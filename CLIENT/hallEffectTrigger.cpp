#include "hallEffectTrigger.h"
#include "config.h"

unsigned int sum;
int samples[ARRAYSIZE];
int startValue = 0;
int endValue = 5000;
#ifdef DEBUGTRIGGER
int counterDebug;
#endif

void setupTrigger()
{
  for(int i = 0; i <ARRAYSIZE; i++){
    samples[i] = analogRead(analogTrigger);
  }
  startValue = calculate_average();
  #ifdef DEBUGTRIGGER
  Serial.println("Calibration value is ");
  Serial.println(startValue);
  #endif
}

int updateTrigger()
{
  int average = calculate_average();
  //AI
  if (average < endValue)   endValue = average;
  if (average > startValue) startValue = average;
  
  int value = map(average, endValue,startValue,255,0);
  
  move_samples();
  if (value > 255) value = 255;
  else if (value < 0) value = 0;
  sendData[0] = value;

  #ifdef DEBUGTRIGGER
  printTriggerInfo(average, value);
  #endif
  
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
#ifdef DEBUGTRIGGER
void printTriggerInfo(int actualValue, int sendValue)
{
  counterDebug++;
  if (counterDebug > 100){
    Serial.print("Actual Value trigger: ");
    Serial.println(actualValue);
    Serial.print("Startvalue is ");
    Serial.println(startValue);
    Serial.print("Endvalue is ");
    Serial.println(endValue);
    Serial.print("Value sent is ");
    Serial.println(sendValue);
    counterDebug = 0;
  }  
}
#endif
