#include<limits.h>
#include<string.h>
#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>

int main(void) {

  struct dirent** folder_struct;
  char folder[4097];
  char newfile_htm[4097];
  char oldfile[4097];

  printf("Enter Folder :");
  scanf("%s", folder);
  if (folder[(strlen(folder)/sizeof(char) != '/')]) {
    strcat(folder, "/");
    printf("Full path: %s\n", folder);
  }

  int entries;
  entries = scandir(folder, &folder_struct, NULL, NULL);
  int i;
  for (i = 0; i < entries; i++) {
    if (folder_struct[i]->d_type == DT_DIR) {
      continue;
    }
    strcpy(oldfile, folder);
    strcat(oldfile, folder_struct[i]->d_name);

    char *token  = strtok(folder_struct[i]->d_name, ".");
    strcpy(newfile_htm, folder);
    strcat(newfile_htm, token);
    strcat(newfile_htm, ".htm");

    int k = rename(oldfile, newfile_htm);
    if (k == -1) {
      perror("rename:");
    }
    printf("OLDFILE: %s, ", oldfile);
    printf("NEWFILE: %s\n", newfile_htm);
    memset(newfile_htm, 0, 0);
    memset(oldfile, 0, 0);
  }
  return 0;
}
