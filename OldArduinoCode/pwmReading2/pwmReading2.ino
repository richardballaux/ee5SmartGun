
volatile long pwm;
volatile boolean done;
unsigned long start;

int diff;
int out1;
int out2;
int percentage;
#define triggerPin 13

unsigned long currentMillis;

long previousMillis = 0;    // set up timers
long interval = 20;        // time constant for timers

void setup() {
  pinMode(triggerPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(triggerPin), timeit, CHANGE);


  Serial.begin(115200);

}


void timeit() {
    if (digitalRead(triggerPin) == HIGH) {
      start = micros();
    }
    else {
      pwm = micros() - start;
      done = true;
    }
  }
void loop() {

  currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {  //start timed event
      previousMillis = currentMillis;
      percentage = map(pwm,0,10000,0,256);
      Serial.print (pwm);
      Serial.print (" , ");
      Serial.println(percentage);
   
      if (!done)
          return;                     
          done = false;  

  } // end of timed event

}
