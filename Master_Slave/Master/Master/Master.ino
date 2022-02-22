#include "SPI.h"
#include "ADC.h"
#include "ISR.h"



/* ------------------------------------- */
/* Declare variables and function for ADC */
char ADC_buffer[10];
uint16_t dato_adc;
/* ------------------------------------- */


void setup() {
  ADC_init();
  delay(1000);
  SPI_Master_init();
  delay(1000);
  Serial.begin(9600);

  /* Inicia el timer1 para generar interrupciones
  cada 1 segundo */
  //T1_ISR_init(1);
}

void loop() {
  /* Atomizar en una función en librería ADC */
  dato_adc = ADC_read(1);
  itoa(dato_adc, ADC_buffer, 10); //conversion de entero a str
  //Serial.println(ADC_buffer);
  
  /* Atomizar en una función en librería SPI */
  SPI_SlaveON(1);
  SPI_TX_string(ADC_buffer);
  SPI_SlaveOFF(1);
  //Serial.println("dato enviado");

  delay(3000);
}
/*
ISR(TIMER1_COMPA_vect){
  
}
*/
