#ifndef CATS_FW_ERROR_H
#define CATS_FW_ERROR_H

typedef enum errorType {
    ERROR_RADIO,
    ERROR_MISC
} error_type_t;

void error(error_type_t err);

#endif // CATS_FW_ERROR_H