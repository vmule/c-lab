#include<limits.h>
#include<string.h>
#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
#include<errno.h>

int main(void) {

  struct dirent* folder_struct;
  char dir_path[4097];
  char newfile_htm[4097];
  char oldfile[4097];
  DIR *dir;

  printf("Enter Folder path: ");
  scanf("%s", dir_path);
  if (dir_path[(strlen(dir_path)/sizeof(char) != '/')]) {
    strcat(dir_path, "/");
    printf("Full path: %s\n", dir_path);
  }

  dir = opendir(dir_path);
  if (dir == NULL) {
    perror("opendir: ");
    exit(1);
  }

  while ((folder_struct = readdir(dir))) {
    if (folder_struct->d_type == DT_DIR) {
      continue;
    }
    strcpy(oldfile, dir_path);
    strcat(oldfile, folder_struct->d_name);

    char *token  = strtok(folder_struct->d_name, ".");
    strcpy(newfile_htm, dir_path);
    strcat(newfile_htm, token);
    strcat(newfile_htm, ".htm");

    int k = rename(oldfile, newfile_htm);
    if (k == -1) {
      perror("rename:");
      exit(1);
    }
    printf("OLDFILE: %s, ", oldfile);
    printf("NEWFILE: %s\n", newfile_htm);
    memset(newfile_htm, 0, 0);
    memset(oldfile, 0, 0);
  }
  exit(0);
}
