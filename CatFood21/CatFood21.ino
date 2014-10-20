#define Sensorpin A0
#define Sensorlimit 750
#define SensorLedPin 13

#define motor1a 42 
#define motor1b 44 
#define UpperSwitchpin 43
#define LowerSwitchpin 45

int Motor1Direction = 1 ;
int Motor1Working = 0 ;
void initall()
{
  
  Serial.begin(9600);
  Serial.println("program start here ");
  
    pinMode(SensorLedPin,OUTPUT) ;
  
 // init motor pin as output 
   pinMode(motor1a,OUTPUT);
   pinMode(motor1b,OUTPUT);


 // init motor direction Led output 
   pinMode(UpperSwitchpin,INPUT);
   pinMode(LowerSwitchpin,INPUT);

}
 void setup()
 {

  initall();
 }

 void loop()
 {
   if (ReadSensor())
       {
         CoverOpening() ;
       }
       else
       {
         CoverClosing() ;
       }
       
  delay(1000);
  
 }

void CoverOpening()
{
  
   if (!CheckUpper())
     {
       Serial.println("Now open to Upper");
       while (!CheckUpper())
          {
               Serial.println("Opening the Cover");
            Motor1Forward() ;
            
          }
     }
        Motor1Stop() ;  
}


void CoverClosing()
{
  
   if (!CheckLower())
     {
       Serial.println("Now close to Down");
       while (!CheckLower())
          {
               Serial.println("Close the Cover");
            Motor1Backward() ;
            
          }
     }
        Motor1Stop() ;  
}




boolean ReadSensor()
{
  
   int sensorValue = analogRead(Sensorpin);
  // print out the value you read:
  Serial.println(sensorValue);
  if (sensorValue <= Sensorlimit)
      {
          return true ;
      }
     return false ;     
    
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


boolean CheckUpper()
{
  boolean tmp = false ;
  if (digitalRead(UpperSwitchpin) == HIGH)
  {
    tmp = true  ;
  }
  else
  {
    tmp = false  ;
  }
  return (tmp) ;
}  
boolean CheckLower()
{
  boolean tmp = false ;
  if (digitalRead(LowerSwitchpin) == HIGH)
  {
    tmp = true  ;
  }
  else
  {
    tmp = false  ;
  }
  return (tmp) ;
}  

