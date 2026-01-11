#ifndef HEADER_H
# define HEADER_H

#include <stdlib.h>

typedef struct {
	char* key;
	int value;
} item;

typedef enum eErrorCode {
    ERR_INPUT,
    ERR_KEY_MISSING
} ErrorCode;

size_t log_error(size_t errorCode, char* message, ...);

#endif