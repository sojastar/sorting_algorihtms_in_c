#include <stdlib.h>
#include <stdio.h>

/* ---=== Dummy Structure : ===--- */
typedef struct Data {
  uint16_t    key;
  const char* string;
} Data;





/* ---=== Function Prototype : ===--- */
Data** count_sort(size_t input_range,size_t input_length,Data** input);





/* ---=== Main : ===--- */
int main(int argc, char** argv) {

  // 1. Creating input data :
  Data  d1  = { 1, "string 1" };
  Data  d2  = { 4, "string 2" };
  Data  d3  = { 1, "string 3" };
  Data  d4  = { 2, "string 4" };
  Data  d5  = { 7, "string 5" };
  Data  d6  = { 5, "string 6" };
  Data  d7  = { 2, "string 7" };

  Data*   input[7]      = { &d1, &d2, &d3, &d4, &d5, &d6, &d7 };
  size_t  input_length  =  7;

  printf("- Input:\n");
  for(size_t i = 0; i < input_length; ++i)
    printf("%hu -> %s\n", input[i]->key, input[i]->string);

  uint16_t max_key = 0;
  for (size_t i = 0; i < input_length; ++i)
    if (input[i]->key > max_key)
      max_key = input[i]->key;


  // 2. Sorting :
  Data** output = count_sort(max_key + 1, input_length, input);


  // 3. Print output :
  printf("- Output:\n");
  for(size_t i = 0; i < input_length; ++i)
    printf("%hu -> %s\n", output[i]->key, output[i]->string);


  // 4. Cleanup :
  free(output);

  return 0;
}





/* ---=== Function Declaration : ===--- */
Data** count_sort(size_t input_range,size_t input_length,Data** input) {
  // 1. Counting input keys :
  uint16_t* input_count = (uint16_t*)malloc(input_range * sizeof(uint16_t));
  for(size_t i = 0; i < input_length; ++i)
    input_count[input[i]->key] += 1;

  // 2. Stacking counts :
  for(size_t i = 1; i < input_range; ++i)
    input_count[i] += input_count[i-1];

  // 3. Actually sorting :
  Data** output = (Data**)malloc(input_length * sizeof(Data*));
  for (ssize_t i = input_length - 1; i >= 0; --i) {
    uint16_t key = input[i]->key;
    input_count[key] -= 1;
    output[input_count[key]] = input[i];
  }

  free(input_count);

  return output;
}
