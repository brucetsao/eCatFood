#define motor1a 42 
#define motor1b 44 
#define UpperSwitchpin 43
#define LowerSwitchpin 45

int Motor1Direction = 1 ;
int Motor1Working = 0 ;
void initall()
{
 // init motor pin as output 
   pinMode(motor1a,OUTPUT);
   pinMode(motor1b,OUTPUT);


 // init motor direction Led output 
   pinMode(UpperSwitchpin,INPUT);
   pinMode(LowerSwitchpin,INPUT);

}
 void setup()
 {
   boolean chkflag ; 
  initall();
   //init serial for debug
Serial.begin(9600);
Serial.println("program start here ");
      if (Motor1Direction == 1 )
          {
             if (checkUpper())
                   Motor1Direction = 2 ;
          }
          else
          {
             if (checkLower())
                   Motor1Direction = 1 ;
          }

 }

 void loop()
 {
    if (Motor1Working == 0)
        {
            if (Motor1Direction == 1 )
                {
                  Motor1Working = 1 ;
                  Motor1Forward() ;
                }
                else
                {
                  Motor1Working = 1 ;                  
                  Motor1Backward() ;
                }
        }
  
  
    if (Motor1Working == 1)
        {
            if (Motor1Direction == 1 )
                {
                  if (checkUpper())
                      {
                         Motor1Stop() ;
                        Motor1Working = 0 ;
                        Motor1Direction = 2;
                        delay(2000);
                      }
                }
                else
                {
                  if (checkLower())
                      {
                         Motor1Stop() ;
                        Motor1Working = 0 ;
                        Motor1Direction = 1;
                        delay(2000);
                      }
 
                }
        }
  
        
  delay(80);
  
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


boolean checkUpper()
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
boolean checkLower()
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

