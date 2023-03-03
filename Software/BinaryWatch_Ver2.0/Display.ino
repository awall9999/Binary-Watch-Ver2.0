void DisplayRawData(int Val1,int Val2,int Val3,int Val4){
int Row1 , Row2 , Row3, Row4;

Row1 = (Val1/10);
Row2 = (Val1 - (Row1*10));
Row3 = (Val2/10);
Row4 = (Val2 - (Row3*10));

LedDisplay(Row1,Row2,Row3,Row4,Val3,Val4); //row from left to right row1,row2,row3,row4 Doublepoint(1,2 or 3)   

}






void LedDisplay(int Val1,int Val2,int Val3,int Val4,int Val5,int Val6){

int ScanValue;
EnBlink = Val6;
if ((unsigned long)(millis() - Blinktime) > 250) {Blink = !Blink; Blinktime = millis();DDRD=B00000000;}

if (Blink == 0 || EnBlink == 0){
for (int a = 0; a <= 16; a=a+4) {

  for (int i = 0+a; i <= 3+a; i++) {
    ScanValue = Val1;
    if (a==4) ScanValue = Val2;
    if (a==8) ScanValue = Val3;
    if (a==12) ScanValue = Val4;
    if (a==16) ScanValue = Val5;
    if (bitRead(ScanValue, i-a) == 1){  
    
    DDRD = LEDS[i][0] ;
    PORTD= LEDS[i][1] ;
  
                                     }

    microsecond();
                                    }
                                  }
  
}}
