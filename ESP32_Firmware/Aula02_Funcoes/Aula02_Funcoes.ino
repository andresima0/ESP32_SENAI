#define LED1 19
#define LED2 18

int i=0;
int j=0;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void rapido(){
  digitalWrite(LED1, HIGH);
  delay(100);
  digitalWrite(LED1, LOW);
  delay(100);
}

void lento(){
  digitalWrite(LED2, HIGH);
  delay(1000);
  digitalWrite(LED2, LOW);
  delay(1000);
}

void loop() {
  for(i=0; i<3; i++){
      rapido();
    }
  for(j=0; j<3; j++){
    lento();
  }
}
