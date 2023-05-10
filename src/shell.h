#define MAX_INPUT_SIZE 16
#define MAX_OUTPUT_SIZE 400

// terminal prompt states
#define ST_NULL 0
#define ST_EXIT 0x7f

// text
#define INPUT_DELIM "$ "
#define CMD_ARG_DELIM ","

extern char *commands[ST_EXIT + 1];
extern int get_command_code(char *command);
extern void parse_args(char *string, char *result[]);