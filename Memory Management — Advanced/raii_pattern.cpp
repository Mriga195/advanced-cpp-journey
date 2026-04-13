#include <iostream>
#include <cstdio>
#include <stdexcept>
using namespace std;

struct FileHandle
{
    FILE *file;

    FileHandle(const char *path)
    {
        file = fopen(path, "r");
        if (!file)
            throw runtime_error("Failed to open this file.");
    };

    ~FileHandle()
    {
        if (file)
            fclose(file);
    };

    FileHandle(const FileHandle &) = delete;
    FileHandle &operator=(const FileHandle &) = delete;
};

void process()
{
    FileHandle f("data.txt");

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), f.file))
    {
        printf("%s", buffer);
    }

    throw runtime_error("Something went wrong");
}

int main()
{
    try
    {
        process();
    }
    catch (const exception &e)
    {
        printf("Caught: %s\n", e.what());
    }
    return 0;
}