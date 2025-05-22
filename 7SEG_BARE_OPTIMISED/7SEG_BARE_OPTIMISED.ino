#include<avr/io.h>
#include<util/delay.h>

void number(int i){

  PORTD &= ~((1<<PD2)|(1<<PD3)|(1<<PD4)|(1<<PD5)|(1<<PD6)|(1<<PD7));
  PORTB &= ~(1<<PB0);

  
  switch(i){

    case 0:
      PORTD = PORTD &(~(1<<PD2)) &(~(1<<PD3)) &(~(1<<PD4)) & (~(1<<PD5)) & (~(1<<PD6)) & (~(1<<PD7));
      PORTB = PORTB | (1<<PB0);
      break;


    case 1: 
      PORTD = PORTD & ~((1<<PD3) | (1<<PD4));
      PORTD = PORTD | (1<<PD2) | (1<<PD5) | (1<<PD6) | (1<<PD7);
      PORTB = PORTB | (1<<PB0);
      break;

    case 2:
      PORTD = PORTD & ~((1<<PD2) | (1<<PD3) | (1<<PD5) | (1<<PD6));
      PORTB = PORTB & ~(1<<PB0);
      PORTD = PORTD | (1<<PD4) | (1<<PD7); 
      break;

    case 3: 
      PORTD = PORTD & (~((1<<PD2) | (1<<PD3) | (1<<PD4) | (1<<PD5)));
      PORTB = PORTB & ~(1<<PB0);
      PORTD = PORTD | (1<<PD6) | (1<<PD7);
      break;

    case 4: 
      PORTD = PORTD & (~((1<<PD3) | (1<<PD4) | (1 << PD7)));
      PORTB = PORTB & ~(1<<PB0);
      PORTD = PORTD | (1<<PD2) | (1<<PD5) | (1<<PD6);
      break;
    
    case 5: 
      PORTD = PORTD & (~((1<<PD2) | (1<<PD4) | (1<<PD5) | (1<<PD7)));
      PORTB = PORTB & ~(1<<PB0);
      PORTD = PORTD | (1<<PD3) | (1<<PD6);
      break;

    case 6: 
      PORTD = PORTD & (~((1<<PD2) | (1<<PD4) | (1<<PD5) | (1<<PD6) | (1<<PD7)));
      PORTB = PORTB & ~(1<<PB0);
      PORTD = PORTD | (1<<PD3);
      break;

    case 7:
      PORTD = PORTD & (~((1<<PD2) | (1<<PD3) | (1<<PD4)));
      PORTD = PORTD | (1<<PD5) | (1<<PD6) | (1<<PD7);
      PORTB = PORTB | (1<<PB0);
      break;

    case 8: 
      PORTD = PORTD & (~((1<<PD2) | (1<<PD3) | (1<<PD4) | (1<<PD5) | (1<<PD6) | (1<<PD7)));
      PORTB = PORTB & (~(1<<PB0));
      break;

    case 9:
      PORTD = PORTD & (~((1<<PD2) | (1<<PD3) | (1<<PD4) | (1<<PD5) | (1<<PD7)));
      PORTB = PORTB & ~((1<<PB0));
      PORTD = PORTD | (1<<PD6);
      break;

    default:
      PORTD = PORTD | (1<<PD2) | (1<<PD3) | (1<<PD4) | (1<<PD5) | (1<<PD6) | (1<<PD7);
      PORTB = PORTB | (1<<PB0);
      break;

  }
}

int main(){

  DDRD = DDRD | (1<<DDD2) | ((1<<DDD3)) | (1<<DDD4) | (1<<DDD5) | (1<<DDD6) | (1<<DDD7);
  DDRB = DDRB | (1<<DDB0);

  int num = 9;
  int i = 0;
 while(1){
  while(i<=num){
    number(i);
    _delay_ms(500);
    i++;
  }
  _delay_ms(500);

}

}


