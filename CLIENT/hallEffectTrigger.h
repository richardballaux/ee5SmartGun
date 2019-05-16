#ifndef _HALLEFFECTTRIGGER_H
#define _HALLEFFECTTRIGGER_H

#define ARRAYSIZE 30

void setupTrigger();
int updateTrigger();
int calculate_average();
void move_samples();
void printTriggerInfo(int actualValue, int sendValue);

#endif
