cmake_minimum_required(VERSION 3.10)

project(MyCProgram)

# Add all your source files
set(SOURCES
    main.c
    list_processes.c
    list_processes.h
    list_users.c
    list_users.h
    redirect_errors.c
    redirect_errors.h
    show_help.c
    show_help.h
    redirect_output.c
    redirect_output.h
)

# Add the executable
add_executable(my_program ${SOURCES})
