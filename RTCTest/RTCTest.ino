#include <Wire.h>
#include <ErriezDS1307.h>

// Create RTC object
ErriezDS1307 RTC;


void setup()
{
  Wire.begin();
  Wire.setClock(100000);
  delay(500);
  
  Serial.begin(115200);
  while (!Serial) {
    ;
  }
  Serial.println(F("\nInicia programa para configurar hora y fecha"));
  
  while (!RTC.begin()) {
    Serial.println(F("RTC not found"));
    delay(3000);
  }
  
if (!RTC.setDateTime(10, 10, 00,  25, 4, 2022, 0)) {
    Serial.println(F("Set date/time failed"));
  } else {
    Serial.println(F("Hora y fecha configurada"));
  }
}

void loop() {
  // put your main code here, to run repeatedly:
    uint8_t hora, minuto, segundo, dia, mes, wday;
    uint16_t ano;

  if (!RTC.getDateTime(&hora, &minuto, &segundo, &dia, &mes, &ano, &wday)) {
    Serial.println(F("Error al leer la fecha y la hora"));
    return;
  } else {
    Serial.println(F("Fecha: "));
    Serial.print( dia );
    Serial.print( '/' );
    Serial.print( mes );
    Serial.print( '/' );
    Serial.print( ano );
    Serial.println(" SIUUUUUUUUUUUUUUUUUUUUU");
    Serial.println(F("Hora: "));
    Serial.print(hora);
    Serial.print( ':' );
    Serial.print( minuto );
    Serial.print( ':' );
    Serial.print( segundo );
  }

  delay(1000);
}
