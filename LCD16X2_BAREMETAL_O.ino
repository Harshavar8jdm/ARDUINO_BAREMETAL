#include<AVR/io.h>
#include<UTIL/delay.h>

void lcd_cmd(unsigned char command);
void lcd_initialise();
void lcd_data(unsigned char data);
void lcd_string(unsigned char *str, int length);
void lcd_clear();

int main(){
  // WE ARE GOING ENTIRE PORTD (DIGITAL PINS (0-7)) FOR OUTPUT FOR 8 DATA LINES (D0 - D7)
  // WE ARE GOING PORTB FOR CONTROLLING RS RW AND EN (RS = D8; RW = D9; EN = D10 on the uno board)
  
  DDRD = 0xFF; // SET ENTIRE PORTD AS OUTPUT 
  DDRB = DDRB | (1<<DDB0) | (1<<DDB1) | (1<<DDB2); // SET PB0 PB1 AND PB2 as output 
  
  // NOW WE NEED TO INITIALISE THE DISPLAY BY THE COMMANDS FOR THE INSTRUCTION 
  // REGISTOR OF THE 16X2 DISPLAY 

  lcd_initialise();

  while(1){ //Main Loop

  lcd_cmd(0x80);
  lcd_string("HELLO WORLD", 11);
  _delay_ms(1000);
  lcd_clear();
  lcd_string("This is working!", 17);
  _delay_ms(1000);
  lcd_clear();

  }

}

void lcd_cmd(unsigned char command){
  
  PORTD = command;
  PORTB = PORTB & ~(1<<PB0); // RS = 0 IS FOR SELECTING INSTRUCTION REGISTER
  PORTB = PORTB & ~(1<<PB1); //RW = 0 FOR WRITE MODE OF INSTRUCTION REGISTER
  PORTB = PORTB | (1<<PB2); //EN = 1 FOR EXECUTING THE COMMAND
  _delay_ms(10); //Wait time for each character to appear before proceeding to the next
  PORTB = PORTB & ~(1<<PB2); //EN = 0 Return to default

}

void lcd_initialise(){

  lcd_cmd(0x38); //INITIALISING INDIVIDUAL 5X7 PIXEL MATRIX 
  lcd_cmd(0x0C); //TURN DISPLAY ON, CURSOR OFF MODE
  lcd_cmd(0x06); //SET CURSOR MODE TO INCEMENTAL MODE (CURSOR MOVES LEFT TO RIGHT)
  lcd_cmd(0x01); //CLEARS DISPLAY ENTIRELY

};

void lcd_data(unsigned char data){

  PORTD = data; //ASSIGN THE DATA TO DATA REGISTER OF THE PORTD REGISTER OF UNO 
  PORTB = PORTB | (1<<PB0);   //  RS = 1 IS FOR SELECTING THE DATA REGISTER OF LCD
  PORTB = PORTB & ~(1<<PB1);  // R/W = 0 IS FOR WRITING THE DATA FROM UNO PORTD TO DATA REGISTER OF LCD
  PORTB = PORTB | (1<<PB2);   // EN = 1 IS FOR EXECUTING THE COMMAND
  _delay_ms(10);
  PORTB = PORTB & ~(1<<PB2); // EN = 0 Return to Default

}

void lcd_string(unsigned char *str, int length){
  //FOR LOOP IS TO INJECT CHARCTERS ONE BY ONE INTO THE DATA REGISTER OF THE LCD
  //AS IN 8 BIT SYSTEM 1 CHAR = 8 BITS. 
  // So it is only possible to inject characters one by one until the entire string is displayed on lcd
  

  for(int i = 0 ; i < length; i++){

    lcd_data(str[i]); 
    
  }

}

void lcd_clear(){
  lcd_cmd(0x01); //COMMAND TO CLEAR ENTIRE DISPLAY
}








