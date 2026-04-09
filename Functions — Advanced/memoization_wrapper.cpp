#include <iostream>
#include <functional>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<int, int> cache;
    function<int(int)> wrapper;

    wrapper = [&cache, &wrapper](int n)
    {
        if (n == 1 || n == 0)
            return n;
        if (cache.find(n) != cache.end())
        {
            return cache[n];
        }

        cache[n] = wrapper(n - 1) + wrapper(n - 2);

        return cache[n];
    };

    cout << wrapper(10) << endl;
}