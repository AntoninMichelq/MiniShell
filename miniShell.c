
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_CANON 1024
#include "exec_cmd.h"

void free_command(cmd* chain);
char* alloc_char();
cmd* charToChain(char* args);

int main(void)
{
    cmd_tab tab[] = {
    {"ls", (int(*)(cmd*))exec_ls},
    {"exit", (int(*)(cmd*))exec_exit},
    {NULL, NULL}
    };
    
    int run = 1;
    while(run) {
        char* command = alloc_char();
        printf("minishell>");

        if(scanf("%s", command) == EOF) {
            free(command);
            break;
        }
        cmd*  chain = charToChain(command);

        int j = 0;
        while(tab[j].name != NULL) {
            if(strcmp(command, tab[j].name) == 0) {
                run = tab[j].func(chain);
                break;
            }
            j++;
        }

     free_command(chain);
     free(command);    
    }
    return 0;
}

char* alloc_char() {
    return malloc(sizeof(char) * MAX_CANON);
}
void free_command(cmd* chain) {
    cmd* tmp;
    while(chain != NULL) {
        tmp = chain->next;
        if(chain->name != NULL)
            free(chain->name);
        free(chain);

        chain = tmp;
    }
    chain = NULL;
}

cmd* charToChain(char* args) {
    cmd* tmpChain = malloc(sizeof(cmd));
    tmpChain->name = alloc_char();

    cmd* current = tmpChain;

    int i = 0; int j = 0;
    while(args[i] != '\0') {
       if(args[i] == ' ') {
            if(j > 0) {
                current->name[j] = '\0';
                cmd* next = malloc(sizeof(cmd));
                next->name = alloc_char();

                current->next = next;
                current = next;
                j = 0;
            }
        } else {
            current->name[j] = args[i]; 
            j++;
        }
        i++; 
    }
    current->name[j] = '\0';
    current->next = NULL;
    return tmpChain;
}