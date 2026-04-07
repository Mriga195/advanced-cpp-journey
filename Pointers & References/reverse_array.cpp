#include <iostream>
#include <vector>
using namespace std;

void reverse_array(int *begin, int *end)
{
    int size{0};
    int *iter{begin};

    for (; iter != end; ++iter)
        size++;

    for (int i{0}; i < size / 2; i++)
    {
        int temp = *(begin + i);
        *(begin + i) = *(begin + size - 1 - i);
        *(begin + size - 1 - i) = temp;
    }
}

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i{0}; i < n; ++i)
        cin >> arr[i];

    for (int i{0}; i < n; ++i)
        cout << arr[i] << " ";

    cout << endl;

    reverse_array(arr, arr + n);

    for (int i{0}; i < n; ++i)
        cout << arr[i] << " ";

    cout << endl;
}