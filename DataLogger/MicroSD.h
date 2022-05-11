class MicroSD{
  public:
    String filename = "", json_string = "";
    
  public:
    void MicroSD_init( void );
    void FileID( void );
    void JSON ( void );
    void JSON_SaveFile( DynamicJsonDocument *);
};

void MicroSD :: MicroSD_init( void ){
  RRTC.get_time();
  while (!SD.begin(MICROSD_PIN)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
  }
  Serial.println("card initialized.");
}

void MicroSD :: FileID( void ){

  filename = '/';

  if ( RRTC.dia < 10 ) filename += '0';
  filename += RRTC.dia;
  filename+='-';
  
  if ( RRTC.mes < 10 ) filename += '0';
  filename += RRTC.mes;
  filename+='-';
  
  filename += RRTC.ano;

  filename += EXTENSION;
}

void MicroSD :: JSON( void ){
  DynamicJsonDocument doc(1024);
  doc["temperatura"] = 23;
  doc["humedad"] = 60;
  doc["motor"] = true;

  RRTC.get_format_date( );
  RRTC.get_format_time( );
  
  doc["fecha"] = RRTC.fecha.c_str();
  doc["fecha"] = RRTC.tiempo.c_str();

  JSON_SaveFile( &doc );
}

void MicroSD :: JSON_SaveFile( DynamicJsonDocument * doc){
  
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
