#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <string.h>

void list_users() {
    struct passwd *pw;
    FILE *fp = popen("cut -d: -f1,6 /etc/passwd | sort", "r");
    
    if (fp == NULL) {
        perror("Ошибка при выполнении команды");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }
    
    pclose(fp);
}

