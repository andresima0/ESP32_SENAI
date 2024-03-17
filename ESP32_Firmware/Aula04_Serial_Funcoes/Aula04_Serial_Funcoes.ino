#define CARGA01 19
#define CARGA02 18
#define CARGA03 17
#define CARGA04 16
#define CARGA05 4
#define CARGA06 15

char DADO;

void setup() {
  Serial.begin(115200);
  pinMode(CARGA01, OUTPUT);
  pinMode(CARGA02, OUTPUT);
  pinMode(CARGA03, OUTPUT);
  pinMode(CARGA04, OUTPUT);
  pinMode(CARGA05, OUTPUT);
  pinMode(CARGA06, OUTPUT);
}

void ligaImpar(){
    digitalWrite(CARGA01, HIGH);
    digitalWrite(CARGA02, LOW);
    digitalWrite(CARGA03, HIGH);
    digitalWrite(CARGA04, LOW);
    digitalWrite(CARGA05, HIGH);
    digitalWrite(CARGA06, LOW);
}

void desligaImpar(){
    digitalWrite(CARGA01, LOW);
    digitalWrite(CARGA02, LOW);
    digitalWrite(CARGA03, LOW);
    digitalWrite(CARGA04, LOW);
    digitalWrite(CARGA05, LOW);
    digitalWrite(CARGA06, LOW);
  }

  void ligaPar(){
    digitalWrite(CARGA01, LOW);
    digitalWrite(CARGA02, HIGH);
    digitalWrite(CARGA03, LOW);
    digitalWrite(CARGA04, HIGH);
    digitalWrite(CARGA05, LOW);
    digitalWrite(CARGA06, HIGH);
  }

void desligaPar(){
  digitalWrite(CARGA01, LOW);
  digitalWrite(CARGA02, LOW);
  digitalWrite(CARGA03, LOW);
  digitalWrite(CARGA04, LOW);
  digitalWrite(CARGA05, LOW);
  digitalWrite(CARGA06, LOW);
  }

void loop() {
  DADO = Serial.read();
  if(DADO == 'A'){
    ligaImpar();
  }
  if(DADO == 'a'){
    desligaImpar();
  }
  if(DADO == 'B'){
    ligaPar();
  }
  if(DADO == 'b'){
    desligaPar();
  }
}
