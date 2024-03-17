#include "BluetoothSerial.h"

String device_name = "ESP32_Andre";  //Nome do dispositivo
int valor;                           //Variável para enviar número randômico
char dado;                           //Variável pra recebimeno de dados
unsigned long tempoAnterior = 0;     //Variável para função Millis


//Verificação de conexão Bletooth
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run make menuconfig to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif

BluetoothSerial SerialBT;  //Instância para gerenciar informações trafegadas

void setup() {
  Serial.begin(115200);
  SerialBT.begin(device_name);
  Serial.printf("Agora é deve parear");
  pinMode(2, OUTPUT);
  pinMode(19, OUTPUT);
}

//Função para estabelecer conexão via Bluettoth
void conexao() {
  if (SerialBT.connected())
    digitalWrite(2, HIGH);  //liga LED do ESP32 se conexão estabelecida
  else
    digitalWrite(2, LOW);  //desliga LED do ESP32 se conexão estabelecida
}

//Função para enviar números randômicos para aplicativo
void randomico() {
  valor = random(0, 1000);
  if ((millis() - tempoAnterior) > 1000) {
    tempoAnterior = millis();
    SerialBT.println(valor);
  }
}

//Função para receber comandos do aplicativo e realizar ações
void controle() {
  dado = SerialBT.read();
  if (dado == 'A')
    digitalWrite(19, HIGH);
  if (dado == 'a')
    digitalWrite(19, LOW);
}

void loop() {
  conexao();
  randomico();
  controle();
}