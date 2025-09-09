#include "test_util.hpp"
#include "megakit/math/gcd.hpp"
#include "megakit/math/sieve.hpp"

TEST_CASE(test_gcd_lcm){
  using megakit::math::gcd; using megakit::math::lcm;
  REQUIRE(gcd(24,36) == 12);
  REQUIRE(lcm(4,6) == 12);
}

TEST_CASE(test_sieve){
  auto p = megakit::math::sieve(20);
  REQUIRE(p.size() == 8); // 2,3,5,7,11,13,17,19
}
