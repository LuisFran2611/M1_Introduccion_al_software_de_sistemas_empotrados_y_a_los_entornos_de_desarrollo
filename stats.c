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

  printf("Arreglo original:\n");
  print_array(test, SIZE);

  /* Ordenamos y mostramos estadísticas */
  sort_array(test, SIZE);
  printf("\nArreglo ordenado (mayor a menor):\n");
  print_array(test, SIZE);

  print_statistics(test, SIZE);

  return 0;
}

void print_statistics(const unsigned char *array, unsigned int length) {
  unsigned char min = find_minimum(array, length);
  unsigned char max = find_maximum(array, length);
  unsigned char mean = find_mean(array, length);
  unsigned char median = find_median(array, length);

  printf("\nEstadísticas del arreglo:\n");
  printf("  Tamaño : %u\n", length);
  printf("  Mínimo : %u\n", min);
  printf("  Máximo : %u\n", max);
  printf("  Media  : %u\n", mean);
  printf("  Mediana: %u\n", median);
}

void print_array(const unsigned char *array, unsigned int length) {
  for (unsigned int i = 0; i < length; i++) {
    printf("%3u ", array[i]);
    if ((i + 1) % 8 == 0) {
      printf("\n");
    }
  }
  if (length % 8 != 0) {
    printf("\n");
  }
}

unsigned char find_median(const unsigned char *array, unsigned int length) {
  unsigned char temp[length];

  /* Copiamos para no modificar la entrada al calcular la mediana */
  for (unsigned int i = 0; i < length; i++) {
    temp[i] = array[i];
  }

  sort_array(temp, length);

  if (length % 2 != 0) {
    return temp[length / 2];
  }

  unsigned int mid_high = temp[length / 2];
  unsigned int mid_low = temp[(length / 2) - 1];
  return (unsigned char)((mid_low + mid_high + 1) / 2);
}

unsigned char find_mean(const unsigned char *array, unsigned int length) {
  unsigned int sum = 0;
  for (unsigned int i = 0; i < length; i++) {
    sum += array[i];
  }

  return (unsigned char)((sum + (length / 2)) / length);
}

unsigned char find_maximum(const unsigned char *array, unsigned int length) {
  unsigned char max = array[0];
  for (unsigned int i = 1; i < length; i++) {
    if (array[i] > max) {
      max = array[i];
    }
  }
  return max;
}

unsigned char find_minimum(const unsigned char *array, unsigned int length) {
  unsigned char min = array[0];
  for (unsigned int i = 1; i < length; i++) {
    if (array[i] < min) {
      min = array[i];
    }
  }
  return min;
}

void sort_array(unsigned char *array, unsigned int length) {
  /* Ordenamiento por selección de mayor a menor */
  for (unsigned int i = 0; i < length; i++) {
    unsigned int max_index = i;
    for (unsigned int j = i + 1; j < length; j++) {
      if (array[j] > array[max_index]) {
        max_index = j;
      }
    }
    if (max_index != i) {
      unsigned char temp = array[i];
      array[i] = array[max_index];
      array[max_index] = temp;
    }
  }
}
