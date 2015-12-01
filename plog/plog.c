#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fts.h>
#include<string.h>
#include<errno.h>
#include<limits.h>
#include<unistd.h>
#include<regex.h>

int main(int argc, char* const argv[])
{
    char buf[PATH_MAX+1];
    regex_t re;
    FTS* file_system = NULL;
    FTSENT* child = NULL;
    FTSENT* parent = NULL;

    if (argc<2)
    {
        printf("Usage: %s <path-spec>\n", argv[0]);
        exit(255);
    }

    regcomp(&re, "^(.*log)$",REG_EXTENDED|REG_NOSUB);

    file_system = fts_open(argv + 1,FTS_LOGICAL,NULL);

    if (NULL != file_system)
    {
        while( (parent = fts_read(file_system)) != NULL)
        {
            child = fts_children(file_system,0);

            if (errno)
            {
                perror("fts_children");
            }
            
            regcomp(&re, "^(.*log)$",REG_EXTENDED|REG_NOSUB);

            while ((NULL != child)
                && (NULL != child->fts_link))
            {
                child = child->fts_link;
                
                char* file = (char*) malloc(strlen(child->fts_path)+\
                                               strlen(child->fts_name) +1 );
                strcpy(file, child->fts_path);
                strcat(file, child->fts_name);

                readlink(file, buf, PATH_MAX -1);
                
                if (regexec(&re, buf, 0, NULL, 0) == 0) { 
                  printf("%s: %s\n", argv[0], buf);
                }
                memset(&buf[0], 0, sizeof(buf));
            }
        }
        fts_close(file_system);
    }
    return 0;
}
