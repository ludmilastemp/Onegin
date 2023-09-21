#include "STL_sorts.h"

int BubbleSort (void* data, size_t nElem, size_t elemSize,
                int Compare (const void* x, const void* y))
{
    if (!data) return 1;

    size_t i = 0;
    nElem--;

    for (; nElem > 0; nElem--)
    {
        for (i = 0; i < nElem; i++)
        {
            if (Compare (((char*)data + i * elemSize),
                        ((char*)data + (i + 1) * elemSize)) > 0)
            {
                if (Swap (((char*)data + i * elemSize),
                         ((char*)data + (i + 1) * elemSize),
                         elemSize))
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int Swap (void* x, void* y, size_t size)
{
    if (!x) return 1;
    if (!y) return 1;

    char ch = 0;
    for (size_t i = 0; i < size; ++i)
    {
        ch = *((char*)x + i);
        *((char*)x + i) = *((char*)y + i);
        *((char*)y + i) = ch;
    }

    return 0;
}
