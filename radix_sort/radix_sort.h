#include "data_struct.h"

/* ---=== Intermediate Data Structure : ===--- */
typedef struct RadixItem {
  uint16_t  n;
  uint8_t   digits[16];
} RadixItem;





/* ---=== Function Prototypes : ===--- */
uint8_t     hex_digit(uint16_t n, uint16_t digit);
RadixItem*  format_input_data(size_t input_length,uint16_t* input);
void        count_sort_by_hex_digit(size_t input_length,RadixItem* input,uint16_t digit);
uint16_t*   radix_sort(size_t input_length,uint16_t *input);
