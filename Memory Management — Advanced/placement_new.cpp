#include <iostream>
#include <new>
using namespace std;

class ArenaAllocator
{
private:
    alignas(1024) char buffer[1024];
    size_t current_offset = 0;

public:
    template <typename T>
    T *allocate()
    {
        int alignment = alignof(T);
        size_t misalignment = current_offset % alignment;
        size_t padding = (misalignment == 0) ? 0 : (alignment - misalignment);

        if (current_offset + padding + sizeof(T) >= 1024)
            return nullptr;

        current_offset += padding;

        void *raw_address = &buffer[current_offset];
        T *constructed_object = new (raw_address) T();

        current_offset += sizeof(T);

        return constructed_object;
    };
};

int main()
{
    ArenaAllocator arena;

    int *my_int = arena.allocate<int>();
    if (my_int)
    {
        *my_int = 42;
        cout << "Value: " << *my_int << " at " << my_int << endl;
    }

    double *my_double = arena.allocate<double>();
    if (my_double)
    {
        *my_double = 3.14159;
        cout << "Value: " << *my_double << " at " << my_double << endl;
    }
}