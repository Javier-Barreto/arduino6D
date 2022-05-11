#include <WiFi.h>
WiFiClient espClient;

#include <PubSubClient.h>
PubSubClient client(espClient);

#define HOTSPOT "HOTSPOT"
#define PWD "123456789"
#define MQTT_SERVER "test.mosquitto.org"
#define MQTT_PORT 1883
String json = "Yavin IV";

#include "MQTT_client.h"
MQTT mqtt;
