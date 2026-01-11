#include "Header.h"
#include <stdarg.h>
#include <stdio.h>

size_t log_error(size_t errorCode, char* message, ...) {
    va_list args;
    va_start(args, message);

    vfprintf(stderr, message, args);

    return errorCode;
}
