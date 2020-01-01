cmake_minimum_required (VERSION 3.10.2)
project (PARSE_ENVIRON)

include (CTest)

add_executable (parse_environ_get_next_kv.test parse_environ_get_next_kv.test.c)

target_compile_options(parse_environ_get_next_kv.test INTERFACE
  -O0
  -g
  --coverage
  -fprofile-arcs
  -ftest-coverage
)

if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.13)
  target_link_options(parse_environ_get_next_kv.test INTERFACE --coverage)
else()
  target_link_libraries(parse_environ_get_next_kv.test INTERFACE --coverage)
endif()

enable_testing()

add_test (parse_environ_get_next_kv parse_environ_get_next_kv.test)
