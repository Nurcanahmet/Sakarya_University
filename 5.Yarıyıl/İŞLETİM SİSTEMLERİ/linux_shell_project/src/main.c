#include <stdio.h>
#include <string.h> // strcmp için gerekli
#include "../include/shell.h"

int main()
{
    char command[MAX_CMD_LEN];

    while (1)
    {
        // Prompt'u yazdır
        print_prompt();

        // Kullanıcıdan komut al
        read_command(command);

        // Çıkış komutunu kontrol et
        if (strcmp(command, "exit") == 0)
        {
            printf("Exiting shell...\n");
            break;
        }

        // Komutu yazdır (şimdilik test için)
        printf("You entered: %s\n", command);
    }

    return 0;
}
