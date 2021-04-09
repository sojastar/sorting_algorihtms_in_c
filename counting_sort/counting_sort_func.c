#include <stdlib.h>
#include <stdio.h>

/* ---=== Function Prototype : ===--- */
uint16_t* count_sort(size_t input_range,size_t input_length,uint16_t* input);





/* ---=== Main : ===--- */
int main(int argc, char** argv) {

  if (argc <= 1) {
    printf("There was no input. Aborting.\n");
    return -1;
  }
    

  // 1. Formating input data :
  uint16_t  input_length  = argc - 1;
  uint16_t* input         = (uint16_t*)malloc(input_length * sizeof(uint16_t));

  for (size_t i = 0; i < input_length; ++i)
    input[i] = atoi(argv[i+1]);

  uint16_t input_max  = 0;
  for (size_t i = 0; i < input_length; i++)
    if (input[i] > input_max)
      input_max = input[i];

  printf("input: ( ");
  for (size_t i = 0; i < input_length; ++i)
    printf("%hu ", input[i]);
  printf(")\ninput length: %hu\ninput range: %hu\n", input_length, input_max);


  // 2. Sorting :
  uint16_t* output = count_sort(input_max + 1, input_length, input);


  // 3. Print output :
  printf("output: ( ");
  for(size_t i = 0; i < input_length; ++i)
    printf("%hu ", output[i]);
  printf(")\n");


  // 4. Cleanup :
  free(input);
  free(output);

  return 0;
}





/* ---=== Function Declaration : ===--- */
uint16_t* count_sort(size_t input_range,size_t input_length,uint16_t* input) {
  // 1. Counting input keys :
  uint16_t* input_count = (uint16_t*)malloc(input_range * sizeof(uint16_t));
  for(size_t i = 0; i < input_length; ++i)
    input_count[input[i]] += 1;

  // 2. Stacking counts :
  for(size_t i = 1; i < input_range; ++i)
    input_count[i] += input_count[i-1];

  // 3. Actually sorting :
  uint16_t* output = (uint16_t*)malloc(input_length * sizeof(uint16_t));
  for (ssize_t i = input_length - 1; i >= 0; --i) {
    uint16_t key = input[i];
    input_count[key] -= 1;
    output[input_count[key]] = key;
  }

  free(input_count);

  return output;
}
