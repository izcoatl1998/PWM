#include <pawm.h>
#INT_RB
int duty=0;
void RB_isr(void){
    if(input(PIN_B0)==0){
       duty+=123;
      }
    /*output_toggle(PIN_B1);
    delay_ms(1000);*/
}
void main()
{  
    set_tris_b(0xFF); //Puerto B como entrada 
    set_tris_d( 0x00 ); // Puerto D como salida. 
    int trabajo=103;
    int timer2=249;
    int poscaler=1;//div by 4 ,249+1,1  con 4MHZ
    setup_timer_2(t2_div_by_16,timer2,poscaler);
    setup_ccp1(ccp_pwm);
    setup_adc_ports(all_analog);
    setup_adc(adc_clock_internal);
    enable_interrupts(INT_RB);
    enable_interrupts(GLOBAL);
   while(TRUE)
   {
        set_adc_channel(0);
        delay_ms(100);
        //trabajo=read_adc(794);
        set_pwm1_duty(duty);
   }

}
