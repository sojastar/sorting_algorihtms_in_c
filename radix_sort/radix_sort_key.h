#include "data_struct.h"

/* ---=== Function Prototypes : ===--- */
uint8_t hex_digit(uint16_t n, uint16_t digit);
void    count_sort_by_hex_digit(size_t input_length,Data** input,uint16_t digit);
void    radix_sort(size_t input_length,Data **input);
