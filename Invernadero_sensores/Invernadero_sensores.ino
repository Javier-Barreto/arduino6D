#include "invernadero_sensores.h"
invernadero_sensores start;

void setup() {
  Serial.begin(115200);
  start.startConfg();
  Act.lcd_init();
  Sen.startSensorDS();
  Act.MicroSD_init();
  attachInterrupt(digitalPinToInterrupt(Pins.PinC), ContarPulsos, RISING);
  //Act.rtc_init();
}

void loop() {
  // put your main code here, to run repeatedly:
  Tasks.currentMillis = millis();
  Tasks.call_tasks();
}
