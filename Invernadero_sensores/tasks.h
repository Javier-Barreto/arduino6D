class tasks {
  //variables
  public:
    unsigned long currentMillis;
    unsigned long m5s = 0, m4s = 0;
    
  //funciones
  public:
    void call_tasks();
    void _5s ();//Tareas que se ejecutaran cada 5 segundos
    void _4s ();//Tareas que se ejecutaran cada 4 segundos
};


void tasks :: call_tasks(){
  if(currentMillis-m4s>=4000){
    m4s = currentMillis;
    tasks::_4s();
  }
  
  if(currentMillis-m5s>=5000){
    m5s = currentMillis;
    tasks::_5s();
  }
}



void tasks :: _5s(){
  mqtt.reconnect_MQTT ( );
  
  if(Sen.HumTierra()>700){
    Serial.println("Comenzando riego");
    Act.relay(1);
  } else {
    Serial.println("Deteniendo riego");
    Act.relay(0);
  }
 
  doc.clear();
  doc["HumedadTierra"] = Sen.HumTierra();
  doc["FotoSensor"] = Sen.Fotosensor();
  doc["Litros/minutos"] = Sen.Caudal();
  doc["Sensor de agua"] = Sen.TempClima();
  doc["Equipo"] = "1 - Alfa Buena maravilla Onda Dinamita Escuadron Lobo";
  doc["tiempo"] = Act.fecha+" "+Act.tiempo;
  if (Act.BombState==true)
    doc["BombaAgua"] = "Se activo la bomba el " + Act.fecha+" a las "+Act.tiempo;
    
  serializeJsonPretty(doc, Serial);

    
  Act.printLCD();

  mqtt.publish_MQTT ( );
  
  Act.JSON();
}


void tasks :: _4s(){
  Act.get_format_time();
  Act.get_format_date();
}
