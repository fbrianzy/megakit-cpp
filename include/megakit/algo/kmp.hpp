#pragma once
#include <string>
#include <vector>

namespace megakit::algo {
  inline std::vector<int> kmp_prefix(const std::string& s) {
    std::vector<int> pi(s.size(), 0);
    for (size_t i=1; i<s.size(); ++i) {
      int j = pi[i-1];
      while (j>0 && s[i]!=s[j]) j = pi[j-1];
      if (s[i]==s[j]) ++j;
      pi[i] = j;
    }
    return pi;
  }

  inline std::vector<int> kmp_search(const std::string& text, const std::string& pat) {
    if (pat.empty()) return {};
    std::string t = pat + "#" + text;
    auto pi = kmp_prefix(t);
    std::vector<int> pos;
    for (size_t i=pat.size()+1; i<t.size(); ++i) {
      if (pi[i] == (int)pat.size()) pos.push_back((int)i - 2*(int)pat.size());
    }
    return pos;
  }
}
