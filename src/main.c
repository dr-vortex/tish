#include <stdio.h>
#include <math.h>
#include <string.h>

#include <ti/screen.h>

#define MAX_INPUT_SIZE  16
#define MAX_OUTPUT_SIZE 400

//terminal prompt states
#define ST_NULL 0
#define ST_EXIT 0x7f

//text
#define INPUT_DELIM "$ "
#define CMD_ARG_DELIM ","

char output[MAX_OUTPUT_SIZE] = "";
char* input_prefix = INPUT_DELIM;

void split(char* string, char* result[]){

    char* token;
    int i = 0;

	token = strtok(string, CMD_ARG_DELIM);
	strcpy(result[i], token);

    while(token != NULL) {
		token = strtok(NULL, CMD_ARG_DELIM);
		strcpy(result[++i], token);
	}

}

char* commands[] = {
	"ECHO",
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	"EXIT",
};

//update the terminal
int update(char* new_output){

	os_ClrHome();
	if(strlen(output) > MAX_OUTPUT_SIZE){
		printf("Error: Max output size exceeded");
		return 1;
	}

	if(new_output){
		strcat(output, new_output);
		strcat(output, "\n");
	}

	printf("%s", output);

	return 0;
}

int prompt(){

	char input[MAX_INPUT_SIZE];
	char input_text[MAX_INPUT_SIZE];
	printf(input_prefix);
	fgets(&input, MAX_INPUT_SIZE, stdin);
	input[strcspn(input, "\n\r")] = 0; //remove trailing newline

	strcpy(input_text, input_prefix);
	strcat(input_text, input);
	
	update(&input_text);

	int command_code = 0;
	for(size_t i = sizeof(commands) / sizeof(commands[0]) - 1; i > 0; i--){
		if(!strcmp(input, commands[i])){
			command_code = i;
			break;
		}
	}

	switch(command_code){
		case ST_EXIT:
			break;
		default:
			update("Command does not exist");

	}

	return command_code;
}

int main()
{
	update(NULL);

	while (true) {
		int state = prompt();

		if(state == ST_EXIT){
			break;
		}
	}

	return 0;
}