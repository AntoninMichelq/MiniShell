#ifndef EXEC_CMD_H
#define EXEC_CMD_H

typedef struct cmd{
    char* args;
    struct cmd* next;
} cmd;

typedef struct cmd_tab {
    char* name;
    int(*func)(cmd *cmd); 
} cmd_tab;

int exec_ls(cmd* args);
int exec_exit();

#endif