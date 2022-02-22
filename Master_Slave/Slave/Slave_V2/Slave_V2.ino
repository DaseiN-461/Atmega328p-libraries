#include "SPI.h"
#include "PWM.h"



void setup(){
  SPI_Slave_init();
  delay(3000);
  
  cli();
  PWM_init();
  sei();

  PWM_setDutyA(128); //duty between 0-255
  PWM_on();
}

void loop() {
  String string = get_line_SPI();
  int value = string.toInt();

  int dc_pwm = map(value, 0, 1023, 0, 255);
  PWM_setDutyA(dc_pwm);
  PWM_on();
}
