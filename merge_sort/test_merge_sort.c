#include <stdlib.h>
#include "unity.h"
#include "merge_sort.h"

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
void test_merge(void) {
  uint16_t  only_two[]  = { 3, 1 };

  merge(only_two, 0, 0, 1);

  TEST_ASSERT_EQUAL_UINT16(1, only_two[0]);
  TEST_ASSERT_EQUAL_UINT16(3, only_two[1]);

  uint16_t  even[]      = { 2, 9, 4, 6 };

  merge(even, 0, 1, 3);

  TEST_ASSERT_EQUAL_UINT16(2, even[0]);
  TEST_ASSERT_EQUAL_UINT16(4, even[1]);
  TEST_ASSERT_EQUAL_UINT16(6, even[2]);
  TEST_ASSERT_EQUAL_UINT16(9, even[3]);

  uint16_t  uneven_left[]    = { 2, 9, 4, 5, 7 };

  merge(uneven_left, 0, 1, 4);

  TEST_ASSERT_EQUAL_UINT16(2, uneven_left[0]);
  TEST_ASSERT_EQUAL_UINT16(4, uneven_left[1]);
  TEST_ASSERT_EQUAL_UINT16(5, uneven_left[2]);
  TEST_ASSERT_EQUAL_UINT16(7, uneven_left[3]);
  TEST_ASSERT_EQUAL_UINT16(9, uneven_left[4]);

  uint16_t  uneven_right[]    = { 2, 5, 9, 4, 7 };

  merge(uneven_right, 0, 2, 4);

  TEST_ASSERT_EQUAL_UINT16(2, uneven_right[0]);
  TEST_ASSERT_EQUAL_UINT16(4, uneven_right[1]);
  TEST_ASSERT_EQUAL_UINT16(5, uneven_right[2]);
  TEST_ASSERT_EQUAL_UINT16(7, uneven_right[3]);
  TEST_ASSERT_EQUAL_UINT16(9, uneven_right[4]);
}

void test_merge_sort(void) {

  // Empty arrays :
  uint16_t empty[0];

  merge_sort(empty, 0, 0);


  // Single element arrays :
  uint16_t only_one[] = { 19 };

  merge_sort(only_one, 0, 0);

  TEST_ASSERT_EQUAL_UINT16(19, only_one[0]);


  // Two elements arrays :
  uint16_t two_sorted[]  = { 1, 73 };

  merge_sort(two_sorted, 0, 1);

  TEST_ASSERT_EQUAL_UINT16( 1, two_sorted[0]);
  TEST_ASSERT_EQUAL_UINT16(73, two_sorted[1]);

  uint16_t two_unsorted[]  = { 73, 1 };

  merge_sort(two_unsorted, 0, 1);

  TEST_ASSERT_EQUAL_UINT16( 1, two_unsorted[0]);
  TEST_ASSERT_EQUAL_UINT16(73, two_unsorted[1]);


  // Three elements arrays :
  uint16_t three[]  = { 1, 73, 42 };

  merge_sort(three, 0, 2);

  TEST_ASSERT_EQUAL_UINT16( 1, three[0]);
  TEST_ASSERT_EQUAL_UINT16(42, three[1]);
  TEST_ASSERT_EQUAL_UINT16(73, three[2]);


  // Larger arrays :
  uint16_t even[] = { 170, 45, 75, 90, 802, 24, 2, 66 };

  merge_sort(even, 0, 7);

  TEST_ASSERT_EQUAL_UINT16(  2, even[0]);
  TEST_ASSERT_EQUAL_UINT16( 24, even[1]);
  TEST_ASSERT_EQUAL_UINT16( 45, even[2]);
  TEST_ASSERT_EQUAL_UINT16( 66, even[3]);
  TEST_ASSERT_EQUAL_UINT16( 75, even[4]);
  TEST_ASSERT_EQUAL_UINT16( 90, even[5]);
  TEST_ASSERT_EQUAL_UINT16(170, even[6]);
  TEST_ASSERT_EQUAL_UINT16(802, even[7]);

  uint16_t uneven[] = { 170, 529, 45, 75, 90, 802, 24, 2, 66 };

  merge_sort(uneven, 0, 8);

  TEST_ASSERT_EQUAL_UINT16(  2, uneven[0]);
  TEST_ASSERT_EQUAL_UINT16( 24, uneven[1]);
  TEST_ASSERT_EQUAL_UINT16( 45, uneven[2]);
  TEST_ASSERT_EQUAL_UINT16( 66, uneven[3]);
  TEST_ASSERT_EQUAL_UINT16( 75, uneven[4]);
  TEST_ASSERT_EQUAL_UINT16( 90, uneven[5]);
  TEST_ASSERT_EQUAL_UINT16(170, uneven[6]);
  TEST_ASSERT_EQUAL_UINT16(529, uneven[7]);
  TEST_ASSERT_EQUAL_UINT16(802, uneven[8]);
}





/*******************************************************************************
 * Main :
 ******************************************************************************/
int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_merge);
  RUN_TEST(test_merge_sort);

  return UNITY_END();
}
