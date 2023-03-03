void GoodNight(){
  
   PORTD= 4;

    sei();
    attachInterrupt(0,wakeup, LOW);
    ADCSRA &= ~(1 << 7); //Disable ADC
    SMCR |= (1 << 2); // power down mode
    SMCR |= 1; // enable sleep mode
    // BOD disable
    MCUCR |= (3 << 5); // Set Bods and Bodse to 1
    MCUCR = (MCUCR &~(1 << 5)) | (1 << 6);
    __asm__ __volatile__("sleep");
}
    
void wakeup(){
  
  detachInterrupt(0);
  
  
}
