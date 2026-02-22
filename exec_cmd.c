#include "exec_cmd.h"

#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>


int exec_ls(cmd* name) {
    (void) name;
    DIR* folder = opendir(".");
    struct dirent* hFile;
    
    while((hFile = readdir(folder)) != NULL) {
        printf("%s ", hFile->d_name);
    }

    closedir(folder);
    return 0;
}

int exec_exit() {
    exit(0);
    return 0;
}






