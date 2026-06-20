int analogPin = A0;
int digitalPin = 7;
int analogVal = 0;
int digitalVal = 0;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(digitalPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogVal = analogRead(analogPin);
  digitalVal = digitalRead(digitalPin);

  Serial.print("Volume :"); Serial.print(analogVal);
  if(digitalVal== HIGH) Serial.println("Clap detected !");
  else Serial.println();

  delay(1000);

}
