#define Sensorpin A0
#define Sensorlimit 750
#define SensorLedPin 13

void setup() {
  // initialize serial communication at 9600 bits per second:
  pinMode(SensorLedPin,OUTPUT) ;
  Serial.begin(9600);
}
 
// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(Sensorpin);
  // print out the value you read:
  Serial.println(sensorValue);
  if (sensorValue <= Sensorlimit)
      {
         Serial.println("Cats are coming, Open the Cover"); 
         digitalWrite(SensorLedPin,HIGH);
        delay(300);        // delay in between reads for stability
      }
         digitalWrite(SensorLedPin,LOW);
    delay(100);      
}      
