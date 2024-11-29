#include <stdio.h>

void show_help() {
    printf("Usage: program_name [options]\n\n");
    printf("Options:\n");
    printf(" -u, --users         List users and their home directories.\n");
    printf(" -p, --processes     List running processes.\n");
    printf(" -h, --help          Show help.\n");
    printf(" -l PATH, --log PATH Write output to the specified PATH file.\n");
    printf(" -e PATH, --errors PATH Write error output to the specified PATH file.\n");
}