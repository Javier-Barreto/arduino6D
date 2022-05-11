JsonArray data = doc.createNestedArray("data");

int valorht = 0;
int valorfs = 0;
float valortc = 0.0;
float valorcd = 0;

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
  valorht = Sen.HumTierra();
  //Act.read_time();
  if(valorht>700){
    Serial.println("Comenzando riego");
    Act.relay(1);
  } else {
    Serial.println("Deteniendo riego");
    Act.relay(0);
  }

  Act.printLCD(m4s);
  data.clear();
  doc["time"] = 123123123;
  doc["HumedadTierra"] = valorht;
  doc["FotoSensor"] = valorfs;
  doc["Litros/minutos"] = valorcd;
  serializeJsonPretty(doc, Serial);

  //Act.writeToMicroSD("/hello.txt", "{time: 312, hum: 123}");
}


void tasks :: _4s(){;
  valorfs = Sen.Fotosensor();
  valortc = Sen.TempClima();
  valorcd = Sen.Caudal(m4s);
  Serial.println(Act.hora);
}
