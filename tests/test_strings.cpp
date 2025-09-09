#include <string>
#include "test_util.hpp"
#include "megakit/algo/kmp.hpp"

TEST_CASE(test_kmp_find){
  auto pos = megakit::algo::kmp_search("ababcabcabababd", "ababd");
  REQUIRE(!pos.empty());
  REQUIRE(pos[0] == 10);
}
