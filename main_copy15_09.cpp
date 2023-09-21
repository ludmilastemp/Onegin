#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <sys\stat.h>

#include "fread.h"

const int Debug = 0;

#define $  if (Debug)

int  Compare        (const void* string1, const void* string2);

int  CompareFromEnd (const void* string1, const void* string2);

int  CompareMain (const void* string1, const void* string2, int straight = 1);

void SortingStrings (String* strings, long long numberOfLines);

void Swap           (String* str1, String* str2);

void FPrintString   (FILE* fp, char* str);

void FPrintText     (FILE* fp, String* strings);

int main()
{
    $ for (int i = 0; i < 15; ++i) printf("\n");

    long long countLines = 0;

    String* strings = stl_SplitFileIntoLines ("onegin.txt", &countLines);

    //SortingStrings (strings, countLines);
    qsort ((void*) strings, countLines, sizeof (String), Compare);

    FILE* fp = fopen ("onegin2.0.txt", "w");

    FPrintText (fp, strings);

    free (strings);

    return 0;
}
         /*
int  Compare (const void* string1, const void* string2)
{
    return CompareMain (string1, string2, 1);
}         //*/
 //*
int  CompareMain (const void* string1, const void* string2, int straight)
{
    assert (string1);
    assert (string2);

    const char* str1 = ((String*) string1) -> str;
    const char* str2 = ((String*) string2) -> str;

    long long i1 = 0;
    long long i2 = 0;

    if (straight == -1)
    {
        i1 = ((String*) string1) -> len;
        i2 = ((String*) string2) -> len;
    }

    while (true)
    {
        while (!isalpha (*((char*) str1 + i1)))
        {
            i1 += straight;
        }
        while (!isalpha (*((char*) str2 + i2)))
        {
            i2 += straight;
        }

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
        i1 += straight;
        i2 += straight;
    }
}
   ////*///*
int  Compare (const void* string1, const void* string2)
{
    assert (string1);
    assert (string2);

    const char* str1 = ((String*) string1) -> str;
    const char* str2 = ((String*) string2) -> str;

    long long i1 = 0;
    long long i2 = 0;

    while (true)
    {
        while (!isalpha (*((char*) str1 + i1)))
        {
            i1++;
        }
        while (!isalpha (*((char*) str2 + i2)))
        {
            i2++;
        }

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

int  CompareFromEnd (const void* string1, const void* string2)
{
    assert (string1);
    assert (string2);

    const char* str1 = ((String*) string1) -> str;
    const char* str2 = ((String*) string2) -> str;

    long long i1 = ((String*) string1) -> len;
    long long i2 = ((String*) string2) -> len;

    while (true)
    {
        while (!isalpha (*((char*) str1 + i1)))
        {
            i1--;
        }
        while (!isalpha (*((char*) str2 + i2)))
        {
            i2--;
        }

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

void SortingStrings (String* strings, long long numberOfLines)
{
    assert (strings);

    int i = 0;
    int j = 0;
    numberOfLines--;

    while (numberOfLines > 0)
    {
        i = 0;

        while (true)
        {
            if (Compare ((strings + i), (strings + i + 1)) > 0)
            {
                Swap ((strings + i), (strings + i + 1));
            }

            if (CompareFromEnd ((strings + i), (strings + i + 1)) > 0)
            {
            //    Swap ((strings + i), (strings + i + 1));
            }

            if ((++i) == numberOfLines)
            {
                break;
            }
        }

        numberOfLines--;
    }
}

void Swap (String* str1, String* str2)
{
    assert (str1);
    assert (str2);

    String s = *str1;
    *str1    = *str2;
    *str2    = s;

    return;
}

void FPrintString (FILE* fp, char* str)
{
    int i = 0;

    if (*str == EOF) return;

    while (*(str + i) != '\n')
    {
        fputc  (      (char) *(str + i), fp);
        printf ("%c", (char) *(str + i)    );
        ++i;
    }

    fputc  ('\n', fp);
    printf ("\n");
}

void FPrintText (FILE* fp, String* strings)
{
    printf ("\n\n");

    int i = 0;
    while (true)
    {
        if (*((strings + i)->str) == EOF) break;

        printf ("%d ", i);
        FPrintString (fp, (strings + i)->str);
        i++;
    }

    printf ("\n\n");
}
