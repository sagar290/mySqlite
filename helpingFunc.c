#include "helpingFunc.h"
#include "main.h"

void print_starting_cmd()
{
    printf("amar sqlite %d.%d a apnake shagotom\r\n", MAJOR_VERSION, MINOR_VERSION);
}

void print_prompt()
{
    printf("mySqlite>");
}

InputBuffer* new_input_buffer()
{
    InputBuffer* input_buffer = malloc(sizeof(InputBuffer));
    input_buffer->buffer = NULL;
    input_buffer->buffer_length = 0;

    return input_buffer;
}

void read_input(InputBuffer* input_buffer)
{
    size_t bytes_read = getline(&(input_buffer->buffer), &(input_buffer->buffer_length), stdin);

    if (bytes_read <= 0)
    {
        printf("Error reading input\r");
        exit(EXIT_FAILURE);
    }

}

stringTokenResult isToken(char* buffer, char* token)
{
    if (strncmp(buffer, token, strlen(token)) == 0)
    {
        return STRING_TOKEN_MATCHED;
    }

    return STRING_TOKEN_NOT_MATCHED;

}

PrepareResult prepare_statement(InputBuffer* input_buffer, Statement* statement)
{

    if (isToken(input_buffer->buffer, "SELECT") == STRING_TOKEN_MATCHED)
    {
        statement->type = STATEMENT_SELECT;
        return PREPARE_SUCCESS;
    }

    if (isToken(input_buffer->buffer, "INSERT") == STRING_TOKEN_MATCHED)
    {
        statement->type = STATEMENT_INSERT;
        return PREPARE_SUCCESS;
    }

    return PREPARE_UNRECOGNIZED_STATEMENT;
}