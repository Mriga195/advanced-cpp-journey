#include <iostream>
using namespace std;

void generic_swap(int *n1, int *n2)
{
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void generic_swap(int &n1, int &n2)
{
    int temp = n1;
    n1 = n2;
    n2 = temp;
}

int main()
{
    int n1, n2;
    cin >> n1 >> n2;

    generic_swap(&n1, &n2);
    cout << n1 << " " << n2 << endl;

    generic_swap(n1, n2);
    cout << n1 << " " << n2 << endl;
}