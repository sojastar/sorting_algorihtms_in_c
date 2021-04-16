#include <stdlib.h>
#include <stdio.h>
#include "merge_sort_key.h"

/* ---=== Function Declarations : ===--- */
void merge_sort_key(Data** input,size_t left, size_t right) {
  if (right - left > 0) {
    size_t middle = left + ( right - left ) / 2;
    merge_sort_key(input, left, middle);
    merge_sort_key(input,       middle + 1, right);

    merge(input, left, middle, right);
  }
}

void merge(Data** input,size_t left,size_t middle,size_t right) {
  size_t left_index   = left;
  size_t right_index  = middle + 1;
  size_t buffer_index = 0;

  Data** buffer = (Data**)malloc((right - left + 1) * sizeof(Data*));

  while ((left_index <= middle) && (right_index <= right)) {
    if (input[left_index]->key <= input[right_index]->key) {
      buffer[buffer_index] = input[left_index];
      left_index   += 1;
    }
    else {
      buffer[buffer_index] = input[right_index];
      right_index  += 1;
    }
    buffer_index += 1;
  }

  if (left_index > middle) {
    for (size_t i = right_index; i <= right; i++)
      buffer[i - right_index + buffer_index] = input[i]; 
  }
  else {
    for (size_t i = left_index; i <= middle; i++)
      buffer[i - left_index + buffer_index] = input[i]; 
  }

  for (size_t i = 0; i < right - left + 1; i++)
    input[i + left] = buffer[i];
 
  free(buffer);
}
