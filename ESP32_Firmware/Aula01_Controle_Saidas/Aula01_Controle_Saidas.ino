#define LED1 18
#define LED2 19

void setup(){
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);
}

void loop(){
  digitalWrite(LED1, HIGH);
  delay(1000);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, HIGH);
  delay(1000);
  digitalWrite(LED2, LOW);
}