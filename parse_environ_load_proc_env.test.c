#include "parse_environ.h"

int sub(const char* testfile){
  FILE* environ = fopen(testfile, "rb");
  if(NULL == environ) return printf("Unable to open environ file: %s\n", testfile);
  char buf[1048576] = {0};
  size_t read_bytes = parse_environ_load_proc_env(environ, buf, 1048575);
  switch(read_bytes){
    case 29: break;
    default:
      printf("expected read bytes: %ld, actual: %ld\n", read_bytes, read_bytes);
      fclose(environ);
      return -1;
  }
  switch(strncmp(buf, "LANG=en_US.UTF-8\0TERM=screen\0", 29)){
    case 0: break;
    default:
      printf("expected buf: %s, actual: %s\n", "LANG=en_US.UTF-8\0TERM=screen", buf);
      fclose(environ);
      return -1;
  }
  fclose(environ);
  return 0;
}

int main(int argc, char** argv){
  switch(argc){
    case 2:  return sub(argv[1]);
    default: return sub("./.test/environ");
  }
}
