#ifndef STL_file_open_
#define STL_file_open_

#include <stdlib.h>
#include <sys\stat.h>
#include <assert.h>

#include "STL_string.h"

struct File
{
    const char* name;
    FILE* fp;
    char* text;
    size_t size;
    size_t nLines;
    String* strings;
};

char* STL_Fread (struct File* file);

String* STL_SplitFileIntoLines (struct File* file, const char* name);

#endif
