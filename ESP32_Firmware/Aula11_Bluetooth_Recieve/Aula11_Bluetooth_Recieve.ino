#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;
int valor;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_Andre");
  Serial.println("Aguardando pareamento");
}

void loop() {
  valor = random(0, 100);
  SerialBT.print("Valor = ");
  SerialBT.print(valor);
  SerialBT.println("%");
  delay(1000);
  SerialBT.read();
}
