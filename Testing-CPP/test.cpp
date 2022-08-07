#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "test.h"
#include "doctest.h"

int factorial_test(int number) {
  return number > 1 ? factorial_test(number - 1) * number : 1;
}

TEST_CASE("it should return success when calculating factorial") {
  CHECK(factorial_test(1) == 1);
  CHECK(factorial_test(3) == 6);
  CHECK(factorial_test(10) == 3628800);
}
