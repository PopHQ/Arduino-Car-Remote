#include <WiFi.h>

const char* ssid = "Adrian's Note20";       // Nombre de la red WiFi que creará el ESP32
const char* password = "zgbz0459";  // Contraseña de la red WiFi

void setup() {
  Serial.begin(115200);

  // Configura el ESP32 como punto de acceso
  WiFi.softAP(ssid, password);
  
  Serial.println("Punto de acceso configurado");
  Serial.print("SSID: ");
  Serial.println(ssid);
  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP());
  
  // Configura los eventos de WiFi para detectar conexiones y desconexiones
  WiFi.onEvent(WiFiEvent);
}

void loop() {
  // Aquí puedes agregar código para enviar señales al ESP8266
  // Por ejemplo, mediante HTTP o cualquier otro protocolo de red

  delay(1000); // Espera un segundo antes de repetir el ciclo
}

void WiFiEvent(WiFiEvent_t event) {
  switch (event) {
    case ARDUINO_EVENT_WIFI_AP_START:
      Serial.println("Punto de acceso iniciado");
      break;
    case ARDUINO_EVENT_WIFI_AP_STOP:
      Serial.println("Punto de acceso detenido");
      break;
    case ARDUINO_EVENT_WIFI_AP_STACONNECTED:
      Serial.println("Dispositivo conectado al AP");
      break;
    case ARDUINO_EVENT_WIFI_AP_STADISCONNECTED:
      Serial.println("Dispositivo desconectado del AP");
      break;
    default:
      break;
  }
}