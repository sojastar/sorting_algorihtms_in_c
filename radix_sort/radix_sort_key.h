#include "data_struct.h"

/* ---=== Intermediate Data Structure : ===--- */
typedef struct RadixItem {
  Data*     data;
  uint8_t   digits[16];
} RadixItem;





/* ---=== Function Prototypes : ===--- */
uint8_t     hex_digit(uint16_t n, uint16_t digit);
RadixItem*  format_input_data(size_t input_length,Data* input);
void        count_sort_by_hex_digit(size_t input_length,RadixItem* input,uint16_t digit);
Data*       radix_sort(size_t input_length,Data *input);
