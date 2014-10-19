#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
   int fd = open("/dev/tun0", O_RDONLY);
    if (fd < 0)
     {
        printf("Failed to open tun/tap device. Are you root? Are the drivers installed?\n");
         return -1;
      }
     while (1)
      {
         sleep(100000);
       }
      return 0;
}
