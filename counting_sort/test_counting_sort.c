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

  uint16_t* output  = counting_sort(input_length, input_data);

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

  RUN_TEST(test_counting_sort);

  return UNITY_END();
}
