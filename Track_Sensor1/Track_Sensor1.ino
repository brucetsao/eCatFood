/*
 Author: Brucetsao 
 */
#define Trsensor1 30 
#define Trsensor2 31 
#define Trsensor3 32 
#define Trsensor4 33 

int Sensorval1 = 0 ;  // variable to receive data from the Track_Sensor 
int Sensorval2 = 0 ;  // variable to receive data from the Track_Sensor 
int Sensorval3 = 0 ;  // variable to receive data from the Track_Sensor 
int Sensorval4 = 0 ;  // variable to receive data from the Track_Sensor 

void setup()  
{
  // Start serial communication at 57600
  Serial.begin(9600); 
  Serial1.begin(9600); 
  pinMode(Trsensor1, INPUT);
  pinMode(Trsensor2, INPUT);
  pinMode(Trsensor3, INPUT);
  pinMode(Trsensor4, INPUT);
  Serial.println("Start here");

}

void loop()
{
    
   Sensorval1 = digitalRead(Trsensor1) ;
   Sensorval2 = digitalRead(Trsensor2) ;
   Sensorval3 = digitalRead(Trsensor3) ;
   Sensorval4 = digitalRead(Trsensor4) ;
   Serial.print("----------------");
   Serial.print(Sensorval1);
   Serial.print("--");
   Serial.print(Sensorval2);
   Serial.print("--");
   Serial.print(Sensorval3);
   Serial.print("--");
   Serial.print(Sensorval4);
   Serial.println("----------------");

  delay(1000) ;
}


