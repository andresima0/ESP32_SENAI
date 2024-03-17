// Bibliotecas
#include <WiFi.h>          // Conexão com WiFi
#include <PubSubClient.h>  // Conexão com Broker

// Credenciais para acesso ao WiFi e Broker MQTT
const char* ssid = "XXXX";
const char* password = "XXXX";
const char* mqtt_server = "192.168.0.127";

// Passa parâmetros do WiFi para o MQTT e vice-versa
WiFiClient Andre_IoT;
PubSubClient client(Andre_IoT);

//Variáveis para o ESP32 publicar no Broker
int valor;
bool flag01;
bool flag02;
bool flag03;
bool flag04;
unsigned long tempoAnterior = 0;

// Função somente para conexão com WiFi
void setup_wifi() {

  Serial.print("Connectando na rede: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi connectado");
  Serial.print("Endereco IP: ");
  Serial.println(WiFi.localIP());
  Serial.print("Endereco MAC: ");
  Serial.println(WiFi.macAddress());
}

// Função para conexão com MQTT
void reconnect() {
  while (!client.connected()) {
    Serial.println("Tentando conexão com MQTT...");

    if (client.connect("Andre_IoT")) {
      Serial.println("Andre_IoT conectado ao Broker.");
    } else {
      Serial.println("Falha de conexão. Tentando reconectar.");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  pinMode(2, OUTPUT);
  pinMode(26, INPUT);
  pinMode(27, INPUT);
  pinMode(13, INPUT);
  pinMode(14, INPUT);
}

void conexao() {
  if (WiFi.status() == WL_CONNECTED) {
    digitalWrite(2, HIGH);
  } else {
    digitalWrite(2, LOW);
  }
}

void randomico() {
  valor = random(0, 100);
  if ((millis() - tempoAnterior) > 1000) {
    tempoAnterior = millis();
    client.publish("NUMERO", String(valor).c_str());
  }
}

void digital() {

  if (digitalRead(26) == LOW && flag01 == 0) {
    client.publish("DIGITAL01", String("Ativado1").c_str());
    flag01 = 1;
  }
  if (digitalRead(26) == HIGH && flag01 == 1) {
    client.publish("DIGITAL01", String("Desativado1").c_str());
    flag01 = 0;
  }

  if (digitalRead(27) == LOW && flag02 == 0) {
    client.publish("DIGITAL02", String("Ativado2").c_str());
    flag02 = 1;
  }
  if (digitalRead(27) == HIGH && flag02 == 1) {
    client.publish("DIGITAL02", String("Desativado2").c_str());
    flag02 = 0;
  }
  if (digitalRead(13) == LOW && flag03 == 0) {
    client.publish("DIGITAL03", String("Ativado3").c_str());
    flag03 = 1;
  }
  if (digitalRead(13) == HIGH && flag03 == 1) {
    client.publish("DIGITAL03", String("Desativado3").c_str());
    flag03 = 0;
  }

  if (digitalRead(14) == LOW && flag04 == 0) {
    client.publish("DIGITAL04", String("Ativado4").c_str());
    flag04 = 1;
  }
  if (digitalRead(14) == HIGH && flag04 == 1) {
    client.publish("DIGITAL04", String("Desativado4").c_str());
    flag04 = 0;
  }
}

void loop() {
  reconnect();
  conexao();
  randomico();
  digital();
}