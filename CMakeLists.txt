cmake_minimum_required (VERSION 3.10.2)
project (PARSE_ENVIRON)

include (CTest)

add_executable (parse_environ_get_next_kv.test   parse_environ_get_next_kv.test.c)
add_executable (parse_environ_load_proc_env.test parse_environ_load_proc_env.test.c)

target_compile_options(parse_environ_get_next_kv.test INTERFACE
  -O0
  -g
  --coverage
  -fprofile-arcs
  -ftest-coverage
)

target_compile_options(parse_environ_load_proc_env.test INTERFACE
  -O0
  -g
  --coverage
  -fprofile-arcs
  -ftest-coverage
)

if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.13)
  target_link_options(parse_environ_get_next_kv.test   INTERFACE --coverage)
  target_link_options(parse_environ_load_proc_env.test INTERFACE --coverage)
else()
  target_link_libraries(parse_environ_get_next_kv.test   INTERFACE --coverage)
  target_link_libraries(parse_environ_load_proc_env.test INTERFACE --coverage)
endif()

enable_testing()

add_test (parse_environ_get_next_kv   parse_environ_get_next_kv.test)
add_test (parse_environ_load_proc_env parse_environ_load_proc_env.test)
