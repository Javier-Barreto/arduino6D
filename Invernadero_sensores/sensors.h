volatile byte NumPulsos; //variable para la cantidad de pulsos recibidos por el caudalimetro
float calibracion = 4.5;//4.5 o 7.5
byte pulsos = 0;
float flujoAgua;
unsigned int flujoMiliLitros;

class sensors {
  //Otras funciones necesarias
  public:
    void startSensorDS();

  //Funciones para los sensores
  public:
    int HumTierra ( void );
    int Fotosensor( void );
    float TempClima( void );
    float Caudal(unsigned long);
};

/*
 Función que detecta los pulsos dado por el caudal
 */
void ContarPulsos(){ 
  NumPulsos++;  //incrementamos la variable de pulsos
} 

void sensors :: startSensorDS(){
  sensorDS18B20.begin();
}

int sensors :: HumTierra(){
  int SensorValue = analogRead(Pins.PinST);
  return SensorValue;
}

int sensors :: Fotosensor(){
  int FSValue = analogRead(Pins.PinFS);
  return FSValue;
}


float sensors :: TempClima(){
  sensorDS18B20.requestTemperatures();
  float tempC = sensorDS18B20.getTempCByIndex(0);
  return tempC;
}

float sensors :: Caudal(unsigned long previousMillis){
  pulsos = NumPulsos;
  NumPulsos=0;

  //Se calcula los litros por minuto
  flujoAgua =((4000.0 / (millis() - previousMillis)) * pulsos) / calibracion;
  flujoMiliLitros = (flujoAgua / 60)* 4000;
  return flujoAgua;
}
