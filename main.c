#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <getopt.h>
#include "list_processes.h"
#include "list_users.h"
#include "show_help.h"
#include "redirect_output.h"
#include "redirect_errors.h"

static struct option long_options[] = {
    {"users", no_argument, 0, 'u'},
    {"processes", no_argument, 0, 'p'},
    {"log", required_argument, 0, 'l'},
    {"errors", required_argument, 0, 'e'},
    {"help", no_argument, 0, 'h'},
    {0, 0, 0, 0}
};

int main(int argc, char *argv[]) {
    int opt;
    char *output = NULL;
    char *log_file = NULL;
    char *error_file = NULL;

    // Process command line arguments
    while ((opt = getopt_long(argc, argv, "upl:e:h", long_options, NULL)) != -1) {
        switch (opt) {
            case 'u':
                output = (char *)malloc(1024);
                list_users();
                break;
            case 'p':
                output = (char *)malloc(1024);
                list_processes();
                break;
            case 'l':
                log_file = optarg;
                redirect_output(log_file);
                break;
            case 'e':
                error_file = optarg;
                redirect_errors(error_file);
                break;
            case 'h':
                show_help();
                exit(0);
            default:
                fprintf(stderr, "Invalid option: -%c\n", optopt);
                exit(1);
        }
    }

    return 0;
}
