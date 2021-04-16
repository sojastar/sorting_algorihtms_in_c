#include <stdlib.h>
#include "unity.h"
#include "counting_sort.h"

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
void test_counting_sort(void) {
  uint16_t input_length     = 8;
  uint16_t input_data[]     = { 170, 45, 75, 90, 802, 24, 2, 66 };

  counting_sort(input_length, input_data);

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

  RUN_TEST(test_counting_sort);

  return UNITY_END();
}
