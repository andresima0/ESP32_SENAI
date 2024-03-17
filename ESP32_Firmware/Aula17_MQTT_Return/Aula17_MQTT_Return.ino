// Bibliotecas
#include <WiFi.h>          // Conexão com WiFi
#include <PubSubClient.h>  // Conexão com Broker MQTT

// Credenciais para acesso ao WiFi e Broker MQTT
const char* ssid = "XXXX";
const char* password = "XXXX";
const char* mqtt_server = "192.168.0.127";

//Nome do cliente que passa parâmetros do WiFi para MQTT e vice_versa
WiFiClient Andre_IoT;
PubSubClient client(Andre_IoT);

//Variáveis para o ESP32 assinar dados publicados pelo Node Red
String my_topic;
String my_payload;

//Variáveis para o ESP32 publicar no NodeRed
int valor;
unsigned long t_valor = 0;
String ip_esp;

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

//Função para o ESP32 receber dados, "assinar"
void callback(char* topic, byte* payload, unsigned int length) {
  String conc_payload;

  for (int i = 0; i < length; i++) {
    conc_payload += ((char)payload[i]);  //O símbolo += adicona caracteres um na frente do outro
  }

  my_topic = topic;
  my_payload = conc_payload;
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Tentando conexão MQTT...");

    if (client.connect("Andre_IoT")) {
      Serial.println("conectado ao MQTT");
      client.subscribe("Topic_Andre");  // Tópico para o ESP32 assinar o Node Red
    } else {
      Serial.print("Falha de conexão");
      Serial.println("Tentando novamente");
      delay(5000);
    }
  }
}

//Inicializa o ESP32 uma única vez
void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  pinMode(2, OUTPUT);   //Indica sucesso na conexão WiFi
  pinMode(19, OUTPUT);  //Pino indicador de carga01
  pinMode(18, OUTPUT);  //Pino indicador de carga02
  pinMode(17, OUTPUT);  //Pino indicador de carga03
  pinMode(16, OUTPUT);  //Pino indicador de carga04
  pinMode(04, OUTPUT);  //Pino indicador de carga03
  pinMode(15, OUTPUT);  //Pino indicador de carga04
}


void led_conexao() {
  if (WiFi.status() == WL_CONNECTED) {
    digitalWrite(2, HIGH);
  } else {
    digitalWrite(2, LOW);
  }
}

void esp_assina() {
  if (my_payload == "A")
    digitalWrite(19, HIGH);
  if (my_payload == "a")
    digitalWrite(19, LOW);
  if (my_payload == "B")
    digitalWrite(18, HIGH);
  if (my_payload == "b")
    digitalWrite(18, LOW);
  if (my_payload == "C")
    digitalWrite(17, HIGH);
  if (my_payload == "c")
    digitalWrite(17, LOW);
  if (my_payload == "D")
    digitalWrite(16, HIGH);
  if (my_payload == "d")
    digitalWrite(16, LOW);
  if (my_payload == "E")
    digitalWrite(4, HIGH);
  if (my_payload == "e")
    digitalWrite(4, LOW);
  if (my_payload == "F")
    digitalWrite(15, HIGH);
  if (my_payload == "f")
    digitalWrite(15, LOW);
}

void esp_publica() {
  valor = random(0, 1000);
  if (millis() - t_valor > 1000) {
    t_valor = millis();
    client.publish("Randomico", String(valor).c_str());  //Tópico para enviar para ESP32. c_str separa
  }
}

void dispositivo() {
  ip_esp = WiFi.localIP().toString();
  client.publish("Topico_Dispositivo", ip_esp.c_str());
  delay(1000);
}

void loop() {
  reconnect();
  client.loop();  //extensão da função callback - manter
  led_conexao();
  esp_assina();
  esp_publica();
  dispositivo();
}