#include <iostream>
#include <memory>
using namespace std;

class Stack
{
    int *next = nullptr;
    int counter = 0;
    int size = 0;

public:
    Stack(int size)
    {
        next = new int[size];
        this->size = size;
    }

    void push(int data)
    {
        if (counter == size)
            return;

        *(next + counter) = data;
        counter++;
    }

    int pop()
    {
        if (counter == 0)
            return -1;

        counter--;
        return *(next + counter);
    }

    int front()
    {
        return *(next + counter - 1);
    }

    ~Stack()
    {
        delete[] next;
    }
};

int main()
{
    int size;
    cin >> size;

    Stack s1(size);

    for (int i{0}; i < size; i++)
    {
        int t;
        cin >> t;
        s1.push(t);
    }

    for (int i{0}; i < size; i++)
    {
        cout << s1.pop() << " ";
    }
    cout << endl;
};