
#define UpperSwitchpin 43
#define LowerSwitchpin 45
void initall()
{

  // init motor direction Led output 
  pinMode(UpperSwitchpin,INPUT);
  pinMode(LowerSwitchpin,INPUT);

}
void setup()
{
  initall();
  //init serial for debug
  Serial.begin(9600);
  Serial.println("program start here ");
}

void loop()
{
  if (CheckUpper())
  {
    Serial.println("Upper Switch is Shorted");
  }
  if (CheckLower())
  {
    Serial.println("Lower Switch is Shorted");
  }


  delay(80);

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


