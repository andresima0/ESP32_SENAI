#include "BluetoothSerial.h"
#define LED1 19

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;
int dado;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_Andre");
  Serial.println("Aguardando pareamento");
  pinMode(LED1, OUTPUT);
}

void loop() {
  dado = SerialBT.read();
  if (dado == '1') {
    digitalWrite(LED1, HIGH);
    SerialBT.println("LED ligado");
  }
  if (dado == '0') {
    digitalWrite(LED1, LOW);
    SerialBT.println("LED desligado");
  }
}
