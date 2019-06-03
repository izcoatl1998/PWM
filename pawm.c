#include <pawm.h>
void main()
{  
    int trabajo=103;
    int timer2=249;
    int poscaler=1;//div by 4 ,249+1,1  con 4MHZ
    setup_timer_2(t2_div_by_16,timer2,poscaler);
    setup_ccp1(ccp_pwm);
    setup_adc_ports(all_analog);
    setup_adc(adc_clock_internal);
   while(TRUE)
   {
        set_adc_channel(0);
        delay_ms(100);
        trabajo=read_adc(794);
        set_pwm1_duty(897);
   }

}
