#define pin_1 4
#define pin_2 3
#define safety 8
#define semi 9
#define autom 10


int counter = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin_1,INPUT);
  pinMode(pin_2,INPUT);
  pinMode(5,OUTPUT);
  pinMode(safety, OUTPUT);
  pinMode(semi, OUTPUT);
  pinMode(autom, OUTPUT);
  digitalWrite(5,1);
  digitalWrite(semi,LOW);
  digitalWrite(safety,HIGH);
  digitalWrite(autom,LOW);
  attachInterrupt(digitalPinToInterrupt(pin_2), count, CHANGE);
  Serial.begin(9600);
 
}

void loop() {
  // put your main code here, to run repeatedly:
  if(counter <= -4){
    digitalWrite(semi,HIGH);
    digitalWrite(safety,LOW);
    digitalWrite(autom,LOW);
  }
  if(-1 <= counter && counter <= 1){
    digitalWrite(semi,LOW);
    digitalWrite(safety,HIGH);
    digitalWrite(autom,LOW);
  }
  if(counter >= 4){
    digitalWrite(semi,LOW);
    digitalWrite(safety,LOW);
    digitalWrite(autom,HIGH);
  }
}
void count(){
  if(digitalRead(pin_1) != digitalRead(pin_2)){
    counter++;
  }
  else{
    counter--;
  }
  Serial.print("position = ");
  Serial.println(counter);
}
