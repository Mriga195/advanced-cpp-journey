#include <iostream>
#include <ranges>
#include <vector>
using namespace std;

int main()
{
    auto pipe = views::iota(1) | views::filter([](int a)
                                               { return a % 2 == 0; }) |
                views::transform([](int a)
                                 { return a * a; }) |
                views::take(5);

    for (int n : pipe)
    {
        cout << n << " ";
    }

    cout << endl;
}