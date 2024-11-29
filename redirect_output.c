#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

void redirect_output(char *file_path) {
    int file_descriptor = open(file_path, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (file_descriptor == -1) {
        perror("Error opening file for writing");
        exit(1);
    }

    if (dup2(file_descriptor, STDOUT_FILENO) == -1) {
        perror("Error redirecting output to file");
        exit(1);
    }

    close(file_descriptor);
}