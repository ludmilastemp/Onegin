#include <ctype.h>

#include "compare.h"

static int IsLetter        (const char* str);
static int IsLetterFromEnd (const char* str);

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

static int IsLetter (const char* str)
{
    size_t i = 0;
    while (!isalpha (str[i]))
    {
        i++;
    }
    return i;
}

static int IsLetterFromEnd (const char* str)
{
    int i = 0;
    while (!isalpha (str[i]))
    {
        i--;
    }
    return i;
}
