#ifndef EXEC_CMD_H
#define EXEC_CMD_H

typedef struct cmd{ 
    char* name;
    struct cmd* next;
} cmd;

typedef struct cmd_tab {
    char* name;
    int(*func)(cmd *cmd); 
} cmd_tab;

int exec_ls(cmd* name);
int exec_exit();

#endif