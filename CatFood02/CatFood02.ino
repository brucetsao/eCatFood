#define motor1a 42 
#define motor1b 44 

int Motor1Direction = 1 ;
int Motor1Working = 0 ;
void initall()
{
 // init motor pin as output 
   pinMode(motor1a,OUTPUT);
   pinMode(motor1b,OUTPUT);

}
 void setup()
 {
   boolean chkflag ; 
  initall();
   //init serial for debug
Serial.begin(9600);
Serial.println("program start here ");


 }

 void loop()
 {
        Motor1Forward() ;
        delay(500);
        Motor1Backward() ;
        delay(500);
           Motor1Stop() ;
            delay(5000);

  
 }

 void Motor1Forward()
 {
   digitalWrite(motor1a,HIGH);
   digitalWrite(motor1b,LOW);
 }
 void Motor1Backward()
 {
   digitalWrite(motor1a,LOW );
   digitalWrite(motor1b,HIGH);
 }
 void Motor1Stop()
 {
   digitalWrite(motor1a,LOW );
   digitalWrite(motor1b,LOW);
 }


