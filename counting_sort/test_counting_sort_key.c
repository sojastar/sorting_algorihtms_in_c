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

  counting_sort_key(input_length, input_data);

  TEST_ASSERT_EQUAL_UINT16(        2, input_data[0]->key);
  TEST_ASSERT_EQUAL_STRING("string7", input_data[0]->data);

  TEST_ASSERT_EQUAL_UINT16(       24, input_data[1]->key);
  TEST_ASSERT_EQUAL_STRING("string6", input_data[1]->data);

  TEST_ASSERT_EQUAL_UINT16(       45, input_data[2]->key);
  TEST_ASSERT_EQUAL_STRING("string2", input_data[2]->data);

  TEST_ASSERT_EQUAL_UINT16(       66, input_data[3]->key);
  TEST_ASSERT_EQUAL_STRING("string8", input_data[3]->data);

  TEST_ASSERT_EQUAL_UINT16(       75, input_data[4]->key);
  TEST_ASSERT_EQUAL_STRING("string3", input_data[4]->data);

  TEST_ASSERT_EQUAL_UINT16(       90, input_data[5]->key);
  TEST_ASSERT_EQUAL_STRING("string4", input_data[5]->data);

  TEST_ASSERT_EQUAL_UINT16(      170, input_data[6]->key);
  TEST_ASSERT_EQUAL_STRING("string1", input_data[6]->data);

  TEST_ASSERT_EQUAL_UINT16(      802, input_data[7]->key);
  TEST_ASSERT_EQUAL_STRING("string5", input_data[7]->data);
}





/*******************************************************************************
 * Main :
 ******************************************************************************/
int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_counting_sort_key);

  return UNITY_END();
}
