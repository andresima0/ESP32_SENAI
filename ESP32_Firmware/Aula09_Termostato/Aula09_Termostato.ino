#define LED1 19

float valor1;

void setup() {
  Serial.begin(115200);
  pinMode(LED1, OUTPUT);
}

void loop() {
  valor1 = random(0,100);
  Serial.print("Temperatura = ");
  Serial.print(valor1);
  Serial.println("°C");
  delay(500);
  if(valor1 >90)
    digitalWrite(LED1, HIGH);
  else
    digitalWrite(LED1, LOW);
}
