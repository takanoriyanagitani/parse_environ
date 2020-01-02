#pragma once

#include <stdio.h>
#include <stdint.h>

#include <string.h>

typedef int (*parse_environ_kv_consumer)(void* param, const char* kvpair);

int parse_environ_get_next_kv(const char* env, uint32_t offset, char* buf, uint32_t len, void* param, parse_environ_kv_consumer c){
  strncpy(buf, env+offset, len);
  return strlen(buf);
}

size_t parse_environ_load_proc_env(FILE* environ, char* buf, const uint32_t len){
  memset(buf, 0, len);
  return fread(buf, 1, len-1, environ);
}
