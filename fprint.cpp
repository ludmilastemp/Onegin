#include "fprint.h"

void FPrintString (FILE* fp, const char* str)
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

void FPrintText (FILE* fp, String* strings, size_t nLines)
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
