#ifndef STL_sorts_
#define STL_sorts_

#include <stdio.h>

int BubbleSort (void* data, size_t nElem, size_t elemSize,
                int Compare (const void* x, const void* y));

int Swap (void* x, void* y, size_t size);

#endif
