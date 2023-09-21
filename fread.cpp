#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys\stat.h>
#include <string.h>

#include "fread.h"

static void SplitIntoLines (File* file);   // readelf -t file.o

char* stl_Fread (File* file)
{
    assert (file);

    struct stat buff = { 0 };

    file->fp = fopen (file->name, "r");
    assert (file->fp);
    if (file->fp == nullptr)
    {
        fprintf(stderr, "Open file error: %s\n", strerror(errno));
        return nullptr;
    }

    fstat (fileno (file->fp), &buff);

    file->size = buff.st_size;

    file->text = (char*) calloc (file->size + 1, sizeof (char));
    assert (file->text);

    file->size = fread (file->text, sizeof (char), file->size, file->fp);

    /**
     *
     */
    if (*(file->text + file->size - 1) != '\n')
    {
        *(file->text + file->size) = '\n';
        (file->size)++;
    }

    fclose (file->fp);
    file->fp = nullptr;

    return file->text;
}

String* stl_SplitFileIntoLines (File* file, const char* name)
{
    assert (file);

    file->name = name;

    file->text = stl_Fread (file);

    for (size_t i = 0; i <= file->size; i++)
    {
        if ((file->text)[i] == '\n') (file->nLines)++;
    }

    file->strings = (String*) calloc (file->nLines + 1, sizeof (String));
    assert (file->strings);

    SplitIntoLines (file);

    return file->strings;
}

static void SplitIntoLines (File* file)
{
    assert (file);

    size_t line = 0;
    size_t pos = 0;

    (file->strings + line)->str = (file->text + pos);

    line++;
    pos++;

    for (; line < file->nLines + 1; line++)
    {
        while (*(file->text + pos) != '\n') pos++;

        (file->strings + line)    ->str = (file->text + pos + 1);
        (file->strings + line - 1)->len = (file->strings + line)->str
                                          - (file->strings + line - 1)->str - 1;

        pos++;

    }

    (file->strings + line - 1)->len = (file->strings + line)->str
                                      - (file->strings + line - 1)->str - 1;
}