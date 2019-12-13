# include <wasi/core.h>
# include <stdio.h>

int main(){
  __wasi_clockid_t clock_id = __WASI_CLOCK_THREAD_CPUTIME_ID;
  __wasi_timestamp_t precision = 10;
  __wasi_timestamp_t start;
  __wasi_timestamp_t end;
  __wasi_timestamp_t resolution;
  __wasi_fd_t fd;
  __wasi_filestat_t buf;

  __wasi_clock_time_get(clock_id,precision,&start);
  __wasi_clock_res_get(clock_id,&resolution);
  __wasi_clock_time_get(clock_id,precision,&end);
  __wasi_fd_filestat_get(fd,&buf);

  printf("start = %llu\n", start);
  printf("end = %llu\n", end);
  printf("time = %llu\n", end-start);
  printf("resolution = %llu\n", resolution);

  printf("file = %u\n", fd);
  printf("file type = %hhu\n", buf.st_filetype);
  printf("file serial number = %llu\n", buf.st_ino);
}
