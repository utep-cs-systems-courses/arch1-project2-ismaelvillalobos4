#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

static int counterForSong1 = 0;
static int counterForSong2 = 0;
static int counterForSong3 = 0;
static int counterForSong4 = 0;

void buzzer_init()
{
    /* 
       Direct timer A output "TA0.1" to P2.6.  
        According to table 21 from data sheet:
          P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero
          P2SEL.6 must be 1
        Also: P2.6 direction must be output
    */
    timerAUpmode();		/* used to drive speaker */
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7; 
    P2SEL |= BIT6;
    P2DIR = BIT6;		/* enable output to speaker (P2.6) */
}

void song1() {
    switch (counterForSong1) {
      case 0:
	buzzer_set_period(750);
	counterForSong1++;
	break; //E note

      case 1:

      case 2:

      case 11:

      case 12:
	buzzer_set_period(630);
	counterForSong1++;
	break; //G note

      case 3:

      case 4:

      case 13:

      case 14:
	buzzer_set_period(560);
	if(counterForSong1==14)
	  {counterForSong1 = 0;}
	else{counterForSong1++;};
	break; //A note

      case 5:

      case 7:

      case 9:
	buzzer_set_period(950);
	counterForSong1++;
	break; //C note

      case 6:

      case 8:

      case 10:
	buzzer_set_period(500);
	counterForSong1++;
	break; //B note

      }
}

void song2() {
    switch(counterForSong2){
        case 0:
        case 1:
        case 2:
        case 3: 
            buzzer_set_period(1000); // E note
            counterForSong2++; 
            break; 
        case 4: 
            buzzer_set_period(250); // C note
            counterForSong2++;
            break; 
        case 5: 
            buzzer_set_period(1930); // G note
            counterForSong2++; 
            break; 
        case 6: 
            buzzer_set_period(2060); // Lower G note
            counterForSong2++;
            break; 
        case 7: 
            buzzer_set_period(100);
            counterForSong2 = 0;
            break;
    }
}

void song3(){
    switch (counterForSong3) {
    case 0:

    case 1:

    case 2:

    case 4:
      buzzer_set_period(750);
      counterForSong3++;
      break; //E note

    case 3:
      buzzer_set_period(950);
      counterForSong3++;
      break; //C note

    case 5:
      buzzer_set_period(630);
      counterForSong3++;
      break; //G note

    case 6:
      buzzer_set_period(1260);
      counterForSong3 = 0;
      break; //Lower G note

       
    }
}

void song4() {
    switch (counterForSong4) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            buzzer_set_period(250);
            counterForSong4++;
            break;
        case 5:
        case 6:
        case 7: 
            buzzer_set_period(750);
            counterForSong4++;
            break;
        case 8:
            buzzer_set_period(1000);
            counterForSong4++;
            break;
        case 9: 
            buzzer_set_period(800);
            counterForSong4++;
            break;
        case 10:
            buzzer_set_period(250);
            counterForSong4++;
            break;
        case 11:
        case 12:
        case 14:
            buzzer_set_period(125);
            counterForSong4 = 0;
            break;
            
    }
}

void buzzer_set_period(short cycles) /* buzzer clock = 2MHz.  (period of 1k results in 2kHz tone) */
{
    CCR0 = cycles; 
    CCR1 = cycles >> 1;		/* one half cycle */
}


     
