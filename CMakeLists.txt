cmake_minimum_required(VERSION 3.16)
project(megakit_cpp VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(BUILD_TESTS "Build tests" ON)
option(BUILD_EXAMPLES "Build examples" ON)

# Library
file(GLOB_RECURSE MEGAKIT_SOURCES CONFIGURE_DEPENDS "src/*.cpp")
file(GLOB_RECURSE MEGAKIT_HEADERS CONFIGURE_DEPENDS "include/*.hpp")

add_library(megakit STATIC ${MEGAKIT_SOURCES} ${MEGAKIT_HEADERS})
target_include_directories(megakit PUBLIC include)
target_compile_features(megakit PUBLIC cxx_std_17)

# CLI app
add_executable(megakit_cli apps/toolkit/main.cpp)
target_link_libraries(megakit_cli PRIVATE megakit)

# Examples
if(BUILD_EXAMPLES)
  add_executable(example_graph examples/example_graph.cpp)
  target_link_libraries(example_graph PRIVATE megakit)
endif()

# Tests (simple header-only tiny framework)
include(CTest)
if(BUILD_TESTS)
  enable_testing()
  file(GLOB TEST_SOURCES CONFIGURE_DEPENDS "tests/*.cpp")
  add_executable(megakit_tests ${TEST_SOURCES})
  target_link_libraries(megakit_tests PRIVATE megakit)
  add_test(NAME run_all COMMAND megakit_tests)
endif()
