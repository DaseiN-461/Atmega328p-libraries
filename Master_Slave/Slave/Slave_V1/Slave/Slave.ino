#include "SPI.h"




void setup(){
  SPI_Slave_init();
}

void loop() {
  String string = get_line_SPI();
  int valor = string.toInt();
}
