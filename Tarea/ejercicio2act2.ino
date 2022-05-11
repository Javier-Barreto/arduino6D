int lectura = 0; 
float temperaturaC = 0.0; 

void setup() {
  Serial.begin(9600);   
}

void loop() {
   delay(1000);
    float fahrenheit = (temperaturaC * 9/5) + 32;
    
  lectura = analogRead(0);  

  temperaturaC = (( lectura * (500.0 / 1023.0)/2) );    
  
  Serial.println("Temperatura en grados C: ");   
  Serial.println(temperaturaC);
  Serial.println("Temperatura en grados K: ");  
  Serial.println(temperaturaC + 273.15 );
  Serial.println("Temperatura en grados F: ");  
  Serial.println(fahrenheit);
}
