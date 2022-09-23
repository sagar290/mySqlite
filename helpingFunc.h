#ifndef HELPINGFUNC_H_INCLUDED
#define HELPINGFUNC_H_INCLUDED
#include "main.h"
#define MAJOR_VERSION 0
#define MINOR_VERSION 1

void print_starting_cmd();
void print_prompt();
InputBuffer* new_input_buffer();
void read_input(InputBuffer* input_buffer);
PrepareResult prepare_statement(InputBuffer* input_buffer, Statement* statement);

#endif // HELPINGFUNC_H_INCLUDED