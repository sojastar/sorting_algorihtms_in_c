#include <stdlib.h>
#include <stdio.h>
#include "counting_sort.h"





/* ---=== Function Declaration : ===--- */
void counting_sort(size_t input_length,uint16_t* input) {
  // 1. Finding the working range :
  uint16_t input_range  = 0;
  for (size_t i = 0; i < input_length; i++)
    if (input[i] > input_range)
      input_range = input[i];
  input_range += 1;

  // 2. Counting input keys :
  uint16_t* input_count = (uint16_t*)malloc(input_range * sizeof(uint16_t));
  for (size_t i = 0; i < input_length; ++i)
    input_count[input[i]] += 1;

  // 3. Stacking counts :
  for(size_t i = 1; i < input_range; ++i)
    input_count[i] += input_count[i-1];

  // 4. Actually sorting :
  uint16_t* output = (uint16_t*)malloc(input_length * sizeof(uint16_t));
  for (ssize_t i = input_length - 1; i >= 0; --i) {
    uint16_t key = input[i];
    input_count[key] -= 1;
    output[input_count[key]] = key;
  }

  for (size_t i = 0; i < input_length; ++i)
    input[i] = output[i];

  free(output);
  free(input_count);
}
