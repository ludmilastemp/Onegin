#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <sys\stat.h>

//Swap
//Bubble
//git

#include "fread.h"

const int Debug = 0;

#define $  if (Debug)

int Compare (const void* str1, const void* str2);

int CompareFromEnd (const void* str1, const void* str2);

void SortingStrings (String* strings, long long nLines);

void Swap (String* str1, String* str2);

int IsLetter (const char* str);

int IsLetterFromEnd (const char* str);

void FPrintText (FILE* fp, String* strings, long long nLines);

void FPrintString (FILE* fp, char* str);

int main()
{
    File file = { 0 };

    file.strings = stl_SplitFileIntoLines (&file, "onegin.txt");
    if (file.strings == nullptr)
    {
        return EXIT_FAILURE;
    }

    FILE* fp = fopen ("onegin2.0.txt", "w");

    qsort (file.strings, file.nLines, sizeof (String), Compare);
    FPrintText (fp, file.strings, file.nLines);

    SortingStrings (file.strings, file.nLines);
    FPrintText (fp, file.strings, file.nLines);

    fprintf (fp, "%s", file.text);

    free (file.text);
    free (file.strings);

    return 0;
}

int Compare (const void* string1, const void* string2)
{
    assert (string1);
    assert (string2);

    const char* str1 = ((String*) string1) -> str;
    const char* str2 = ((String*) string2) -> str;

    long long i1 = IsLetter (str1);
    long long i2 = IsLetter (str2);

    while (true)
    {

        if ((int) *((char*) str1 + i1) < (int) *((char*) str2 + i2))
        {
            return -1;
        }
        if ((int) *((char*) str1 + i1) > (int) *((char*) str2 + i2))
        {
            return 1;
        }
        if (*((char*) str1 + i1) == '\n')
        {
            return -1;
        }
        if (*((char*) str2 + i2) == '\n')
        {
            return 1;
        }
        ++i1;
        ++i2;
    }
}

int CompareFromEnd (const void* string1, const void* string2)
{
    assert (string1);
    assert (string2);

    const char* str1 = ((String*) string1) -> str;
    const char* str2 = ((String*) string2) -> str;

    long long i1 = ((String*) string1) -> len;
    long long i2 = ((String*) string2) -> len;

    i1 += IsLetterFromEnd (str1 + i1);
    i2 += IsLetterFromEnd (str2 + i2);

    while (true)
    {
        if ((int) *((char*) str1 + i1) < (int) *((char*) str2 + i2))
        {
            return -1;
        }
        if ((int) *((char*) str1 + i1) > (int) *((char*) str2 + i2))
        {
            return 1;
        }
        if (i1 == 0)
        {
            return -1;
        }
        if (i2 == 0)
        {
            return 1;
        }
        i1--;
        i2--;
    }
}

void SortingStrings (String* strings, long long nLines)   // sort
{
    assert (strings);

    size_t i = 0;
    size_t j = 0;
    nLines--;

    while (nLines > 0)
    {
        i = 0;

        while (true)
        {
            if (CompareFromEnd ((strings + i), (strings + i + 1)) > 0)
            {
                Swap ((strings + i), (strings + i + 1));
            }

            if ((++i) == nLines)
            {
                break;
            }
        }

        nLines--;
    }
}

// void Swap(void*, void*, size)
// long int short char

void Swap (String* str1, String* str2)
{
    assert (str1);
    assert (str2);

    String s = *str1;
    *str1    = *str2;
    *str2    = s;

    return;
}

int IsLetter (const char* str)
{
    size_t i = 0;
    while (!isalpha (str[i]))
    {
        i++;
    }
    return i;
}

int IsLetterFromEnd (const char* str)
{
    int i = 0;
    while (!isalpha (str[i]))
    {
        i--;
    }
    return i;
}

void FPrintString (FILE* fp, char* str)
{
    size_t i = 0;

    while (*(str + i) != '\n')
    {
        fputc  (      (char) *(str + i), fp);
        printf ("%c", (char) *(str + i)    );
        ++i;
    }

    fputc  ('\n', fp);
    printf ("\n");
}

void FPrintText (FILE* fp, String* strings, long long nLines)
{
    printf ("\n\n");

    size_t i = 0;
    while (true)
    {
        if (nLines-- == 0) break;

        printf ("%d ", i);
        FPrintString (fp, (strings + i)->str);
        i++;
    }

    fprintf (fp, "\n\n\n");
    fprintf (fp, "---------------------------------------\n");
    fprintf (fp, "\n\n\n");

    printf ("\n\n");
}
