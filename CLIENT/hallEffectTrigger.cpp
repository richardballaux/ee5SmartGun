#include "hallEffectTrigger.h"
#include "config.h"


unsigned int sum;
int samples[ARRAYSIZE];
int startValue;

void setupTrigger()
{
  for(int i = 0; i <ARRAYSIZE; i++){
    samples[i] = analogRead(analogTrigger);
  }
  startValue = calculate_average();
}

int updateTrigger()
{
  int value = map(calculate_average(), 510,startValue,255,0);
  //Serial.println("Value trigger: ");
  //Serial.println(value);
  //Serial.println(calculate_average());
  move_samples();
  if (value > 255) value = 255;
  else if (value < 0) value = 0;
  Serial.println("Actual value: ");
  Serial.println(value);
  sendData[0] = value;
  return value;  
}

int calculate_average(){
  sum = 0;
  for(int i = 0; i <(ARRAYSIZE); i++){
    sum += samples[i];
  }
  int answer = sum/ARRAYSIZE;
  return answer;
}

void move_samples(){
  for(int i = 0; i < (ARRAYSIZE-1); i++){
    samples[i] = samples[i+1];
  }
  samples[(ARRAYSIZE-1)] = analogRead(analogTrigger);
}
