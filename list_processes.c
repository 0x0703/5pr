#include <stdlib.h>

void list_processes() {
    system("ps -eo pid,comm --sort pid");
}