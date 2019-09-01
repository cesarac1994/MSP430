#include <msp430.h>
#include <msp430g2452.h>
#define TIME_STARTT 200 //200 ms
#define TIME_STOPP 100 //100 ms

//ESCALA DOS PERÍODOS DAS NOTAS DE C1 A B8 (8 OITAVAS NO TOTAL)
#define NOTE_C1 15289
#define NOTE_D1 13621
#define NOTE_E1 12135
#define NOTE_F1 11454
#define NOTE_G1 10204
#define NOTE_A1 9091
#define NOTE_B1 8099

#define NOTE_C2 7645
#define NOTE_D2 6810
#define NOTE_E2 6067
#define NOTE_F2 5727
#define NOTE_G2 5102
#define NOTE_A2 4545
#define NOTE_B2 4050

#define NOTE_C3 3822
#define NOTE_D3 3405
#define NOTE_E3 3034
#define NOTE_F3 2863
#define NOTE_G3 2551
#define NOTE_A3 2273
#define NOTE_B3 2025

#define NOTE_C4 1911
#define NOTE_D4 1703
#define NOTE_E4 1517
#define NOTE_F4 1432
#define NOTE_G4 1276
#define NOTE_A4 1136
#define NOTE_B4 1012

#define NOTE_C5 956
#define NOTE_D5 851
#define NOTE_E5 758
#define NOTE_F5 716
#define NOTE_G5 638
#define NOTE_A5 568
#define NOTE_B5 506

#define NOTE_C6 478
#define NOTE_D6 426
#define NOTE_E6 379
#define NOTE_F6 358
#define NOTE_G6 319
#define NOTE_A6 284
#define NOTE_B6 253

#define NOTE_C7 239
#define NOTE_D7 213
#define NOTE_E7 190
#define NOTE_F7 179
#define NOTE_G7 159
#define NOTE_A7 142
#define NOTE_B7 127

#define NOTE_C8 119
#define NOTE_D8 106
#define NOTE_E8 95
#define NOTE_F8 89
#define NOTE_G8 80
#define NOTE_A8 71
#define NOTE_B8 63

void delay_ms(unsigned int delay)
{
    while (delay--)
    {
        __delay_cycles(1000); //TEM QUE SER CONDIZENTE COM O CLOCK DO MICROCONTROLADOR QUE ESTÁ EM 1MHz
    }
}

void tocaNota(unsigned int nota, unsigned int tempo)
{
  TACCR0 = nota;      //PERÍODO DO PWM
  TACCTL1 = OUTMOD_7;   //MODO DE SAÍDA DO TIMER0_A: RESET/SET
  TACCR1 = TACCR0/2;     //DUTY CYCLE DO PWM EM 50%
  TACTL = TASSEL_2 + MC_1;  //TASSEL_2 -> CLOCK SOURCE: MCLK  MC_1 ->                           //TIMER COM CONTAGEM PROGRESSIVA DE 0 ATÉ TACCR1
  delay_ms(tempo);
}

void tocaPausa(unsigned int pausa)
{
  TACCR0 = 1000;      //PERÍODO DO PWM
  TACCTL1 = OUTMOD_7;   //MODO DE SAÍDA DO TIMER0_A: RESET/SET
  TACCR1 = 0;     //DUTY CYCLE DO PWM EM 50%
  TACTL = TASSEL_2 + MC_1;  //TASSEL_2 -> CLOCK SOURCE: MCLK  MC_1 ->                           //TIMER COM CONTAGEM PROGRESSIVA DE 0 ATÉ TACCR1
  delay_ms(pausa);
}


int main(void) {

  //##########################################//
  //####  CONFIGURAÇÃO DO WATCHDOG TIMER  ####//
  //##########################################//

  WDTCTL = WDTPW | WDTHOLD;   //WATCHDOG TIMER PARADO

  //##########################################//
  //#######  CONFIGURAÇÃO DO CLOCK  ##########//
  //##########################################//

  DCOCTL = 0;                 //
  BCSCTL1 = CALBC1_1MHZ;      //CONFIGURA CLOCK EM 1 MHZ
  DCOCTL = CALDCO_1MHZ;       //

  //##########################################//
  //##########  DECLARAÇÃO DE I/Os  ##########//
  //##########################################//

  P1DIR |= 0x40;      //P1.6 IMPLEMENTADO COMO SAÍDA
  P1SEL |= 0x40;      //CONFIGURANDO P1.6 COMO PERIFÉRICO TA0.1

  //#################################################################//
  //#######  CONFIGURAÇÃO DO TIMER0_A (TOCANDO AS 8 OITAVAS)  #######//
  //#################################################################//
while(1){
//1
tocaNota(NOTE_C1,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
tocaNota(NOTE_D1,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
tocaNota(NOTE_E1,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
tocaNota(NOTE_F1,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
tocaNota(NOTE_G1,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
tocaNota(NOTE_A1,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
tocaNota(NOTE_B1,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
//2
tocaNota(NOTE_C2,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
tocaNota(NOTE_D2,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
tocaNota(NOTE_E2,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
tocaNota(NOTE_F2,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
tocaNota(NOTE_G2,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
tocaNota(NOTE_A2,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
tocaNota(NOTE_B2,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);

//3
tocaNota(NOTE_C3,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
tocaNota(NOTE_D3,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
tocaNota(NOTE_E3,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
tocaNota(NOTE_F3,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
tocaNota(NOTE_G3,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
tocaNota(NOTE_A3,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
tocaNota(NOTE_B3,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
//4
tocaNota(NOTE_C4,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
tocaNota(NOTE_D4,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
tocaNota(NOTE_E4,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
tocaNota(NOTE_F4,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
tocaNota(NOTE_G4,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
tocaNota(NOTE_A4,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
tocaNota(NOTE_B4,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);

//5
tocaNota(NOTE_C5,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
tocaNota(NOTE_D5,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
tocaNota(NOTE_E5,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
tocaNota(NOTE_F5,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
tocaNota(NOTE_G5,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
tocaNota(NOTE_A5,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
tocaNota(NOTE_B5,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
//6
tocaNota(NOTE_C6,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
tocaNota(NOTE_D6,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
tocaNota(NOTE_E6,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
tocaNota(NOTE_F6,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
tocaNota(NOTE_G6,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
tocaNota(NOTE_A6,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
tocaNota(NOTE_B6,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
//7
tocaNota(NOTE_C7,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
tocaNota(NOTE_D7,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
tocaNota(NOTE_E7,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
tocaNota(NOTE_F7,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
tocaNota(NOTE_G7,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
tocaNota(NOTE_A7,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
tocaNota(NOTE_B7,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);

//8
tocaNota(NOTE_C8,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
tocaNota(NOTE_D8,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
tocaNota(NOTE_E8,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
tocaNota(NOTE_F8,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
tocaNota(NOTE_G8,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
tocaNota(NOTE_A8,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
tocaNota(NOTE_B8,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
tocaNota(NOTE_C9,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);            //PARADA DE 100ms
///------------------------------------PARAR UM TEMPÃO DE 1 seg --------------------------------
tocaPausa(1000);
}
  //_BIS_SR(CPUOFF);    //DESLIGA A CPU PARA ECONOMIZAR CONSUMO (LPM0)

  return 0;

}
