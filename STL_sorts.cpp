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

int Swap (void* p1, void* p2, size_t size)
{
    if (!p1) return 1;
    if (!p2) return 1;

    long long n1;

    int i = 0;
    for (; size >= 8; size -= 8, i++)
    {
        n1 = *(long long*)((char*)p1 + i * 8);
        *(long long*)((char*)p1 + i * 8) = *(long long*)((char*)p2 + i * 8);
        *(long long*)((char*)p2 + i * 8) = n1;
    }
    i *= 8;

    if (size >= 4)
    {
        int n2 = *(int*)((char*)p1 + i);
        *(int*)((char*)p1 + i) = *(int*)((char*)p2 + i);
        *(int*)((char*)p2 + i) = n2;
        size -= 4;
        i += 4;
    }

    if (size >= 2)
    {
        short n3 = *(short*)((char*)p1 + i);
        *(short*)((char*)p1 + i) = *(short*)((char*)p2 + i);
        *(short*)((char*)p2 + i) = n3;
        size -= 2;
        i += 2;
    }

    if (size >= 1)
    {
        char n4 = *((char*)p1 + i);
        *((char*)p1 + i) = *((char*)p2 + i);
        *((char*)p2 + i) = n4;
        size -= 1;
        i += 1;
    }

    return 0;

/*
    char ch = 0;
    for (size_t i = 0; i < size; ++i)
    {
        ch = *((char*)x + i);
        *((char*)x + i) = *((char*)y + i);
        *((char*)y + i) = ch;
    }

    return 0;    */
}
