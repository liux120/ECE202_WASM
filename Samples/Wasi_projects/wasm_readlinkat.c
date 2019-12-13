#include <sys/stat.h>
#include <wasi/core.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
int main(){
  __wasi_fd_t fd;
  const char path[] = "/Users/yiruwang/Documents/202/build/project";
  size_t path_len = strlen(path);
  char buf[64];
  size_t buf_len = strlen(buf);
  size_t bufused;
  __wasi_errno_t error = __wasi_path_readlink(fd, path, path_len, buf, buf_len,&bufused);
  printf("error = %hu\n",error);

}
