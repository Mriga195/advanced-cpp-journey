#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <iterator>
#include <chrono>
using namespace std;

int main()
{
    vector<int> v(10000000, 5);
    deque<int> d(10000000, 5);
    list<int> l(10000000, 5);

    auto v_start = chrono::high_resolution_clock::now();
    v.insert(v.begin() + v.size() / 2, 10);
    auto v_end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> v_time = v_end - v_start;

    auto d_start = chrono::high_resolution_clock::now();
    d.insert(d.begin() + d.size() / 2, 10);
    auto d_end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> d_time = d_end - d_start;

    auto l_start = chrono::high_resolution_clock::now();
    l.insert(next(l.begin(), l.size() / 2), 10);
    auto l_end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> l_time = l_end - l_start;

    cout << "vector: " << v_time.count() << endl;
    cout << "deque: " << d_time.count() << endl;
    cout << "list: " << l_time.count() << endl;
}