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
 * @file stats.h
 * @brief Prototipos y documentación de utilidades estadísticas sobre arreglos.
 *
 * Declara funciones para imprimir, ordenar y calcular valores estadísticos
 * (mínimo, máximo, media y mediana) de un arreglo de bytes sin signo.
 *
 * @author Luis Francisco Sanchez Turrion
 * @date 2024-06-05
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief Imprime las estadísticas de un arreglo: mínimo, máximo, media y mediana.
 *
 * Los valores se redondean al entero más cercano. No modifica el arreglo de entrada.
 *
 * @param array Apuntador al arreglo de datos.
 * @param length Cantidad de elementos en el arreglo.
 */
void print_statistics(const unsigned char *array, unsigned int length);

/**
 * @brief Imprime los elementos de un arreglo de bytes.
 *
 * @param array Apuntador al arreglo de datos.
 * @param length Cantidad de elementos en el arreglo.
 */
void print_array(const unsigned char *array, unsigned int length);

/**
 * @brief Calcula la mediana de un arreglo.
 *
 * El arreglo original no se modifica; se usa una copia interna.
 *
 * @param array Apuntador al arreglo de datos.
 * @param length Cantidad de elementos en el arreglo.
 *
 * @return Valor de la mediana redondeado al entero más cercano.
 */
unsigned char find_median(const unsigned char *array, unsigned int length);

/**
 * @brief Calcula la media aritmética de un arreglo.
 *
 * @param array Apuntador al arreglo de datos.
 * @param length Cantidad de elementos en el arreglo.
 *
 * @return Valor de la media redondeado al entero más cercano.
 */
unsigned char find_mean(const unsigned char *array, unsigned int length);

/**
 * @brief Obtiene el valor máximo de un arreglo.
 *
 * @param array Apuntador al arreglo de datos.
 * @param length Cantidad de elementos en el arreglo.
 *
 * @return Valor máximo encontrado.
 */
unsigned char find_maximum(const unsigned char *array, unsigned int length);

/**
 * @brief Obtiene el valor mínimo de un arreglo.
 *
 * @param array Apuntador al arreglo de datos.
 * @param length Cantidad de elementos en el arreglo.
 *
 * @return Valor mínimo encontrado.
 */
unsigned char find_minimum(const unsigned char *array, unsigned int length);

/**
 * @brief Ordena un arreglo de bytes de mayor a menor.
 *
 * @param array Apuntador al arreglo de datos a ordenar (se modifica en sitio).
 * @param length Cantidad de elementos en el arreglo.
 */
void sort_array(unsigned char *array, unsigned int length);

#endif /* __STATS_H__ */
