#include <sys/stat.h>
#include <wasi/core.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>

int main()
{

  const char path[] = "/Users/yiruwang/Documents/202/build/project";
  size_t path_len = strlen(path);
  __wasi_fd_t fd;

  __wasi_errno_t error_mkdirat = __wasi_path_create_directory(fd,path,path_len);

  printf("mkdir error = %hu\n",error_mkdirat);
  printf("fd = %u\n",fd);
  printf("openat error = %hu\n",error_mkdirat);

  return 0;
}
