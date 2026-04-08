#include <iostream>
#include <memory>
#include <utility>
using namespace std;

class Node
{
public:
    int data;
    unique_ptr<Node> next = nullptr;

    Node(int data)
    {
        this->data = data;
    }
};

class LinkedList
{
    unique_ptr<Node> head = nullptr;

public:
    void insert(int data)
    {
        auto store = make_unique<Node>(data);

        if (!head)
        {
            head = move(store);
            return;
        }

        Node *iter = head.get();

        while (iter->next != nullptr)
            iter = iter->next.get();

        iter->next = move(store);
    }

    void remove()
    {
        if (!head)
            return;

        if (!head->next)
        {
            head.reset();
            return;
        }

        Node *iter = head.get();

        while (iter->next->next)
            iter = iter->next.get();

        iter->next.reset();
        iter->next = nullptr;
    }

    void print()
    {

        Node *iter = head.get();

        while (iter)
        {
            cout << iter->data << " ";
            iter = iter->next.get();
        }

        cout << endl;
    }
};
int main()
{
    int n;
    LinkedList ll;
    cin >> n;

    for (int i{0}; i < n; i++)
    {
        int temp;
        cin >> temp;

        ll.insert(temp);
    };

    ll.print();
}