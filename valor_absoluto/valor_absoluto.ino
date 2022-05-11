#include <stdio.h>
int a=-3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(1000);
  Serial.print("El valor absoluto de ");
  Serial.print(a);
  Serial.print(" es: ");

  if(a>1)
    Serial.print(a);
  else
  {
    a=a*(-1);
    Serial.print(a);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
