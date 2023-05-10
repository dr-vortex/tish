#include <math.h>
#include <stdio.h>
#include <string.h>

#ifdef NOT_TI
#include <stdlib.h>
#else
#include <ti/screen.h>
#endif

#include "shell.h"

char output[MAX_OUTPUT_SIZE] = "";
char *input_prefix = INPUT_DELIM;

// update the terminal
int update(char *new_output)
{

#ifdef NOT_TI
	system("clear");
#else
	os_ClrHome();
#endif
	if (strlen(output) > MAX_OUTPUT_SIZE)
	{
		printf("Error: Max output size exceeded");
		return 1;
	}

	if (new_output)
	{
		strcat(output, new_output);
		strcat(output, "\n");
	}

	printf("%s", output);

	return 0;
}

int prompt()
{

	char input[MAX_INPUT_SIZE];
	char input_text[MAX_INPUT_SIZE];
	printf("%s", input_prefix);
	fgets(input, MAX_INPUT_SIZE, stdin);
	input[strcspn(input, "\n\r")] = 0; // remove trailing newline

	strcpy(input_text, input_prefix);
	strcat(input_text, input);

	update(input_text);

	int command_code = get_command_code(input);

	switch (command_code)
	{
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

	while (true)
	{
		int state = prompt();

		if (state == ST_EXIT)
		{
			break;
		}
	}

	return 0;
}