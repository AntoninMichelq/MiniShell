#include "exec_cmd.h"

#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>


int exec_ls(cmd* name) {
    (void) name;
    DIR* folder = opendir(".");
    struct dirent* hFile;
    int i = 0;
    while((hFile = readdir(folder)) != NULL) {
        i++;
        if(hFile->d_name[0] != '.') {
            printf("%s ", hFile->d_name);
        }
        if(i%4 == 0) printf("\n");
    }
    printf("\n");

    closedir(folder);
    return 1;
}

int exec_exit() {
    return 0;
}






