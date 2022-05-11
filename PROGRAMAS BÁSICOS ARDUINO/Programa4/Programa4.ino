int lm35 = 0;
float temperaturas[500];
float total = 0.0;
float temperaturaC = 0.0;
float promedio = 0.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i<500; i++) {
    delay(100);
    temperaturas[i] = (( analogRead(0) * (500.0 / 1023.0)/2) );
    Serial.println(temperaturas[i]);
  }
  
  for(int i = 0; i < 500; i++) {
    total += temperaturas[i];
  }
  
  promedio = total/500;
  Serial.print("El promedio de ");
  Serial.print(total);
  Serial.print(" es: ");
  Serial.println(promedio);
  delay(5000);
}
