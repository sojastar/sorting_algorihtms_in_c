#include <stdlib.h>
#include <stdio.h>
#include "radix_sort_key.h"





/* ---=== Function Declarations : ===--- */
uint8_t hex_digit(uint16_t n, uint16_t digit) {
  uint16_t p = 4 * digit;
  return (n >> p) % 16;
}

RadixItem* format_input_data(size_t input_length,Data* input) {
  RadixItem* formated_input_data = (RadixItem*)calloc(input_length, sizeof(RadixItem));

  for(size_t i = 0; i < input_length; ++i)
    formated_input_data[i]  = (RadixItem) { .data   = &input[i],
                                            .digits = { hex_digit(input[i].key,  0),
                                                        hex_digit(input[i].key,  1),
                                                        hex_digit(input[i].key,  2),
                                                        hex_digit(input[i].key,  3),
                                                        hex_digit(input[i].key,  4),
                                                        hex_digit(input[i].key,  5),
                                                        hex_digit(input[i].key,  6),
                                                        hex_digit(input[i].key,  7),
                                                        hex_digit(input[i].key,  8),
                                                        hex_digit(input[i].key,  9),
                                                        hex_digit(input[i].key, 10),
                                                        hex_digit(input[i].key, 11),
                                                        hex_digit(input[i].key, 12),
                                                        hex_digit(input[i].key, 13),
                                                        hex_digit(input[i].key, 14),
                                                        hex_digit(input[i].key, 15) } };

  return formated_input_data;
}

void count_sort_by_hex_digit(size_t input_length,RadixItem* input,uint16_t digit) {
  // 1. Counting input keys :
  /* We are sorting hex digits on a uint16_t key, so the input_count count ...
   * ... array has to be of length 16. */
  uint16_t input_count[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  for (size_t i = 0; i < input_length; ++i)
    input_count[input[i].digits[digit]] += 1;

  // 2. Stacking counts :
  for (size_t i = 1; i < 16; ++i)
    input_count[i] += input_count[i-1];

  // 3. Actually sorting :
  RadixItem* output = (RadixItem*)calloc(input_length, sizeof(RadixItem));
  for (ssize_t i = input_length - 1; i >= 0; i -= 1) {
    uint16_t key = input[i].digits[digit];
    input_count[key] -= 1;
    output[input_count[key]] = input[i];
  }

  for (size_t i = 0; i < input_length; ++i)
    input[i] = output[i];

  free(output);
}

Data* radix_sort(size_t input_length,Data *input) {
  RadixItem* formated_input = format_input_data(input_length, input);

  for (size_t i = 0; i < 16; ++i)
    count_sort_by_hex_digit(input_length, formated_input, i);

  Data* output = (Data*)calloc(input_length, sizeof(Data));
  for (size_t i = 0; i < input_length; ++i)
    output[i] = *(formated_input[i].data);

  return output;
}
