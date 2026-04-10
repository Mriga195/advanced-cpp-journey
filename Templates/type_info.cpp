#include <iostream>
using namespace std;

template <typename T>
struct TypeInfo
{
    static string name()
    {
        return "Generic";
    }
};

template <>
struct TypeInfo<int>
{
    static string name()
    {
        return "int";
    };
};

template <>
struct TypeInfo<double>
{
    static string name()
    {
        return "double";
    };
};

template <>
struct TypeInfo<char>
{
    static string name()
    {
        return "char";
    };
};

int main()
{
    cout << TypeInfo<float>::name() << endl;
    cout << TypeInfo<int>::name() << endl;
    cout << TypeInfo<char>::name() << endl;
    cout << TypeInfo<double>::name() << endl;
}