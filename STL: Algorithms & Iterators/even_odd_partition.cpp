#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> v{23, 34, 23, 4, 234, 55, 32, 01, 354};

    auto even_end = partition(v.begin(), v.end(), [](int a)
                              { return a % 2 == 0; });

    auto max_ele_iter = max_element(v.begin(), even_end);

    rotate(v.begin(), max_ele_iter, even_end);

    for (auto &ele : v)
        cout << ele << " ";

    cout << endl;
}