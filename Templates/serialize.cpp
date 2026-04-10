#include <type_traits>
#include <string>
#include <iostream>
using namespace std;

template <typename T>
string serialize(T val)
{
    if constexpr (is_arithmetic_v<T>)
        return to_string(val);
    else
        return "[non-scalar]";
};

int main()
{
    cout << serialize("lol") << endl;
    cout << serialize(1.5) << endl;
    cout << serialize(100) << endl;
    cout << serialize('f') << endl;
}