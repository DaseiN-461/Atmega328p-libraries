
void PWM_init(){
  //Operation Mode = Fast PWM
  TCCR0A |= (1<<WGM00);
  TCCR0A |=  (1<<WGM01);
  TCCR0B &=~  (1<<WGM02);
 
}


void PWM_on()
{
  TCNT0 = 0x0000;
  //N = 1024
  TCCR0B |=  (1<<CS00);
  TCCR0B &=~ (1<<CS01);
  TCCR0B |=  (1<<CS02);
}

void PWM_off()
{
  //Clock setting T1clock = 0 Hz
  TCCR0B &=~ (1<<CS00);
  TCCR0B &=~ (1<<CS01);
  TCCR0B &=~ (1<<CS02);
}

void PWM_setDutyA(int duty){
  DDRD |= (1<<DDD6);

  TCCR0A &=~ (1<<COM0A0);
  TCCR0A |=  (1<<COM0A1);
  OCR0A = duty;
}
