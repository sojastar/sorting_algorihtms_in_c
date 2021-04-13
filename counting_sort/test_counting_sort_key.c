#include <stdlib.h>
#include "unity.h"
#include "counting_sort_key.h"

/*******************************************************************************
 * Setup and Teardown :
 ******************************************************************************/
void setUp(void) {
  // set stuff up here
}

void tearDown(void) {
  // clean stuff up here
}





/*******************************************************************************
 * Test Suit :
 ******************************************************************************/
void test_counting_sort_key(void) {
  size_t  input_length  =  8;
  Data    input1        = { .key  = 170,  .data = "string1" };
  Data    input2        = { .key  = 45,   .data = "string2" };
  Data    input3        = { .key  = 75,   .data = "string3" };
  Data    input4        = { .key  = 90,   .data = "string4" };
  Data    input5        = { .key  = 802,  .data = "string5" };
  Data    input6        = { .key  = 24,   .data = "string6" };
  Data    input7        = { .key  = 2,    .data = "string7" };
  Data    input8        = { .key  = 66,   .data = "string8" };
  Data*  input_data[]   = { &input1,
                            &input2,
                            &input3,
                            &input4,
                            &input5,
                            &input6,
                            &input7,
                            &input8 };

  Data**  output  = (Data**)calloc(input_length, sizeof(Data*));
  counting_sort_key(input_length, input_data, output);

  TEST_ASSERT_EQUAL_UINT16(        2, output[0]->key);
  TEST_ASSERT_EQUAL_STRING("string7", output[0]->data);

  TEST_ASSERT_EQUAL_UINT16(       24, output[1]->key);
  TEST_ASSERT_EQUAL_STRING("string6", output[1]->data);

  TEST_ASSERT_EQUAL_UINT16(       45, output[2]->key);
  TEST_ASSERT_EQUAL_STRING("string2", output[2]->data);

  TEST_ASSERT_EQUAL_UINT16(       66, output[3]->key);
  TEST_ASSERT_EQUAL_STRING("string8", output[3]->data);

  TEST_ASSERT_EQUAL_UINT16(       75, output[4]->key);
  TEST_ASSERT_EQUAL_STRING("string3", output[4]->data);

  TEST_ASSERT_EQUAL_UINT16(       90, output[5]->key);
  TEST_ASSERT_EQUAL_STRING("string4", output[5]->data);

  TEST_ASSERT_EQUAL_UINT16(      170, output[6]->key);
  TEST_ASSERT_EQUAL_STRING("string1", output[6]->data);

  TEST_ASSERT_EQUAL_UINT16(      802, output[7]->key);
  TEST_ASSERT_EQUAL_STRING("string5", output[7]->data);

  free(output);
}





/*******************************************************************************
 * Main :
 ******************************************************************************/
int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_counting_sort_key);

  return UNITY_END();
}
