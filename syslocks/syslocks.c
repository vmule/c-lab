#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(void) {

  FILE *fd = fopen("/proc/locks", "r");
  char line[100];
  int i;
  char *tmp;
  char pid[100];
  char *inode;

  printf("Current LOCKS:\n");

  while (fgets(line, 100, fd) != NULL) {
    tmp = strtok(line, " ");
    for (i = 0; i < 4; i++) {
      tmp = strtok(NULL, " ");
    }
    strncpy(pid, tmp, strlen(tmp) + 1);
    while (i < 7) {
      tmp = strtok(NULL, ":");
      i++;
    }
    inode = strtok(tmp, " ");
  
   char proc_path[4097] = "/proc/";
   strcat(proc_path, pid);
   strcat(proc_path, "/fd/");
  
    struct dirent** namelist;
    char file[PATH_MAX+1];
    int entries;
    struct stat file_stat;
    char link_path[4097];
    entries = scandir(proc_path, &namelist, NULL, NULL);
    if (entries < 1) {
      perror("scandir");
    } else {
        for (i = 0; i < entries; i++) {
          strcpy(link_path, proc_path);
          strcat(link_path, namelist[i]->d_name);
          int spa = stat(link_path, &file_stat);
          int ino = file_stat.st_ino;
          if (spa == -1) {
            perror("stat");
          }
          if (ino == atoi(inode))   {
            readlink(link_path, file, PATH_MAX-1);
            printf("pid: %s file: %s\n", pid, file);
          }
        memset(&link_path[0], 0, sizeof(link_path));
        }
      }
  }
  return 0;
}
