#define LED1 19

int valor1;
int valor2;
int dif;

void setup() {
  Serial.begin(115200);
  pinMode(LED1, OUTPUT);
}

void loop() {
  valor1 = random(0, 100);
  valor2 = random(0, 100);
  dif = (valor1 - valor2);
  Serial.print("Temperatura 1 = ");
  Serial.print(valor1);
  Serial.println("°C");
  Serial.print("Temperatura 2 = ");
  Serial.print(valor2);
  Serial.println("°C");

  if (dif > 10) {
    digitalWrite(LED1, HIGH);
    Serial.println("Bomba ligada");
    Serial.print("Diferencial: ");
    Serial.println(dif);
  } 
  else {
    digitalWrite(LED1, LOW);
    Serial.println("Bomba desligada");
    delay(2000);
  }
}