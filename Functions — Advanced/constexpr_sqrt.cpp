#include <iostream>
using namespace std;

constexpr double manualSqrt(double n)
{
    if (n < 0)
        return -1;
    if (n == 0)
        return 0;

    double guess = n / 2.0;
    constexpr double precision = 0.00001;

    while ((guess * guess - n) > precision || (n - guess * guess) > precision)
    {
        guess = 0.5 * (guess + n / guess);
    }

    return guess;
}

int main()
{
    constexpr double n = 25.0;
    static_assert(manualSqrt(n) > 4.99 && manualSqrt(n) < 5.01, "Value must be approx 5");
}