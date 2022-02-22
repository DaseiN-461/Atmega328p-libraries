#include "PWM.h"


void setup() {
  cli();
  PWM_init();
  sei();
  PWM_setDutyA(128); //duty between 0-255
  PWM_on();
}

void loop() {
  // put your main code here, to run repeatedly:

}
