#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>

#include "utilitis.h"

// Welcome print------------------------------------------------------------------------------------------
void welcome_print() {
    printf("┏┓┏┓┏┓  ┏┓┓┏┏┓┓ ┓   ┏┓\n");
    printf("┣ ┃┓┃┓  ┗┓┣┫┣ ┃ ┃   ┃\n");
    printf("┗┛┗┛┗┛  ┗┛┛┗┗┛┗┛┗┛  ┗┛\n");
    printf("\n* Enter `help` command for help\n\n");
}

// Clear terminal-----------------------------------------------------------------------------------------
void clear_terminal() {
    system("clear");
}

// Parse input command------------------------------------------------------------------------------------
#define MAX_TOKENS 5
#define MAX_TOKEN_LENGTH 20

char** parse_input_command(char *input_command) {
    char** parsed_command = (char**)malloc(MAX_TOKENS * sizeof(char*));
    
    for (int i = 0; i < MAX_TOKENS; i++) {
        parsed_command[i] = (char*)malloc(MAX_TOKEN_LENGTH * sizeof(char));
    }

    char *token = strtok(input_command, " ");
    
    int i = 0;
    
    while (token != NULL && i < MAX_TOKENS) {
        strcpy(parsed_command[i], token);
        token = strtok(NULL, " ");
        i++;
    }

    return parsed_command;
}

void free_input_command(char**input_command) {
    for(int i = MAX_TOKENS; i<MAX_TOKENS; i++) {
        free(input_command[i]);
    }    
    
    free(input_command);
}

void organize_command(char *input_command){
    int i = 0;
    while(input_command[i] !='\0') {
        if (input_command[i]=='\n'){
            deleteAtIndex(input_command, i);
        }
        i++;
    }
}

void deleteAtIndex(char *str, int index) {
    int len = strlen(str);
    
    if (index >= 0 && index < len) {
        memmove(&str[index], &str[index + 1], len - index); // Shift characters to the left
    }
}

// Help command -----------------------------------------------------------------------------------
void help_command() {
    printf("# Terminal Commands ------------\n");
    printf("* clear: clear terminal\n");
    printf("* exit: exit terminal\n");
}

void create_folder( char *folder_name){
    bool is_succes = mkdir(folder_name, 0777);

    if (is_succes == 0) {
        printf("Directory created successfully.\n");
    } else {
        printf("Unable to create directory. Please check if it already exists or if you have sufficient permissions.\n");
    }
}