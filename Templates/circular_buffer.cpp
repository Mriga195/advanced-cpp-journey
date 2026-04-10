#include <iostream>
using namespace std;

struct myType
{
    int value;

    bool operator<(const myType &other) const
    {
        return value < other.value;
    };
};

template <typename T, int N>
class CircularBuffer
{
    T data[N];
    int size{0};
    int head{0};
    int tail{0};

public:
    void push(T val)
    {
        if (size == N)
        {
            cout << "buffer is full" << endl;
            return;
        }

        data[head] = val;
        head = (head + 1) % N;
        size++;
    }

    T pop()
    {
        if (size == 0)
        {
            cout << "buffer is empty" << endl;
            return T{};
        }

        size--;
        T store = data[tail];
        tail = (tail + 1) % N;
        return store;
    }

    bool full()
    {
        if (size == N)
            return true;

        return false;
    }

    bool empty()
    {
        if (size == 0)
            return true;

        return false;
    }
};

int main()
{
    CircularBuffer<int, 3> buffer;
    cout << "Is empty? " << boolalpha << buffer.empty() << "\n";

    buffer.push(10);
    buffer.push(20);
    buffer.push(30);
    cout << "Is full? " << buffer.full() << "\n";

    cout << "Popped: " << buffer.pop() << "\n";

    buffer.push(40);

    cout
        << "Popped after wrap: " << buffer.pop() << "\n";

    CircularBuffer<myType, 2> customBuffer;
    customBuffer.push({100});
    cout << "Custom Type Val: " << customBuffer.pop().value << "\n";

    return 0;
}