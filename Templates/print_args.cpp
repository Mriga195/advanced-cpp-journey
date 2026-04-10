#include <iostream>
using namespace std;

template <typename... T>
void print(T... args)
{
    ((cout << args << " | "), ...) << endl;
}

int main()
{
    print(1, 2, 3, "hello");
}