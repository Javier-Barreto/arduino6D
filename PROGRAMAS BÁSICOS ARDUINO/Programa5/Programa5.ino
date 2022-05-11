String valor;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  delay(1000);
  digitalWrite(LED_BUILTIN, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    valor = Serial.readString();
    
    if(valor=="prender\n"){
      Serial.println("¡Led encendido!");  
      digitalWrite(LED_BUILTIN, LOW);
    }
    if(valor=="apagar\n"){
      Serial.println("¡Led apagado!");
      digitalWrite(LED_BUILTIN, HIGH);
    }
  }
}
