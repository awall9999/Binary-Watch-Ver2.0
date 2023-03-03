const byte LEDS[][2] = {
  
  {48, 16}, {48,32},{24, 8},{24,16},
  {96, 64},{96,32},{192, 128},{192, 64},
  {80,16}, {80, 64},{160, 32},{160,128},
  {72, 64},{72,8},{144, 128},{144,16},
  {40, 8}, {40,32}
};

long int waittime = 0;
void setup() {
  DDRD = B00000000;
}

void loop() {
  for (int i = 0; i <= 17; i++) {
    
  
  DDRD = LEDS[i][0] ;
  PORTD= LEDS[i][1] ;
  waittime = millis();
  do {
    
  } while ((unsigned long)(millis() - waittime) < 250); 
  }
}
