int lm35 = 0; 
float centi = 0.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  centi = (( lm35 * (500.0 / 1023.0)/2));
  float fahrenheit = (centi * 9/5) + 32;

  Serial.println("Temperatura en grados C: ");   
  Serial.println(centi);
  Serial.println("Temperatura en grados K: ");  
  Serial.println(centi + 273.15 );
  Serial.println("Temperatura en grados F: ");  
  Serial.println(fahrenheit);
  
  delay(2000);
}
