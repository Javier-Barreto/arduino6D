int numero = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("Ingrese un valor númerico entero: ");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available( )){
    char n = Serial.read();
    numero = String(n).toInt();

    for(int i = 1; i <= numero; i++){
      Serial.print(i);
      delay(1000);
    }
    Serial.println();
  }
}
