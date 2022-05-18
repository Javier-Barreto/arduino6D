const char* HOTSPOT_WIFI = "HOTSPOT";
const char* HOTSPOT_PWD = "123456789";  
const char* MQTT_SERVER = "test.mosquitto.org";
#define MQTT_PORT 1883
#define TOPIC "20164773"

class MQTT {
  public:
    void publish_MQTT ( void );
    void reconnect_MQTT ( void );
    void setup_WiFi ( void ); 
    void set_MQTT_server ( void );
};

void MQTT :: set_MQTT_server ( void ) {
  client.setServer ( MQTT_SERVER, MQTT_PORT );
}

void MQTT :: publish_MQTT ( void ) {
  Serial.println ( "Publicando información" );
  client.publish( TOPIC, Act.json_string.c_str());
}

void MQTT :: reconnect_MQTT ( void ) {
  if ( ! client.connected ( ) ) {

    while ( ! client.connected ( ) ) {
      
    Serial.print ( "Conectado nuevamente al servidor" );

    if ( client.connect ( "E1_6D" ) ) {
      
      Serial.println ( "Cliente conectado" );
      
      client.subscribe("E1_6D");
      
    } else {
        Serial.print("failed, rc=");
        Serial.print(client.state());
        Serial.println(" try again in 5 seconds");
        // Wait 5 seconds before retrying
        delay(5000);
      }
    }
  }
  client.loop();
}



void MQTT :: setup_WiFi ( void ) {
  Serial.println ( "Configurando WiFi: " );
  WiFi.begin ( HOTSPOT_WIFI, HOTSPOT_PWD );
  
  while ( WiFi.status ( ) != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }
  
  Serial.println("Se configuró el wifi correctamente");//Salto de linea
}


void callback(char* topic, byte* message, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String messageTemp;
  
  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();
}
