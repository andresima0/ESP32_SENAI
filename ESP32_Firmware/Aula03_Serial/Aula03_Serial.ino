#define LUZ01 19

char dado;

void setup() {
  Serial.begin(115200);
  pinMode(LUZ01, OUTPUT);
}

void loop() {
  dado = Serial.read();
  if(dado == 'a')
    digitalWrite(LUZ01, HIGH);
  if(dado == 'z')
    digitalWrite(LUZ01, LOW);
}