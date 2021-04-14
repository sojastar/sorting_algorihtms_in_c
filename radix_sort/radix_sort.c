#include <stdlib.h>
#include <stdio.h>
#include "radix_sort.h"





/* ---=== Function Declarations : ===--- */
uint8_t hex_digit(uint16_t n, uint16_t digit) {
  uint16_t p = 4 * digit;
  return (n >> p) % 16;
}

void count_sort_by_hex_digit(size_t input_length,uint16_t* input,uint16_t digit) {
  // 1. Counting input keys :
  /* We are sorting hex digits, so the input_count count array ...
   * ... is of length 16. */
  uint16_t input_count[16] = { 0 };
  for (size_t i = 0; i < input_length; ++i)
    input_count[hex_digit(input[i], digit)] += 1;

  // 2. Stacking counts :
  for (size_t i = 1; i < 16; ++i)
    input_count[i] += input_count[i-1];

  // 3. Actually sorting :
  uint16_t* output = (uint16_t*)calloc(input_length, sizeof(uint16_t));
  for (ssize_t i = input_length - 1; i >= 0; i -= 1) {
    uint16_t key = hex_digit(input[i], digit);
    input_count[key] -= 1;
    output[input_count[key]] = input[i];
  }

  // 4. Copying the results to to original array :
  for (size_t i = 0; i < input_length; ++i)
    input[i] = output[i];
}

void radix_sort(size_t input_length,uint16_t* input) {
  for (size_t i = 0; i < 16; ++i)
    count_sort_by_hex_digit(input_length, input, i);
}
