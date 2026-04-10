#include <iostream>
using namespace std;

struct myType
{
    int value;

    bool operator<(myType &other) const
    {
        return value < other.value;
    };
};

template <typename T>
T clamp(T val, T lo, T hi)
{
    if (val < lo)
        return lo;

    if (hi < val)
        return hi;

    return val;
};

int main()
{
    cout << clamp<int>(12, 10, 20) << endl;
    cout << clamp("hello", "hi", "noo") << endl;

    myType val = {25};
    myType low = {10};
    myType high = {20};

    myType result = clamp(val, low, high);
    cout << "Clamped custom type: " << result.value << endl;
}