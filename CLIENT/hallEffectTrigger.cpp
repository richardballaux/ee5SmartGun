#include "hallEffectTrigger.h"
#include "config.h"


unsigned int sum;
int samples[ARRAYSIZE];

void setupTrigger()
{
  for(int i = 0; i <ARRAYSIZE; i++){
    samples[i] = analogRead(analogTrigger);
  }
}

int updateTrigger()
{

  int value = map(calculate_average(), 338,1024,0,255);
  sendData[0] = value;
  Serial.println("Value trigger: ");
  Serial.println(value);
  move_samples();
  return value;  
}

int calculate_average(){
  sum = 0;
  for(int i = 0; i <(ARRAYSIZE/2); i++){
    sum += samples[i];
  }
  int answer = 2*sum/ARRAYSIZE;
  return answer;
}
void move_samples(){
  for(int i = 0; i < (ARRAYSIZE-1); i++){
    samples[i] = samples[i+1];
  }
  samples[(ARRAYSIZE-1)] = analogRead(analogTrigger);
}
