#define ANALOG A0
#define ARRAYSIZE 40
unsigned int sum;
int samples[ARRAYSIZE];
int average;
void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i <ARRAYSIZE; i++){
    samples[i] = analogRead(ANALOG);
  }
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  average = map(calculate_average(), 338,1024,0,255);
  Serial.println(average);
  move_samples();
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
  samples[(ARRAYSIZE-1)] = analogRead(ANALOG);
}
