#include <iostream>
#include <functional>
#include <vector>

using namespace std;

template <typename T>
class Pipeline
{
private:
    vector<function<T(T)>> fnArr;

public:
    void add_step(function<T(T)> fn)
    {
        fnArr.push_back(fn);
    }

    T execute(T initialValue)
    {
        T temp = initialValue;

        for (int i{0}; i < fnArr.size(); i++)
        {
            temp = fnArr[i](temp);
        }

        return temp;
    }
};

int main()
{
    Pipeline<int> p;

    for (int i{0}; i < 3; i++)
    {
        p.add_step([i](int x) -> int
                   { return (x + i); });
    }

    cout << p.execute(0) << endl;
}