int ldrPin = A0;
int ldrValue = 0 ;

void setup() {
  Serial.begin(9600);
  Serial.println("LDR Value :"); Serial.print  (ldrValue);
}

void loop() {
  ldrValue = analogRead(ldrPin); // 0-1023
  Serial.print("Light level: "); Serial.println(ldrValue);
  
  if(ldrValue < 300) Serial.println("It's dark");
  else Serial.println("It's bright");
  
  delay(3000);
}