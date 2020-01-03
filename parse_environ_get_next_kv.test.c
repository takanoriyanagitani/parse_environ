#include "parse_environ.h"

#include <stdio.h>

int sub(const char* environ){
  char buf[1048576] = {0};
  int kvlen = 0;

  uint32_t offset = 0;
  kvlen = parse_environ_get_next_kv(environ, offset, buf, 1048576, NULL, NULL);
  if(16 != kvlen) return -1;
  if(0  != strncmp(buf, "LANG=en_US.UTF-8", kvlen)) return -1;
  offset += 1 + kvlen;

  kvlen = parse_environ_get_next_kv(environ, offset, buf, 1048576, NULL, NULL);
  if(11 != kvlen) return -1;
  if(0  != strncmp(buf, "USER=ubuntu", kvlen)) return -1;
  offset += 1 + kvlen;

  kvlen = parse_environ_get_next_kv(environ, offset, buf, 1048576, NULL, NULL);
  if(17 != kvlen) return -1;
  if(0  != strncmp(buf, "HOME=/home/ubuntu", kvlen)) return -1;
  offset += 1 + kvlen;

  kvlen = parse_environ_get_next_kv(environ, offset, buf, 1048576, NULL, NULL);
  if(11 != kvlen) return -1;
  if(0  != strncmp(buf, "TERM=screen", kvlen)) return -1;
  offset += 1 + kvlen;

  kvlen = parse_environ_get_next_kv(environ, offset, buf, 1048576, NULL, NULL);
  if(15 != kvlen) return -1;
  if(0  != strncmp(buf, "SHELL=/bin/bash", kvlen)) return -1;
  offset += 1 + kvlen;

  kvlen = parse_environ_get_next_kv(environ, offset, buf, 1048576, NULL, NULL);
  if(0 != kvlen) return -1;

  return 0;
}

int main(int argc, char** argv){
  const char environ[] = "LANG=en_US.UTF-8\0USER=ubuntu\0HOME=/home/ubuntu\0TERM=screen\0SHELL=/bin/bash\0";
  return sub(environ);
}
