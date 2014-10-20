//本程式採用arduino-1.0.1撰寫完成
//請編譯時，採用arduino-1.0.1編譯
//腳位定義
#define LedPin13    13                 //Led指示燈
#define PIRPin      3                 //PIR腳位
//旗標參數
struct
{
    //時間旗標
    volatile unsigned Int_T1mSec:1;
    unsigned T1mSec:1;                 //1mSec計時旗標
    unsigned T10mSec:1;                //10mSec計時旗標
    unsigned T100mSec:1;               //100mSec計時旗標
    unsigned T1Sec:1;                  //1Sec計時旗標
    //UART旗標
    unsigned RevReady:1;              //RS232準備接收資料封包旗標(表檢查到啟始位元0xAA後，開始接收資料封包)
    unsigned RevOK:1;                 //RS232封包接收完成旗標
    unsigned CheckSumOK:1;            //RS232 檢查碼正確旗標
    //按鍵旗標
}Flags;
unsigned char  LED;                    //Pin13 LED腳位變化參數
//時間參數
unsigned long T1uSec;
unsigned char T1mSec,
              T10mSec,
              T100mSec,
              T1Sec;
int PirState;              //IR狀態
unsigned int PIRCounter = 0;
void LedSub()
{
  digitalWrite(LedPin13,LED);
}
//***************************
//******* MCU腳位設定 *******
//***************************
void setup()
{
  pinMode(PIRPin,INPUT);                            //設定紅外線為輸入腳位
  pinMode(LedPin13,OUTPUT);                         //設定蜂鳴器腳位
}
//***************************
//******* Timer計時器 *******
//***************************
void Timer()
{
  millis();
  T1mSec++;
  //*** 10mSec計時 ****
  if(T1mSec >= 10)
  {
    T1mSec = 0;
    T10mSec++;
    Flags.T10mSec = 1;
  }
  //*** 100mSec計時 ***
  if(T10mSec >= 10)
  {
    T10mSec = 0;
    T100mSec++;
    Flags.T100mSec = 1;
  }
  //**** 1Sec計時 *****
  if(T100mSec >= 10)
  {
    T100mSec = 0;
    Flags.T1Sec = 1;
  }
}
//***************************
//******* Main Loop *********
//***************************
void loop()
{
  Timer();
  LedSub();
  PirState = digitalRead(PIRPin);               //取得紅外線腳位狀態
  if(PirState == LOW)                           //若紅外線腳位為LOW則
  {
	PIRCounter++;
	if(PIRCounter >= 1000)		        //1Sec
	{
		LED = 1;		        //有人經過
	}
  }
  else if(PirState == HIGH)
  {
	PIRCounter = 0;				//無人經過
	LED = 0;
  }
}
