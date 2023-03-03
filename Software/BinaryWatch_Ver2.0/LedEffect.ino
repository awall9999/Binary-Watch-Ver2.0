void LedEffect(){
 // random Led
 for (int Loop = 0; Loop <= 9; Loop++) {
 int RND1 = random(1,16);
 int RND2 = random(1,16);
 int RND3 = random(1,16);
 int RND4 = random(1,16);
 int RND5 = random(1,3);

 
 LoopTimer = millis();
  do {
  LedDisplay(RND1,RND2,RND3,RND4,RND5,0); //row from left to right row1,row2,row3,row4 Doublepoint(1,2 or 3)  
    } while ((unsigned long)(millis() - LoopTimer) < 80); 
    




 }// end for loop
DDRD = B00000000; //All Led off 
}//end void
