#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "utilitis.h"

int main(int argc, char** argv)
{   
    // Clear terminal
    clear_terminal();

    //Welcome print
    welcome_print();

    char *command_input = NULL;
    size_t str_buffer_size = 100;

    while(true) {
    printf("Enter command: ");
    command_input = (char*) malloc(str_buffer_size * sizeof(char));

    if (command_input == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    getline(&command_input, &str_buffer_size, stdin);

    char **parsed_input_command = parse_input_command(command_input);

    char *command = parsed_input_command[0];

    
    organize_command(command);

    if(!strcmp(command, "clear")) {
        clear_terminal();
    } else if(!strcmp(command, "exit")){
        printf("Terminating\n");
        exit(0);
    } else {
        printf("command:%s,%d\n",command ,strcmp(command, "clear"));
        printf("Please enter a valid command!\n");
    }

    free_input_command(parsed_input_command);
    free(command_input);
    free(command);

    }

    return 0;
}