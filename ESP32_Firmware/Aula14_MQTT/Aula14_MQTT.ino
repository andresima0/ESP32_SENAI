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

// Função somente para conexão com WiFi
void setup_wifi() {

  Serial.print("Connectando na rede: ");
  Serial.println(ssid);

  // WiFi.mode(WIFI_STA);
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
  // Loop until we're reconnected
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
  // -------------Publicação MQTT-----------------   
  //            | TÓPICO |       PAYLOAD         |
  client.publish("NUMERO", String(valor).c_str());
  delay(1000);
}

void loop() {
  reconnect();
  conexao();
  randomico();
}
