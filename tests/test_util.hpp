#pragma once
#include <iostream>
#include <functional>
#include <vector>
#include <string>

namespace tinytest {
  using TestFn = std::function<void()>;
  inline std::vector<std::pair<std::string, TestFn>>& registry(){
    static std::vector<std::pair<std::string, TestFn>> r; return r;
  }
  struct Reg { Reg(const std::string& n, TestFn f){ registry().push_back({n,f}); } };
  inline int run_all(){
    int failed = 0;
    for (auto& [name, fn] : registry()){
      try { fn(); std::cout << "[PASS] " << name << "\n"; }
      catch(const std::exception& e){ std::cout << "[FAIL] " << name << " : " << e.what() << "\n"; ++failed; }
      catch(...){ std::cout << "[FAIL] " << name << " : unknown\n"; ++failed; }
    }
    std::cout << registry().size() << " tests, " << failed << " failed\n";
    return failed;
  }
}

#define TEST_CASE(name) static void name(); static tinytest::Reg reg_##name(#name, name); static void name()
#define REQUIRE(cond) do { if(!(cond)) throw std::runtime_error("Requirement failed: " #cond); } while(0)
