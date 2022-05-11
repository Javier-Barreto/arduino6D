float pesos = 105.23;
float dolares = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dolares = pesos *20;
  while(!Serial){
    ;
  }

  delay(2000);
  Serial.print(pesos);
  Serial.print(" son ");
  Serial.print(dolares);
  Serial.print(" dolares");
}

void loop() {
  // put your main code here, to run repeatedly:

}
