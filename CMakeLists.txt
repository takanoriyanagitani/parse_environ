cmake_minimum_required (VERSION 2.8.11)
project (PARSE_ENVIRON)

include (CTest)

add_test (parse_environ_iovec parse_environ_iovec.test)
