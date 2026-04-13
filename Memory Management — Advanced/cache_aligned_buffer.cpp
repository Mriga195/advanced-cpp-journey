#include <iostream>
#include <array>
using namespace std;

int main()
{
    alignas(64) array<int, 10> arr;

    for (int i{0}; i < 10; i++)
    {
        int temp;
        cin >> temp;
        arr[i] = temp;
    }

    cout << alignof(arr) << endl;

    cout << &arr << endl;
}