#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {

  // 1. Input Data :
  uint16_t  max_input_value = 10;
  uint16_t  input_length    = 7;
  uint16_t  input[7]        = { 1, 4, 1, 2, 7, 5, 2 };

  printf("input:  ");
  for(size_t i = 0; i < input_length; ++i)
    printf("%hu ", input[i]);
  printf("\n");


  // 2. Sorting :

  // 2.1 Counting input keys :
  uint16_t  input_count[10];
  for(size_t i = 0; i < 7; ++i) {
    input_count[input[i]] += 1;
  }

  // 2.2 Stacking counts :
  for(size_t i = 1; i < 10; ++i)
    input_count[i] += input_count[i-1];

  // 2.3 Actually sorting :
  uint16_t  output[7];
  for (ssize_t i = input_length - 1; i >= 0; --i) {
    uint16_t key = input[i];
    input_count[key] -= 1;
    output[input_count[key]] = key;
    //output[--input_count[input[i]]] = input[i];
  }


  // 3. Print output :
  printf("output: ");
  for(size_t i = 0; i < input_length; ++i)
    printf("%hu ", output[i]);
  printf("\n");

  return 0;
}
