// Definição de entradas, saídas e variáveis
//Saídas
#define LED01 19
#define LED02 18

//Entradas
#define BTN01 14
#define BTN02 13

//Variáveis e Falgs
bool FLAG01;
bool FLAG02;

//----------------------------------------------------------------//
// Código que roda somente uma única vez na inicialização
void setup() {
  Serial.begin(115200);    // Habilita a comunicação serial
  pinMode(LED01, OUTPUT);  //Configura o LED01 como saída
  pinMode(LED02, OUTPUT);  //Configura o LED02 como saída
  pinMode(BTN01, INPUT);   //Configura o botão BTN01 como entrada
  pinMode(BTN02, INPUT);   //Configura o botão BTN02 como entrada
}

// Código que roda continuamente
void loop() {
  if ((digitalRead(BTN01) == LOW) && (FLAG01 == 0)) {
    FLAG01 = 1;
    digitalWrite(LED01, HIGH);
    Serial.println("LED 01 ligado");
    delay(100);
  }

  if ((digitalRead(BTN01) == HIGH) && (FLAG01 == 1)) {
    FLAG01 = 0;
    digitalWrite(LED01, LOW);
    Serial.println("LED 01 desligado");
    delay(100);
  }

  if ((digitalRead(BTN02) == LOW) && (FLAG02 == 0)) {
    FLAG02 = 1;
    digitalWrite(LED02, HIGH);
    Serial.println("LED 02 ligado");
    delay(100);
  }

  if ((digitalRead(BTN02) == HIGH) && (FLAG02 == 1)) {
    FLAG02 = 0;
    digitalWrite(LED02, LOW);
    Serial.println("LED 02 desligado");
    delay(100);
  } 
}
