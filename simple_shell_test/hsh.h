#ifndef HSH_H
#define HSH_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include <sys/wait.h>

char *get_line(void);
char **_split_line(char *line);
int _builtin(void);
int shell_cd(char **args);
int shell_exit(void);
int _shell_launch(char **args);
int exec_shell(char **args);
int shell_interact();
int shell_script(char filename[]);
int main(int argc, char **argv);

#endif
Footer
© 2022 GitHub, Inc.
Footer navigation
Terms

