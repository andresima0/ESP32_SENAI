//Definição de entradas saídas e variáveis
//Saídas
#define LED0 2
#define LED1 19
#define LED2 18
//Variáveis
char DADOS;
int x;

void setup() {
  Serial.begin(115200);
  //Configura os pinos como entradas/saídas
  pinMode(LED0, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void rapido() {
  digitalWrite(LED1, HIGH);
  delay(100);
  digitalWrite(LED1, LOW);
  delay(100);
}

void lento() {
  digitalWrite(LED2, HIGH);
  delay(1000);
  digitalWrite(LED2, LOW);
  delay(1000);
}

void desliga() {
  digitalWrite(LED0, LOW);
  digitalWrite(LED1, LOW);
}

void loop() {
  DADOS = Serial.read();
  if (DADOS == 'A')
    x = 1;
  if (x == 1)
    rapido();

  if (DADOS == 'B')
    x = 2;
  if (x == 2)
    lento();

  if (DADOS == 'C')
    x = 0;
  if (x == 0) {
    desliga();
  }
}