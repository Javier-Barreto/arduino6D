#include "invernadero_sensores.h"
invernadero_sensores start;

void setup() {
  Serial.begin(115200);
  start.startConfg(); // Inicializa los pines
  Act.lcd_init(); //Inicializa el rejol
  Sen.startSensorDS(); 
  Act.MicroSD_init();
  attachInterrupt(digitalPinToInterrupt(Pins.PinC), ContarPulsos, RISING); //Define el pin con interrupciones para el caudal
  Act.rtc_init();
  mqtt.setup_WiFi ( );
  mqtt.set_MQTT_server ( );
  client.setCallback(callback);
}

void loop() {
  // put your main code here, to run repeatedly:
  Tasks.currentMillis = millis();
  Tasks.call_tasks();
}
