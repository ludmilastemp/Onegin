#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

const int Debug = 0;

#define $DBG  if (Debug)

void PrintString (int* str);

void PrintText (int** str);

void SplittingIntoLines (int** str, int* line, long long* numberOfLines);

void Swap (int** x, int** y);

void SortTwoStrings (int** str1, int** str2, int* line);

void SortTwoStringsFromEnd (int** str1, int** str2, int* line);

void SortingStrings (int** str, int* line, long long numberOfLines);

int main()
{
    $DBG for (int i = 0; i < 15; ++i) printf("\n");

    FILE* fp = fopen ("onegin.txt", "r");
    assert (fp);

    long long elementsInFile = 0;
    long long numberOfLines  = 0;

    fseek (fp, 0, SEEK_END);
    elementsInFile = ftell (fp);
    numberOfLines  = elementsInFile;
    fseek (fp, 0, SEEK_SET);

    int* line = (int*)  calloc (elementsInFile + 1, sizeof (int));
    assert (line);

    int** str = (int**) calloc (numberOfLines  + 1, sizeof (int*));
    assert (str);

    fread (line, sizeof (int), elementsInFile, fp);

    while ((int) *((char*)line + elementsInFile) == 0) elementsInFile--;

    *((char*)line + elementsInFile) = '\n';
    elementsInFile++;

    *((char*)line + elementsInFile) = EOF;
    elementsInFile++;

    if (Debug) printf ("%d \n", elementsInFile);
    for (size_t i = 0; i < elementsInFile; ++i)
    {
        //printf ("%d - %c %d\n", i, *((char*)line + i), *((char*)line + i));
    }

    printf ("\nReadInFile - OK!\n");

    SplittingIntoLines (str, line, &numberOfLines);
    printf ("\nSplittingIntoLines - OK!\n");

    //if (Debug) printf ("%d", numberOfLines);

    SortingStrings (str, line, numberOfLines);
    printf ("\nSortingStrings - OK!\n");

    printf ("\n\n");
    PrintText (str);

    printf ("\nProgramms the end");

    free (line);
    free (str);

    return 0;
}

void PrintString (int* str)
{
    int i = 0;

    if (*(char*)str == EOF) return;

    while (*((char*)str + i) != '\n')
    {
        printf ("%c", *(int*)((char*)str + i));
        ++i;
    }
    printf ("\n");
}

void PrintText (int** str)
{
    int i = 0;
    while (true)
    {
        if (*(char*)(*(str + i)) == EOF) return;

        printf ("%d ", i);
        PrintString (*(str + i));
        i++;
    }
}

void SplittingIntoLines (int** str, int* line, long long* numberOfLines)
{
    assert (str);
    assert (line);

    int i = 0;
    int j = 0;

    *(str + j) = (int*)((char*)line + i);
    i++;
    j++;

    while (true)
    {
        if (Debug) printf ("%c", *((char*)line + i));
        switch (*((char*)line + i))
        {
            case '\n':
                *(str + j) = (int*)((char*)line + i + 1);
                i++;
                j++;
                break;
            case -1:
                *numberOfLines = j - 1;
                str = (int**)realloc(str, sizeof(int*) * (*numberOfLines + 1));
                return;
            default:
                i++;
        }
    }
}

void Swap (int** x, int** y)
{
    assert (x);
    assert (y);

    if (Debug) printf ("%p %p\n", *x, *y);

    int* s = *x;
    *x = *y;
    *y = s;

    if (Debug) printf ("%p %p\n", *x, *y);

    return;
}

void SortTwoStrings (int** str1, int** str2, int* line)
{
    assert (str1);
    assert (str2);
    assert (line);

    if (Debug) printf ("Sort\n");

    int i1 = 0, i2 = 0;

    while (true)
    {
        while (!((65 <= (int)*((char*)*str1 + i1) && (int)*((char*)*str1 + i1) <= 90 ) ||
                 (97 <= (int)*((char*)*str1 + i1) && (int)*((char*)*str1 + i1) <= 122)))
        {
            if (Debug) printf("!");
            if (Debug) printf ("%d \n", *((char*)*str1 + i1));
            i1++;
        }
        while (!((65 <= (int)*((char*)*str2 + i2) && (int)*((char*)*str2 + i2) <= 90 ) ||
                 (97 <= (int)*((char*)*str2 + i2) && (int)*((char*)*str2 + i2) <= 122)))
        {
            if (Debug) printf("@");
            if (Debug) printf ("%d \n", *((char*)*str2 + i2));
            i2++;
        }

        if (Debug) printf ("<%c> %d or ", *((char*)*str1 + i1), (int)*((char*)*str1 + i1));
        if (Debug) printf ("<%c> %d \n",  *((char*)*str2 + i2), (int)*((char*)*str2 + i2));

        if ((int)*((char*)*str1 + i1) < (int)*((char*)*str2 + i2))
        {
            if (Debug) printf (" 1 ");
            return;
        }
        if ((int)*((char*)*str1 + i1) > (int)*((char*)*str2 + i2))
        {
            Swap (str1, str2);

            if (Debug) printf (" 2 ");
            return;
        }
        if (*((char*)*str1 + i1) == '\n')
        {
            if (Debug) printf (" 3 ");
            return;
        }
        if (*((char*)*str2 + i2) == '\n')
        {
            Swap (str1, str2);

            if (Debug) printf (" 4 ");
            return;
        }
        ++i1;
        ++i2;
    }
}

void SortTwoStringsFromEnd (int** str1, int** str2, int* line)
{
    assert (str1);
    assert (str2);
    assert (line);

    if (Debug) printf ("SortEnd\n");

    int i1 = 0, i2 = 0;

    while (*((char*)*str1 + i1) != '\n') i1++;
    while (*((char*)*str2 + i2) != '\n') i2++;

    while (true)
    {
        while (!((65 <= (int)*((char*)*str1 + i1) && (int)*((char*)*str1 + i1) <= 90 ) ||
                 (97 <= (int)*((char*)*str1 + i1) && (int)*((char*)*str1 + i1) <= 122)))
        {
            if (Debug) printf("!");
            if (Debug) printf ("%d \n", *((char*)*str1 + i1));
            i1--;
        }
        while (!((65 <= (int)*((char*)*str2 + i2) && (int)*((char*)*str2 + i2) <= 90 ) ||
                 (97 <= (int)*((char*)*str2 + i2) && (int)*((char*)*str2 + i2) <= 122)))
        {
            if (Debug) printf("@");
            if (Debug) printf ("%d \n", *((char*)*str2 + i2));
            i2--;
        }

        if (Debug) printf ("<%c> %d or ", *((char*)*str1 + i1), (int)*((char*)*str1 + i1));
        if (Debug) printf ("<%c> %d \n",  *((char*)*str2 + i2), (int)*((char*)*str2 + i2));

        if ((int)*((char*)*str1 + i1) < (int)*((char*)*str2 + i2))
        {
            if (Debug) printf (" 1 ");
            return;
        }
        if ((int)*((char*)*str1 + i1) > (int)*((char*)*str2 + i2))
        {
            Swap (str1, str2);

            if (Debug) printf (" 2 ");
            return;
        }
        if (i1 == 0)
        {
            if (Debug) printf (" 3 ");
            return;
        }
        if (i2 == 0)
        {
            Swap (str1, str2);

            if (Debug) printf (" 4 ");
            return;
        }
        --i1;
        --i2;
    }
}

void SortingStrings (int** str, int* line, long long numberOfLines)
{
    assert (str);
    assert (line);

    if (Debug) printf ("SortingStrings begin\n");
    int i = 0;
    int j = 0;
    long long n = numberOfLines - 1;

    while (n > 0)
    {
        if (Debug) printf ("%d ", n);
        i = 0;

        while (true)
        {
            if (Debug) if (*(char*)(*(str + i + 1)) == EOF)  { printf ("!%d", i);n = i; break; }

            if (Debug) printf ("\n%d ", n);
            if (Debug) printf ("%d ", j);
            if (Debug) printf ("%d\n ", i);

            if (Debug) printf ("\nSortBegin\n");

            if (Debug) PrintString (*(str + i));
            if (Debug) PrintString (*(str + i + 1));

            SortTwoStrings ((str + i), (str + i + 1), line); //return;
            //SortTwoStringsFromEnd ((str + i), (str + i + 1), line); //return;

            if (Debug) PrintString (*(str + i));
            if (Debug) PrintString (*(str + i + 1));

            if (Debug) printf ("SortEnd");
            if (Debug) printf ("\n");

            if ((++i) == n)
            {
                break;
            }
        }
        if (Debug) printf ("\nI end\n");
        n--; //return;
    }
    if (Debug) printf ("SortingStrings end\n");

}


int  SortTwoStrings (* str1, String* str2)
{
    assert (str1);
    assert (str2);

    $ printf ("Sort\n");

    int i1 = 0, i2 = 0;

    while (true)
    {
        while (!(('a' <= (int) *(str1->str + i1) && (int) *(str1->str + i1) <= 'z' )  ||
                 ('A' <= (int) *(str1->str + i1) && (int) *(str1->str + i1) <= 'Z' )))
        {
            $ printf("!");
            $ printf ("%d \n", *(str1->str + i1));
            i1++;
        }
        while (!(('a' <= (int) *(str2->str + i2) && (int) *(str2->str + i2) <= 'z' )  ||
                 ('A' <= (int) *(str2->str + i2) && (int) *(str2->str + i2) <= 'Z' )))
        {
            $ printf("@");
            $ printf ("%d \n", *(str2->str + i2));
            i2++;
        }

        $ printf ("<%c> %d or ", *(str1->str + i1), *(str1->str + i1));
        $ printf ("<%c> %d \n",  *(str2->str + i2), *(str2->str + i2));

        if ((int) *(str1->str + i1) < (int) *(str2->str + i2))
        {
            $ printf (" 1 ");
            return 1;
        }
        if ((int) *(str1->str + i1) > (int) *(str2->str + i2))
        {
            //Swap (str1, str2);

            $ printf (" 2 ");
            return -1;
        }
        if (*(str1->str + i1) == '\n')
        {
            $ printf (" 3 ");
            return 1;
        }
        if (*(str2->str + i2) == '\n')
        {
            //Swap (str1, str2);

            $ printf (" 4 ");
            return -1;
        }
        ++i1;
        ++i2;
    }
}


