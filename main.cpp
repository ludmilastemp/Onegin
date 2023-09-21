#include <stdio.h>

#include "STL_sorts.h"
#include "STL_file_open.h"
#include "compare.h"
#include "fprint.h"

int main()
{
    File file = { 0 };

    file.strings = STL_SplitFileIntoLines (&file, "onegin.txt");
    if (file.strings == nullptr)
    {
        return EXIT_FAILURE;
    }

    FILE* fp = fopen ("onegin2.0.txt", "w");

    qsort (file.strings, file.nLines, sizeof (String), Compare);
    FPrintText (fp, file.strings, file.nLines);

    BubbleSort (file.strings, file.nLines, sizeof (String), CompareFromEnd);
    FPrintText (fp, file.strings, file.nLines);

    fprintf (fp, "%s", file.text);

    free (file.text);
    free (file.strings);

    return 0;
}
