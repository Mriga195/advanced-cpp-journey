#include <iostream>
#include <array>
using namespace std;

int main()
{
    array<int (*)(int, int), 256> fnArr{nullptr};

    fnArr['+'] = [](int a, int b)
    {
        return a + b;
    };

    fnArr['-'] = [](int a, int b)
    {
        return a - b;
    };

    fnArr['*'] = [](int a, int b)
    {
        return a * b;
    };

    fnArr['/'] = [](int a, int b)
    {
        return a / b;
    };

    cout << fnArr['*'](3, 4) << endl;
}