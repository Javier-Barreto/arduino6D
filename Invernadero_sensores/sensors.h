volatile int NumPulsos; //variable para la cantidad de pulsos recibidos
float factor_conversion=7.11; //para convertir de frecuencia a caudal

class sensors {
  //Otras funciones necesarias
  public:
    void startSensorDS();

  //Funciones para los sensores
  public:
    int HumTierra ( void );
    int Fotosensor( void );
    float TempClima( void );
    float Caudal( void );

  public:
    int ObtenerFrecuecia ( void ); //Función que obtiene la frecuencia de los pulsos
};

/*
 Función que detecta los pulsos dado por el caudal
 */

 
void ContarPulsos(){ 
  NumPulsos++;  //incrementamos la variable de pulsos
} 


int sensors :: ObtenerFrecuecia() 
{
  int frecuencia;
  NumPulsos = 0;   //Ponemos a 0 el número de pulsos
  interrupts();    //Habilitamos las interrupciones
  delay(1000);   //muestra de 1 segundo
  noInterrupts(); //Deshabilitamos  las interrupciones
  frecuencia=NumPulsos; //Hz(pulsos por segundo)
  return frecuencia;
}



void sensors :: startSensorDS(){
  sensorDS18B20.begin();
}

int sensors :: HumTierra(){
  int SensorValue = analogRead(Pins.PinST);
  Serial.println(SensorValue);
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

float sensors :: Caudal(){
  float frecuencia=ObtenerFrecuecia(); //obtenemos la frecuencia de los pulsos en Hz
  float caudal_L_m=frecuencia/factor_conversion; //calculamos el caudal en L/m
  
  return caudal_L_m;
}
