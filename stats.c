/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief Implementa funciones básicas de estadística sobre un arreglo de enteros sin signo.
 *
 * Calcula mínimo, máximo, media y mediana de un arreglo de bytes sin signo,
 * ordena el arreglo de mayor a menor y muestra los resultados por consola.
 *
 * @author Luis Francisco Sanchez Turrion
 * @date 2024-06-05
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

int main(void) {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  printf("Vector original:\n");
  print_array(test, SIZE);

  /* Ordenamos y mostramos estadísticas */
  sort_array(test, SIZE);
  printf("\n Vector ordenado (mayor a menor):\n");
  print_array(test, SIZE);

  print_statistics(test, SIZE);

  return 0;
}

void print_statistics(const unsigned char *array, unsigned int length) {

}

void print_array(const unsigned char *array, unsigned int length) {

}

unsigned char find_median(const unsigned char *array, unsigned int length) {

}

unsigned char find_mean(const unsigned char *array, unsigned int length) {

}

unsigned char find_maximum(const unsigned char *array, unsigned int length) {

}

unsigned char find_minimum(const unsigned char *array, unsigned int length) {


void sort_array(unsigned char *array, unsigned int length) {

}
