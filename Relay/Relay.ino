int relay = 17;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(relay, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(relay, HIGH);
  delay(10000);
  digitalWrite(relay, LOW);
  delay(10000);
}
