
class actuators{
  public:
    void relay( int );

    //LCD (display)
    void lcd_init( void );
    long printLCD( long );
    
    //MircoSD
    void MicroSD_init( void );
    void FileID( void );
    void JSON ( void );
    void JSON_SaveFile( DynamicJsonDocument *);

    //RTC
    uint8_t hora, minuto, segundo, dia, mes, wday;
    uint16_t ano;
    String fecha, tiempo, filename,json_string="" ;
    
    void rtc_init( void );
    void get_time( void );
    void get_format_time( void );
    void get_format_date( void );
};

void actuators::relay(int value){
  if(value==1)
  {
    Serial.println("Encendiendo bomba");
    digitalWrite(Pins.PinRB, LOW);
  } else {
    Serial.println("Apagando bomba");
    digitalWrite(Pins.PinRB, HIGH);
  }
}

void actuators::lcd_init( void ){
  Wire.begin();
  lcd.init();
  lcd.backlight();
}

long actuators::printLCD( long m4s ){
  lcd.setCursor(0,0);
  lcd.print("H: ");
  lcd.print(Sen.HumTierra());
  lcd.setCursor(8,0);
  lcd.print("TC: ");
  lcd.print(Sen.Fotosensor());
  lcd.setCursor(0,1);
  lcd.print("C:");
  lcd.print(Sen.TempClima());
  lcd.setCursor(8,1);
  lcd.print("L:");
  lcd.print(Sen.Caudal(m4s));
}



void actuators :: rtc_init( void ){
  while (! RRTC.begin()) {
    
    Serial.println(F("Hay un error al reconocer el RTC, revise las conexiónes e intente de nuevo"));
    delay(10);
    
  }
  RRTC.adjust(DateTime(2022, 5, 18, 9, 0, 0));
  Serial.println(F("El RTC se ha iniciado correctamente"));
}

void actuators :: get_time( void ){
  DateTime now = RRTC.now();
  ano = now.year();
  mes = now.month();
  dia = now.day();
  hora = now.hour();
  minuto = now.minute();
  segundo = now.second();
}

void actuators :: get_format_date ( void ){
  
  get_time();

  fecha = "";
  
  if ( dia < 10 ) fecha += '0';
  fecha += dia;
  fecha += '/';
  if ( mes < 10 ) fecha += '0';
  fecha += mes;
  fecha += '/';
  fecha += ano;
  
}

void actuators :: get_format_time ( void ){
  get_time();

  tiempo = "";
  
  if ( hora < 10 ) tiempo += '0';
    tiempo += hora;
    tiempo += ':';
  
  if ( minuto < 10 ) tiempo += '0';
    tiempo += minuto;
    tiempo += ':';
    
  if ( segundo < 10 ) tiempo += '0';
    tiempo += segundo;
}



void actuators :: MicroSD_init( void ){
  while (!SD.begin(MICROSD_PIN)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
  }
  Serial.println("card initialized.");
}

void actuators :: FileID( void ){

  filename = '/';

  if ( dia < 10 ) filename += '0';
  filename += dia;
  filename+='-';
  
  if ( mes < 10 ) filename += '0';
  filename += mes;
  filename+='-';
  
  filename += ano;

  filename += EXTENSION;
}

void actuators :: JSON( void ){
  doc["Equipo"] = "1 - Alfa Buena maravilla Onda Dinamita Escuadron Lobo";
  doc["tiempo"] = fecha+" "+tiempo;

  JSON_SaveFile( &doc );
}

void actuators :: JSON_SaveFile( DynamicJsonDocument * doc){
  
  FileID ( );
  json_string = "";
  MicroSD_File = SD.open ( filename, FILE_APPEND );
  if (MicroSD_File) {
    serializeJson(*doc, json_string);
    MicroSD_File.print(json_string);
    MicroSD_File.println(",");
    MicroSD_File.close();
  }

}
