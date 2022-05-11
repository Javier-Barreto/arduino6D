int lm35 = 0;
float temperatura = 0.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  lm35 = analogRead(A0);
  temperatura = 27.4 + (( lm35 * (500.0 / 1023.0)));
  Serial.println(temperatura);

  delay(500);
}
