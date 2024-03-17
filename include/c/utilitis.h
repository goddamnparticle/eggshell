#ifndef UTILITIS_H
#define UTILITIS_H

// Welcome print
void welcome_print();

// Clear terminal command
void clear_terminal();

// Parse input command
char** parse_input_command(char *input_command);
void free_input_command(char**input_command);
void organize_command(char *input_command);
void deleteAtIndex(char *str, int index);

// Help command
void help_command();

// Create folder command
void create_folder( char *folder_name);

// Current path
void current_path_command();

// Create a file
void create_file_command();

// list directories
void list_dir_command();

#endif  //UTILITIS_H