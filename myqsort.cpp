#include <stdio.h>

const int Debug = 1;

#define $ if (Debug)

const int sizeData = 20;

void PrintArray (int* data, int left, int right);

int  Partition (int* data, int left, int right);

void qsort (int* data, int left, int right);

void Swap (int* a, int* b);

int main ()                        // not correct
{
    $ printf ("\n\n\n\n\n\n\n\n\n\n");

    int data[sizeData] = {5,9,87,-3,0,-78,-2222,65,
                        -3,785,1,9,0,0,-2222,2222,3,68,452,1};

    printf ("\n\n Initial array: \n");
    PrintArray (data, 0, sizeData - 1);

    qsort (data, 0, sizeData - 1);

    printf ("\n\n Result:        \n");
    PrintArray (data, 0, sizeData - 1);
}

void qsort (int* data, int left, int right)
{
    $ printf ("\n\nI qsort:         left = %d, right = %d\n", left, right);
    $ PrintArray (data, left, right);

    if ((right - left) < 1) return;
    if ((right - left) == 1 && data[left] > data[right])
        Swap (&data[left], &data[right]);

    int middle = Partition (data, left, right);

    if (middle > right) return;

    qsort (data, left,   middle - 1);
    qsort (data, middle, right);
}

int Partition (int* data, int left, int right)
{
    $ printf ("I Partition:     left = %d, right = %d\n", left, right);
    $ PrintArray (data, left, right);

    int leftRef  = left;
    int rightRef = right;

    int mid = data[ (right + left) / 2 ];

    while (left <= right)
    {
        while (data[left] < mid)
        {
            left++;
        }
        while (data[right] > mid)
        {
            right--;
        }

        if (left >= right) break;


        $ printf ("I Swap: mid = %d  left = %d, right = %d %d | %d\n",
                  mid, left, right, data[left], data[right]);

        Swap (&data[left], &data[right]);

        left++;
        right--;

        if (left >= right) break;

     }

    $ printf ("I end sort:      left = %d, right = %d\n", left, right);
    $ printf ("  mid = %d\n", left);
    $ PrintArray (data, leftRef, rightRef);

    if (data[left] < mid) return left + 1;
    return left;
}

void Swap (int* a, int* b)
{
    int x = *a;
    *a    = *b;
    *b    = x;
}

void PrintArray (int* data, int left, int right)
{
    size_t i = 0;

    $ for (; i < sizeData; ++i) printf ("%-3d", i);
    $ printf ("\n");

    i = 0;
    for (; i < left;  ++i) printf ("%-6d" , data[i] );
    printf ("\033[102;1m" "%-6d" "\033[0m", data[i++]);
    for (; i < right; ++i) printf ("%-6d" , data[i]);
    if (i == right) printf ("\033[41;1m"  "%-6d" "\033[0m", data[i++] );
    for (; i < sizeData;     ++i) printf ("%-6d" , data[i]);
    printf ("\n");
}

