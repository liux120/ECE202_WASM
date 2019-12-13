#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/uio.h>
#include <wasi/core.h>

int main ()
{
        //struct iovec iov[3];
        struct __wasi_ciovec_t iov[3];

        size_t nr;
        __wasi_fd_t fd;
        int i;

        char *buf[] = {
                "The term buccaneer comes from the word boucan.\n",
                "A boucan is a wooden frame used for cooking meat.\n",
                "Buccaneer is the West Indies name for a pirate.\n" };
        char path[] = "/Users/yiruwang/Documents/202/build/project/write.txt";
        
        fd = open("/Users/yiruwang/Documents/202/build/project/write.txt",O_WRONLY | O_CREAT | O_TRUNC);


        /* fill out three iovec structures */
        for (i = 0; i < 3; i++) {
                iov[i].buf = buf[i];
                iov[i].buf_len = strlen(buf[i]) + 1;
        }
        /* with a single call, write them all out */
        __wasi_fd_write (fd, iov, 3, &nr);

        printf ("wrote %zd bytes\n", nr);

        return 0;
}
