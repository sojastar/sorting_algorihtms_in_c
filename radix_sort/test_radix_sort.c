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

void test_count_sort_by_hex_digit(void) {
  uint16_t input_length     = 3;
  uint16_t input_data[]     = { 29, 4, 385 };

  count_sort_by_hex_digit(input_length, input_data, 0);

  TEST_ASSERT_EQUAL_UINT16(385, input_data[0]);
  TEST_ASSERT_EQUAL_UINT16(  4, input_data[1]);
  TEST_ASSERT_EQUAL_UINT16( 29, input_data[2]);

  count_sort_by_hex_digit(input_length, input_data, 1);

  TEST_ASSERT_EQUAL_UINT16(  4, input_data[0]);
  TEST_ASSERT_EQUAL_UINT16( 29, input_data[1]);
  TEST_ASSERT_EQUAL_UINT16(385, input_data[2]);
}

void test_radix_sort(void) {
  uint16_t input_length     = 8;
  uint16_t input_data[]     = { 170, 45, 75, 90, 802, 24, 2, 66 };

  radix_sort(input_length, input_data);

  TEST_ASSERT_EQUAL_UINT16(  2, input_data[0]);
  TEST_ASSERT_EQUAL_UINT16( 24, input_data[1]);
  TEST_ASSERT_EQUAL_UINT16( 45, input_data[2]);
  TEST_ASSERT_EQUAL_UINT16( 66, input_data[3]);
  TEST_ASSERT_EQUAL_UINT16( 75, input_data[4]);
  TEST_ASSERT_EQUAL_UINT16( 90, input_data[5]);
  TEST_ASSERT_EQUAL_UINT16(170, input_data[6]);
  TEST_ASSERT_EQUAL_UINT16(802, input_data[7]);
}





/*******************************************************************************
 * Main :
 ******************************************************************************/
int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_hex_digit);
  RUN_TEST(test_count_sort_by_hex_digit);
  RUN_TEST(test_radix_sort);

  return UNITY_END();
}
