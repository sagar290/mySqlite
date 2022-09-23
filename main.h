#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct _inputBuffer_t {
    char *buffer;
    size_t buffer_length;
} InputBuffer;

typedef enum {
    STATEMENT_SELECT,
    STATEMENT_INSERT,
} StatementType;

typedef struct _statement_t {
    StatementType type;
} Statement;

typedef enum {
    PREPARE_SUCCESS,
    PREPARE_UNRECOGNIZED_STATEMENT,
} PrepareResult;

typedef enum {
    STRING_TOKEN_MATCHED,
    STRING_TOKEN_NOT_MATCHED,
} stringTokenResult;

#endif