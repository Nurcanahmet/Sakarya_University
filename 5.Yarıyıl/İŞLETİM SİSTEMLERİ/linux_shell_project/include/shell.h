#ifndef SHELL_H
#define SHELL_H

#define MAX_CMD_LEN 1024  // Maksimum komut uzunluğu

// Prompt gösteren fonksiyon
void print_prompt();

// Kullanıcıdan komut okuyan fonksiyon
void read_command(char *cmd);

#endif

