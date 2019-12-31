cmake_minimum_required (VERSION 2.8.11)
project (PARSE_ENVIRON)

include (CTest)

add_executable (parse_environ_iovec.test parse_environ_iovec.test.c)

add_test (parse_environ_iovec parse_environ_iovec.test)
