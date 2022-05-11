String myString;

void setup() {
  // put your setup code here, to run once:
  pinMode (LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  delay(1000);
  digitalWrite(LED_BUILTIN, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    myString = Serial.readString();
    Serial.print(myString);
    Serial.println(myString.length());
    if(myString == "apagar\n"){
      Serial.println("ON");
      digitalWrite(LED_BUILTIN,LOW);
    }
    if(myString == "prender\n"){
      Serial.println("OFF");
      digitalWrite(LED_BUILTIN, HIGH);
    }
  }

}
