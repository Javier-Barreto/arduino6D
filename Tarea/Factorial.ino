void setup (){
  Serial.begin(115200);
}

void loop(){
  if (Serial.available() > 0){

     int numero = Serial.parseInt ();
     if (numero !=0){
      Serial.print("El numero que introdujiste fue: ");
      Serial.println(numero);
      for(int i = 1 ; i <= numero; i++){
        Serial.println(i);
      }
     }
     
  }
}
