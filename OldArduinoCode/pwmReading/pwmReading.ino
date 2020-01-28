//The pulseIn Function
//byte PWM_PIN = 3;
// 
//int pwm_value;
// 
//void setup() {
//  pinMode(PWM_PIN, INPUT);
//  Serial.begin(115200);
//}
// 
//void loop() {
//  pwm_value = pulseIn(PWM_PIN, HIGH);
//  Serial.println(pwm_value);
//}
//External Interrupts
volatile int pwm_value = 0;
volatile int prev_time = 0;
 
void setup() {
  Serial.begin(115200);
  // when pin D2 goes high, call the rising function
  attachInterrupt(0, rising, RISING);
}
 
void loop() { }
 
void rising() {
  attachInterrupt(0, falling, FALLING);
  prev_time = micros();
}
 
void falling() {
  attachInterrupt(0, rising, RISING);
  pwm_value = micros()-prev_time;
  Serial.println(pwm_value);
}

//#include <PinChangeInt.h>
// 
//#define MY_PIN 5 // we could choose any pin
// 
//volatile int pwm_value = 0;
//volatile int prev_time = 0;
//uint8_t latest_interrupted_pin;
// 
//void rising()
//{
//  latest_interrupted_pin=PCintPort::arduinoPin;
//  PCintPort::attachInterrupt(latest_interrupted_pin, &falling, FALLING);
//  prev_time = micros();
//}
// 
//void falling() {
//  latest_interrupted_pin=PCintPort::arduinoPin;
//  PCintPort::attachInterrupt(latest_interrupted_pin, &rising, RISING);
//  pwm_value = micros()-prev_time;
//  Serial.println(state);
//}
// 
//void setup() {
//  pinMode(MY_PIN, INPUT); digitalWrite(MY_PIN, HIGH);
//  Serial.begin(115200);
//  PCintPort::attachInterrupt(MY_PIN, &rising, RISING);
//}
// 
//void loop() { }
