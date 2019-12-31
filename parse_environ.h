#pragma once

#include <sys/uio.h>

typedef int (*parse_environ_consumer)(void* parameter, const struct iovec key, const struct iovec val);

int parse_environ_iovec(const struct iovec environ, void* parameter, parse_environ_consumer c, struct iovec key, struct iovec val){
  key.iov_len = 0;
  val.iov_len = 0;
  c(parameter, key, val);
  return 0;
}
