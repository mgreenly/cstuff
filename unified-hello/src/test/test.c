#include "unity.h"

void setUp(void) {
  // set stuff up here
}

void tearDown(void) {
  // clean stuff up here
}

void expect_foo_1_2_returns_3(void) {
    TEST_ASSERT_EQUAL(3, foo(1, 2));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(expect_foo_1_2_returns_3);

    return UNITY_END();
}
