#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <string>
using namespace std;

int main()
{
    vector<tuple<string, int, double>> arr = {
        {"A", 50, 10.5},  // Tie 1 with B
        {"B", 20, 10.5},  // Tie 1 with A (B should come first if sorting int asc)
        {"C", 100, 99.9}, // Highest double (should be first)
        {"D", 15, 5.2},   // Lowest double (should be last)
        {"E", 30, 10.5},  // Tie 1 with A and B
        {"F", 10, 25.0},
        {"G", 80, 25.0}, // Tie 2 with F
        {"H", 5, 12.0},
        {"I", 60, 7.5},
        {"J", 40, 10.5} // Tie 1 with A, B, E
    }; // ai generated dummy data

    sort(arr.begin(), arr.end(), [](tuple<string, int, double> &a, tuple<string, int, double> &b)
         {
             if (get<2>(a) == get<2>(b)) 
                return get<1>(a) < get<1>(b);
            
            return get<2>(a) > get<2>(b); });

    for (auto ele : arr)
    {
        cout << get<0>(ele) << " " << get<1>(ele) << " " << get<2>(ele) << endl;
    }
}