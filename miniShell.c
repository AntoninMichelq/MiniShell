
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "exec_cmd.h"

int main(void)
{
    cmd_tab tab[] = {
    {"ls", (int(*)(cmd*))exec_ls},
    {"exit", (int(*)(cmd*))exec_exit},
    {NULL, NULL}
    };

    cmd* chain;
    char command[100];
    int size;
    while(1)
    {
        printf("minishell>");
        scanf("%s", command);
        size = strlen(command);
        for(int i = 0; i < size; i++) {
            if(strcmp(command, tab[i].name) == 0) {
                tab[i].func(chain);
            }
        }
    }
    free(command);
    return 0;
}