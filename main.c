#include<stdio.h>
#include<stdlib.h>
#include "main.h"
#include "helpingFunc.h"

int main()
{
    print_starting_cmd();

    InputBuffer* input_buffer = new_input_buffer();

    while (1)
    {
        print_prompt();

        read_input(input_buffer);

        if (input_buffer->buffer[0] == '.')
        {
            printf("This is a meta command\r");
            continue;
        }

        Statement statement;
        switch (prepare_statement(input_buffer, &statement))
        {
            case PREPARE_SUCCESS:
                printf("This is a success statement\r\n");
                continue;

            case PREPARE_UNRECOGNIZED_STATEMENT:
                printf("Unrecognized keyword at start of '%s'\r\n", input_buffer->buffer);
                continue;
            default:
                break;
        }

    }
    

    return 0;
}