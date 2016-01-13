#include<limits.h>
#include<string.h>


int main(void) {

struct **dirent folder_struct;
char folder[] = “/var/www/”
//printf message
//scanf folder
char newfile_html[PATH_MAX +1];

scandir(folder, folder_struct);
while(folder_struct->d_name != NULL) {
   char *token strtok(folder_struct->d_name, “.”);
   //check error
   return 1;

   strncpy(newfile_html, folder, PATH_MAX);
   strncat(token, newfile_html, PATH_MAX - strlen());
   strncat(“.html”, newfile_html, (PATH_MAX - strlen(newfile_html)));
   rename(folder_struct->d_name, newfile_html);
   memset(newfile_html, 0, 0);
}
return 0;
}

