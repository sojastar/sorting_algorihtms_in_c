#include <stdlib.h>
#include "unity.h"
#include "radix_sort.h"

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
void test_hex_digit(void) {
  uint16_t n = 923;
  
  TEST_ASSERT_EQUAL_UINT8(11, hex_digit(n, 0));
  TEST_ASSERT_EQUAL_UINT8( 9, hex_digit(n, 1));
  TEST_ASSERT_EQUAL_UINT8( 3, hex_digit(n, 2));
}

void test_format_input_data(void) {
  uint16_t input_length = 3;
  uint16_t input_data[] = { 29, 4, 385 };

  RadixItem* formated_input  = format_input_data(input_length, input_data);

  TEST_ASSERT_EQUAL_UINT16( 29, formated_input[0].n);
  TEST_ASSERT_EQUAL_UINT8(  13, formated_input[0].digits[0]);
  TEST_ASSERT_EQUAL_UINT8(   1, formated_input[0].digits[1]);
  TEST_ASSERT_EQUAL_UINT8(   0, formated_input[0].digits[2]);

  TEST_ASSERT_EQUAL_UINT16(  4, formated_input[1].n);
  TEST_ASSERT_EQUAL_UINT8(   4, formated_input[1].digits[0]);
  TEST_ASSERT_EQUAL_UINT8(   0, formated_input[1].digits[1]);

  TEST_ASSERT_EQUAL_UINT16(385, formated_input[2].n);
  TEST_ASSERT_EQUAL_UINT8(   1, formated_input[2].digits[0]);
  TEST_ASSERT_EQUAL_UINT8(   8, formated_input[2].digits[1]);
  TEST_ASSERT_EQUAL_UINT8(   1, formated_input[2].digits[2]);
  TEST_ASSERT_EQUAL_UINT8(   0, formated_input[2].digits[3]);

  free(formated_input);
}

void test_count_sort_by_hex_digit(void) {
  uint16_t input_length     = 3;
  uint16_t input_data[]     = { 29, 4, 385 };
  RadixItem* formated_input = format_input_data(input_length, input_data);

  count_sort_by_hex_digit(input_length, formated_input, 0);

  TEST_ASSERT_EQUAL_UINT16(385, formated_input[0].n);
  TEST_ASSERT_EQUAL_UINT16(  4, formated_input[1].n);
  TEST_ASSERT_EQUAL_UINT16( 29, formated_input[2].n);

  count_sort_by_hex_digit(input_length, formated_input, 1);

  TEST_ASSERT_EQUAL_UINT16(  4, formated_input[0].n);
  TEST_ASSERT_EQUAL_UINT16( 29, formated_input[1].n);
  TEST_ASSERT_EQUAL_UINT16(385, formated_input[2].n);

  free(formated_input);
}

void test_radix_sort(void) {
  uint16_t input_length     = 8;
  uint16_t input_data[]     = { 170, 45, 75, 90, 802, 24, 2, 66 };
  RadixItem* formated_input = format_input_data(input_length, input_data);

  uint16_t* output  = radix_sort(input_length, input_data);

  TEST_ASSERT_EQUAL_UINT16(  2, output[0]);
  TEST_ASSERT_EQUAL_UINT16( 24, output[1]);
  TEST_ASSERT_EQUAL_UINT16( 45, output[2]);
  TEST_ASSERT_EQUAL_UINT16( 66, output[3]);
  TEST_ASSERT_EQUAL_UINT16( 75, output[4]);
  TEST_ASSERT_EQUAL_UINT16( 90, output[5]);
  TEST_ASSERT_EQUAL_UINT16(170, output[6]);
  TEST_ASSERT_EQUAL_UINT16(802, output[7]);

  free(output);
}





/*******************************************************************************
 * Main :
 ******************************************************************************/
int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_hex_digit);
  RUN_TEST(test_format_input_data);
  RUN_TEST(test_count_sort_by_hex_digit);
  RUN_TEST(test_radix_sort);

  return UNITY_END();
}
