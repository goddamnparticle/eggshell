#ifndef UTILITIS_H
#define UTILITIS_H

// Welcome print
void welcome_print();

// Clear terminal
void clear_terminal();

// Parse input command
char** parse_input_command(char *input_command);
void free_input_command(char**input_command);
void organize_command(char *input_command);

#endif  //UTILITIS_H