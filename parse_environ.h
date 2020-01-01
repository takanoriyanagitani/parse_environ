#pragma once

#include <stdint.h>

#include <string.h>

typedef int (*parse_environ_kv_consumer)(void* param, const char* kvpair);

int parse_environ_get_next_kv(const char* env, uint32_t offset, char* buf, uint32_t len, void* param, parse_environ_kv_consumer c){
  strncpy(buf, env+offset, len);
  return strlen(buf);
}
