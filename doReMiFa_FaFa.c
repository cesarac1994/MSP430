#include <msp430.h>
#include <msp430g2452.h>
#define TIME_STARTT 200 //200 ms
#define TIME_STOPP 100 //100 ms

//ESCALA DOS PERÍODOS DAS NOTAS DE C5 A B5 
#define NOTE_C5 956
#define NOTE_D5 851
#define NOTE_E5 758
#define NOTE_F5 716
#define NOTE_G5 638
#define NOTE_A5 568
#define NOTE_B5 506

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
  TACCR1 = 0;     //NIVEL LOGICO BAIXO
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
while(1)
{
    //do re mi fa
  tocaNota(NOTE_C5,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
  tocaNota(NOTE_D5,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
  tocaNota(NOTE_E5,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
  tocaNota(NOTE_F5,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
  tocaPausa(TIME_STOPP);
  //fa fa
  tocaNota(NOTE_F5,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
  tocaNota(NOTE_F5,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);

  //do re do re
  tocaNota(NOTE_C5,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
  tocaNota(NOTE_D5,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
  tocaNota(NOTE_C5,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
  tocaNota(NOTE_D5,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
  tocaPausa(TIME_STOPP);
  tocaPausa(TIME_STOPP);
  //re re
  tocaNota(NOTE_D5,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
  tocaNota(NOTE_D5,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);

  //do sol fa mi
  tocaNota(NOTE_C5,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
  tocaNota(NOTE_G5,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
  tocaNota(NOTE_F5,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
  tocaNota(NOTE_E5,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
  tocaPausa(TIME_STOPP);
  tocaPausa(TIME_STOPP);
  //mi mi
  tocaNota(NOTE_E5,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
  tocaNota(NOTE_E5,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);

  //do re mi fa
  tocaNota(NOTE_C5,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
  tocaNota(NOTE_D5,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
  tocaNota(NOTE_E5,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
  tocaNota(NOTE_F5,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
  tocaPausa(TIME_STOPP);
  //fa fa
  tocaNota(NOTE_F5,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
  tocaNota(NOTE_F5,TIME_STARTT);      //PERÍODO DO PWM
  tocaPausa(TIME_STOPP);
  ///------------------------------------PARAR UM TEMPÃO DE 2 seg --------------------------------
  tocaPausa(2000);
}
  //_BIS_SR(CPUOFF);    //DESLIGA A CPU PARA ECONOMIZAR CONSUMO (LPM0)

  return 0;

}
