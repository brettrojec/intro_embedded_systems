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
 * @brief statistics function declarations for unsigned char array
 *
 *
 * @author brett🦕
 * @date 2021-01-14
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief A function that prints the statistics of an array including minimum, maximum, mean, and median. 
 * 
 * Side effect - array is sorted.
 * @param arr - array to print
 * @param len - length of <arr>
 **/
void print_statistics(unsigned char arr[], int len);

/**
 * @brief Given an array of data and a length, prints the array to the screen
 * @param arr - array to print
 * @param len - length of <arr>
 **/
void print_array(unsigned char arr[], int len);

/**
 * @brief Given a SORTED array of data and a length, returns the median value
 * @param arr - the array
 * @param len - length of <arr>
 * @return - median value of <arr>
 **/
float find_median(unsigned char arr[], int len);

/**
 * @brief Given an array of data and a length, returns the mean
 * @param arr - the array
 * @param len - length of <arr>
 * @return - the mean value of <arr>
 **/
float find_mean(unsigned char arr[], int len);

/**
 * @brief Given an array of data and a length, returns the maximum
 * @param arr - the array
 * @param len - length of <arr>
 * @return - maximum value in <arr>
 **/
unsigned char find_maximum(unsigned char arr[], int len);

/**
 * @brief Given an array of data and a length, returns the minimum value
 * @param arr - the array
 * @param len - length of <arr>
 * @return - minimum value in <arr>
 **/
unsigned char find_minimum(unsigned char arr[], int len);

/**
 * @brief Given an array of data and a length, sorts the array from largest to smallest.  (The zeroth Element should be the largest value, and the last element (n-1) should be the smallest value. )
 * Use the CountingSort algorithm to sort (descending) the input array of unsigned characters.
 * 
 * @param arr - the array
 * @param len - length of <arr>
 * @return - a new array of lenght <len>, containing the sorted values of <arr>
 **/
void sort_array(unsigned char arr[], int len);

#endif /* __STATS_H__ */
