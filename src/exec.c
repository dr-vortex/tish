#include <stdio.h>
#include <string.h>

#include "shell.h"

int get_command_code(char* command){
	int command_code = -1;
	for(size_t i = sizeof(commands) / sizeof(commands[0]) - 1; i > 0; i--){
		if(!strcmp(command, commands[i])){
			command_code = i;
			break;
		}
	}
	return command_code;
}

void parse_args(char* string, char* result[]){

    char* token;
    int i = 0;

	token = strtok(string, CMD_ARG_DELIM);
	strcpy(result[i], token);

    while(token != NULL) {
		token = strtok(NULL, CMD_ARG_DELIM);
		strcpy(result[++i], token);
	}

}