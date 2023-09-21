#ifndef STL_fread_
#define STL_fread_

// size_t is cringe (non Denis)
struct String
{
    char* str;
    long long len; // size_t ssize_t
};

// int x;       x++ UB
// unsigned x;  x++ overflow
  /*
void log(int x)
{
    assert(x > 0);
}

void log(unsigned x)
{
}*/

struct File
{
    const char* name;
    FILE* fp;
    char* text;
    long long size;
    long long nLines;
    String* strings;
};

char* stl_Fread (File* file);

String* stl_SplitFileIntoLines (struct File* file, const char* name);

#endif
