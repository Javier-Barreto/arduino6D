//ARDUINO JSON
#include <ArduinoJson.h>
DynamicJsonDocument doc(1024);

// Micro SD adapter
#include "FS.h"
#include "SD.h"
#include "SPI.h"

//DISPLAY LCD
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);//0x27

//RELOJ
#include "RTClib.h"
RTC_DS1307 rtc;

//PINES
#include "pines.h"
pines Pins;


//SENSORES
#include <OneWire.h>
#include <DallasTemperature.h>
OneWire tempClima(Pins.PinSD);//Sensor temperatura "clima"
DallasTemperature sensorDS18B20(&tempClima);
#include "sensors.h"
sensors Sen;


//ACTUADORES
#include "actuators.h"
actuators Act;


//TASKS
#include "tasks.h"
tasks Tasks;

class invernadero_sensores {
  public:
    void startConfg();
};


void invernadero_sensores::startConfg(){
  //Pins de entrada de valores de sensores
  pinMode(Pins.PinST, INPUT);//,Sensor temperatura tierra
  pinMode(Pins.PinFS, INPUT); //Fotosensor
  pinMode(Pins.PinC, INPUT); //Caudal
  
  //Pins de actuadores
  pinMode(Pins.PinRB, OUTPUT);//Relay bomba
}
