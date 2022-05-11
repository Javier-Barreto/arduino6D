int lectura = 0;
float myArray[500];
int temperatura;
float suma = 0;
float temperaturaC = 0.0;
void setup() {
  //Iniciamos la comunicación serial
  Serial.begin(9600);
  delay(1000);
}
void loop() {
   delay(100);
   
  for(int i = 0; i<500; i++) {
    delay(100);
    myArray[i] = (( analogRead(0) * (500.0 / 1023.0)/2) );
    Serial.println(myArray[i]);
  }
  suma = 0;
  for(int i = 0; i<500; i++) {
    suma += myArray[i];
  }
  float promedio = suma/500;
  Serial.print("Suma: ");
  Serial.println(suma);
  Serial.print("Promedio: ");
  Serial.println(promedio);
}
