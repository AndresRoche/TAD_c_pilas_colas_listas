#ifndef TYPEDATA
#define TYPEDATA

#include <stdbool.h>

typedef enum{
    TYPE_INT, 
    TYPE_CHAR, 
    TYPE_BOOL, 
    TYPE_STRING, 
    TYPE_FLOAT
} DataType;

typedef union {
    int valueInt;
    float valueFloat;
    char valueChar;
    char* valueString;
    bool valueBool;
} DataValue;

#endif