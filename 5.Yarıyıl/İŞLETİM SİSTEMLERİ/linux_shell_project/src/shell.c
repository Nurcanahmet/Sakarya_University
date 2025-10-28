#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strcmp için gerekli

#define MAX_CMD_LEN 1024

// Komut istemini yazdıran fonksiyon
void print_prompt()
{
    printf("> ");   // Komut istemini göster
    fflush(stdout); // Print buffer'ını temizle
}

// Kullanıcıdan komut okuma fonksiyonu
void read_command(char *command)
{
    // Kullanıcıdan komut al
    fgets(command, MAX_CMD_LEN, stdin);
    // Komut sonundaki yeni satır karakterini sil
    command[strcspn(command, "\n")] = 0;
}
