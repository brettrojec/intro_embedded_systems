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
 * @brief Array statistics
 *
 * Several functions to find & display statistics of an unsigned char[].
 *
 * @author brett🦕
 * @date 2021-02-13
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  print_statistics(test, SIZE);
}

void print_statistics(unsigned char arr[], int len){
  printf("\r\nstatistics for array: ");
  print_array(arr, len);
  sort_array(arr, len);
  // printf("sorted array: ");
  // print_array(arr, len);
  printf("mean: %f\r\n", find_mean(arr, len));
  printf("median: %f\r\n", find_median(arr, len));
  printf("max: %u\r\n", find_maximum(arr, len));
  printf("min: %u\r\n", find_minimum(arr, len));

}

void print_array(unsigned char arr[], int len){
  for (int i=0; i<len; i++){
    printf("%u ", arr[i]);
  }
  printf("\r\n");
}

float find_median(unsigned char arr[], int len){
  if (len % 2 != 0){
    return (float) arr[len/2 + 1];
  }
  return (arr[(len / 2) - 1] + arr[len / 2]) / 2.0;
}

float find_mean(unsigned char arr[], int len){
  float mean = (float) arr[0];
  for (int i=1; i<len; i++){
    mean += (float) arr[i];
  }
  return mean / len;
}

unsigned char find_maximum(unsigned char arr[], int len){
  unsigned char max = arr[0];
  for (int i=1; i<len; i++){
    if (arr[i] > max)
      max = arr[i];
  }
  return max;
}

unsigned char find_minimum(unsigned char arr[], int len){
  unsigned char min = arr[0];
  for(int i=1; i<len; i++){
    if (arr[i] < min)
      min = arr[i];
  }
  return min;
}

void sort_array(unsigned char arr[], int len){
  unsigned char max = find_maximum(arr, len);
  unsigned char count[max + 1];
  unsigned char copy[len];

  for(int i=0; i<=max; i++){
    count[i] = 0;
  }

  for (int i=0; i<len; i++){
    count[arr[i]]++;
    copy[i] = arr[i];
  }

  unsigned char last = count[0];
  for (int i=1; i<=max; i++){
    count[i] += last;
    last=count[i];
  }

  int sortedIndex;
  for (int i=0; i<len; i++){
    sortedIndex = count[arr[i]] - 1;
    copy[len - sortedIndex - 1] = arr[i]; // update the input arr to be sorted in reverse order
    count[arr[i]]--;
  }
  for (int i=0; i<len; i++){
    arr[i] = copy[i]; //copy values b/c for some GD reason doing it in the previous loop doesn't work
  }
}
