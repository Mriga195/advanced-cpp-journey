#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

struct Range
{
private:
    int m_start;
    int m_end;

public:
    Range(int start, int end)
    {
        this->m_end = end;
        this->m_start = start;
    }

    struct Iterator
    {
    public:
        using iterator_category = forward_iterator_tag;
        using value_type = int;
        using difference_type = ptrdiff_t;
        using pointer = int *;
        using reference = int &;
        int iter;
        Iterator(int val)
        {
            iter = val;
        }

        Iterator &operator++()
        {
            iter++;
            return *this;
        };

        int operator*()
        {
            return iter;
        }

        bool operator!=(const Iterator &other)
        {
            return this->iter != other.iter;
        }

        bool operator==(const Iterator &other)
        {
            return this->iter == other.iter;
        }
    };

    Iterator begin()
    {
        return Iterator(m_start);
    };

    Iterator end()
    {
        return Iterator(m_end);
    };
};

int main()
{
    Range range(1, 11);

    cout << "Range-based for loop: ";
    for (int i : range)
    {
        cout << i << " ";
    }

    cout << "\nfor_each: ";
    for_each(range.begin(), range.end(), [](int n)
             { cout << n * 10 << " "; });

    cout << endl;
}