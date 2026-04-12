#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v{1, 5, 2, 3, 5, 1, 4, 2, 5, 3, 10, 1};
    set<int> s;

    for (const int &val : v)
        s.insert(val);

    sort(v.begin(), v.end());

    auto it = unique(v.begin(), v.end());

    v.erase(it, v.end());

    for (const int &val : s)
        cout << val << " ";

    cout << endl;

    for (const int &val : v)
        cout << val << " ";

    cout << endl;
}