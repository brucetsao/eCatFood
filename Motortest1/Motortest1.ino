const int motor1a = 7;
const int motor2a = 6;
const int motor3a = 5;
const int motor4a = 4;


 void setup()
 {
   pinMode(motor1a,OUTPUT);
   pinMode(motor2a,OUTPUT);
   pinMode(motor3a,OUTPUT);
   pinMode(motor4a,OUTPUT);

 }

 void loop()
 {
  digitalWrite(motor1a,HIGH);
   digitalWrite(motor2a,LOW);
   digitalWrite(motor3a,HIGH);
   digitalWrite(motor4a,LOW);
   delay(3000);
   digitalWrite(motor1a,LOW);
   digitalWrite(motor2a,HIGH);
   digitalWrite(motor3a,LOW);
   digitalWrite(motor4a,HIGH);
   delay(3000);
 }


