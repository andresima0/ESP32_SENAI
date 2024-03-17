// Definição de entradas, saídas e variáveis
#define LED01 19
#define LED02 18
#define LED03 17
#define LED04 16
#define LED05 4
#define LED06 15

// Variáveis
char DADO;  // Variável que armazena 1 letra
bool X;     // variável que armazena 1 bit (0 ou 1)

void setup() {
  Serial.begin(115200);
  pinMode(LED01, OUTPUT);
  pinMode(LED02, OUTPUT);
  pinMode(LED03, OUTPUT);
  pinMode(LED04, OUTPUT);
  pinMode(LED05, OUTPUT);
  pinMode(LED06, OUTPUT);
}

void comando() {
  // acende LEDs
  digitalWrite(LED01, HIGH);
  delay(100);
  digitalWrite(LED02, HIGH);
  delay(100);
  digitalWrite(LED03, HIGH);
  delay(100);
  digitalWrite(LED04, HIGH);
  delay(100);
  digitalWrite(LED05, HIGH);
  delay(100);
  digitalWrite(LED06, HIGH);
  // apaga LEDs
  digitalWrite(LED01, LOW);
  delay(100);
  digitalWrite(LED02, LOW);
  delay(100);
  digitalWrite(LED03, LOW);
  delay(100);
  digitalWrite(LED04, LOW);
  delay(100);
  digitalWrite(LED05, LOW);
  delay(100);
  digitalWrite(LED06, LOW);
}

void desliga() {
  digitalWrite(LED01, LOW);
  digitalWrite(LED02, LOW);
  digitalWrite(LED03, LOW);
  digitalWrite(LED04, LOW);
  digitalWrite(LED05, LOW);
  digitalWrite(LED06, LOW);
}

void loop() {
  DADO = Serial.read();
  if (DADO == 'A') {
    X = 1;
  }
  if (X == 1) {
    comando();
  }

  if (DADO == 'a') {
    X = 0;
  }
  if (X == 0) {
    desliga();
  }
}
