#include "parse_environ.h"

#include <sys/uio.h>

#include <stdio.h>

#include <string.h>

int environ2json(void* parameter, const struct iovec key, const struct iovec val){
  return 0;
}

int main(int argc, char** argv){
  char keybuf[1024] = {0};
  char valbuf[1048576] = {0};
  struct iovec key = {
    keybuf,
    1024,
  };
  struct iovec val = {
    valbuf,
    1048576,
  };
  char envbuf[1048576] = {0};
  struct iovec environ = {
    envbuf,
    1048576,
  };
  strncpy(envbuf, "LANG=en_US.UTF-8\0USER=ubuntu\0HOME=/home/ubuntu\0TERM=screen\0SHELL=/bin/bash\0", 1048576);
  parse_environ_iovec(environ, NULL, environ2json, key, val);
  return 0;
}
