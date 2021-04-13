#include <stdlib.h>
#include <stdio.h>
#include "counting_sort_key.h"





/* ---=== Function Declaration : ===--- */
void counting_sort_key(size_t input_length,Data** input,Data** output) {
  // 1. Finding the working range :
  uint16_t key_range = 0;
  for (size_t i = 0; i < input_length; ++i)
    if (input[i]->key > key_range)
      key_range = input[i]->key;
  key_range += 1;

  // 2. Counting input keys :
  uint16_t* input_count = (uint16_t*)malloc(key_range * sizeof(uint16_t));
  for(size_t i = 0; i < input_length; ++i)
    input_count[input[i]->key] += 1;

  // 3. Stacking counts :
  for(size_t i = 1; i < key_range; ++i)
    input_count[i] += input_count[i-1];

  // 4. Actually sorting :
  for (ssize_t i = input_length - 1; i >= 0; --i) {
    uint16_t key = input[i]->key;
    input_count[key] -= 1;
    output[input_count[key]] = input[i];
  }

  free(input_count);
}
