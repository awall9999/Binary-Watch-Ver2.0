#include <Wire.h>
#define RTC_ADDRESS 0x32
byte decToBcd(byte val)
{
  return ( (val / 10 * 16) + (val % 10) );
}
// Convert binary coded decimal to normal decimal numbers
byte bcdToDec(byte val)
{
  return ( (val / 16 * 10) + (val % 16) );
}

byte Minute, Hour;
byte  Week, Day, Month;

const byte LEDS[][2] = {
  
  {48, 16}, {48,32},{24, 8},{24,16},
  {96,64},{96, 32},{192, 128},{192, 64},
  {80, 16},{80,64},{160, 32},{160,128},
  {72,64},{72, 8},{144,128},{144, 16}, 
  {40, 8}, {40,32}
};

long int LoopTimer;
boolean BlockPusch =false; 
boolean BlockRelease =false; 
boolean SetupPusch =false; 
boolean TimeDate =false; 
long int PushTimer;
long int Blinktime;
int Blink;
int EnBlink=0;
int SetupMenu = 0;
int SetupCounter = 0;



void microsecond(){
long int slowdown = micros();
  do {
    
  } while ((unsigned long)(micros() - slowdown) < 100); 
    

}



void millisecond(int Value){
long int delaytimer = millis();
  do {
    
  } while ((unsigned long)(millis() - delaytimer) < Value); 
    

}

void InitWatch(){
  digitalWrite(8,HIGH);
  LedEffect();
  LoopTimer = millis();
  TimeDate =false; 
  SetupPusch =false; 
  SetupMenu = 0;
  
}

void setup() {
  Wire.begin();
  DDRD = B00000000;
  pinMode(8, OUTPUT);
  pinMode(2, INPUT_PULLUP);
 // Minute=33;
 // Hour=14;
}

void loop() {
  InitWatch();
  ReadRTC();
  
    do {
      pinMode(2, INPUT_PULLUP);
      
  if (digitalRead(2) == 0 && BlockPusch == false) {PushTimer = millis();microsecond();BlockPusch = true;LoopTimer = millis();} // Reset LoopTimer also
  if (digitalRead(2) == 0 && BlockPusch == true && SetupPusch == false ) {
                                                                          if ((unsigned long)(millis() - PushTimer) > 1500){LoopTimer = millis();SetupMenu++; SetupPusch = true;}} // Reset LoopTimer also 

  
  
  if (digitalRead(2) == 1 && BlockPusch == true && SetupMenu == 0 && SetupPusch == false)  {BlockPusch = false;SetupPusch = false;TimeDate=!TimeDate;} // false = time true = date
  if (digitalRead(2) == 1 && BlockPusch == true && SetupMenu > 0)  {LoopTimer = millis();BlockPusch = false;Blink=0;Blinktime = millis();
                                                                                         if (SetupPusch == false && SetupMenu == 1) {Hour++;if(Hour>24){Hour=0;}} 
                                                                                         if (SetupPusch == false && SetupMenu == 2) {Minute++;if(Minute>60){Minute=0;}}
                                                                                         if (SetupPusch == false && SetupMenu == 3) {Day++;if(Day>32){Day=1;}}
                                                                                         if (SetupPusch == false && SetupMenu == 4) {Month++;if(Month>13){Month=1;}}
                                                                                         
                                                                                          SetupPusch = false;} // false = time true = date


 if (SetupMenu == 0 && TimeDate == false) {DisplayRawData(Hour,Minute,3,0);}
 if (SetupMenu == 0 && TimeDate == true) {DisplayRawData(Day,Month,2,0);}

 if (SetupMenu == 1) {DisplayRawData(Hour,0,1,1);}
 if (SetupMenu == 2) {DisplayRawData(0,Minute,1,1);}
 if (SetupMenu == 3) {DisplayRawData(Day,0,2,1);}
 if (SetupMenu == 4) {DisplayRawData(0,Month,2,1);}  
 if (SetupMenu == 5 && digitalRead(2) == 0) {DDRD=B00000000;LoopTimer = millis();}
 if (SetupMenu == 5 && digitalRead(2) == 1) {InitWatch();SetRTC();BlockPusch = false;PushTimer = millis(); } // write to RTC
    //DisplayRawData(Hour,Minute);
    } while ((unsigned long)(millis() - LoopTimer) < 5000); 

GoodNight();
  
}
