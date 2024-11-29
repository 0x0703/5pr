#include <stdlib.h>

void list_users() {
    system("awk -F: '{ print $1, $6 }' /etc/passwd | sort -k1");
}