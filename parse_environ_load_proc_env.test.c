#include "parse_environ.h"

int sub(const char* testfile){
  FILE* environ = fopen(testfile, "rb");
  if(NULL == environ) return printf("Unable to open environ file: %s\n", testfile);
  char buf[1048576] = {0};
  size_t read_bytes = parse_environ_load_proc_env(environ, buf, 1048575);
  if(29 != read_bytes) return fclose(environ)*0 + printf("expected read bytes: %d, actual: %ld\n", 29, read_bytes);
  if(0 != memcmp(buf, "LANG=en_US.UTF-8\0TERM=screen\0", 29)) return fclose(environ)*0 + printf("Unexpected string: %s\n", buf);
  fclose(environ);
  return 0;
}

int main(int argc, char** argv){
  switch(argc){
    case 2:  return sub(argv[1]);
    default: return sub("./.test/environ");
  }
}
