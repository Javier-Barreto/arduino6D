class MQTT {
  public:
    void wifi_init ( void );
    void set_server_MQTT ( void );
    void reconnect_MQTT ( void );
    void publish_MQTT ( void );
};

void MQTT::wifi_init ( void ){
  delay(10);
  WiFi.begin(HOTSPOT, PWD);

  while ( WiFi.status() != WL_CONNECTED ) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi conectado a: " + WiFi.localIP());
}


void MQTT :: set_server_MQTT ( void ){
  client.setServer(MQTT_SERVER, MQTT_PORT);
  Serial.println("Se ha configurando el puerto");
  //client.setCallback(callback);  
}


void MQTT :: reconnect_MQTT ( void) {

  if ( !client.connected() ) {
    while ( !client.connected( ) ) {
      Serial.print("Reconenctando MQTT...");
      
      if ( client.connect ("ESP3266Client") ) {
        
        Serial.println("MQTT conectado");
        
        //client.subscribe("JABM/6D");
        
      } else {
        
        Serial.print( "Falló la conexión, error=" );
        Serial.print(client.state());
        Serial.println(" try again in 5 seconds");
        // Wait 5 seconds before retrying
        delay(5000);
      
      }
    }
  }
  client.loop();
}

void MQTT :: publish_MQTT ( void ){
  client.publish("JABM/6D/E1", json.c_str());  
}
