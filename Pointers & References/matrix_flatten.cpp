#include <iostream>
using namespace std;

int *matrixFlatten(int **mat, int r, int c)
{
    int *arr = new int[r * c];
    int counter{0};

    for (int i{0}; i < r; ++i)
    {
        for (int j{0}; j < c; ++j)
        {
            *(arr + (i * c + j)) = *(*(mat + i) + j);
        }
    }

    return arr;
}

int main()
{
    int r, c;
    cin >> r >> c;
    int **mat = new int *[r];

    for (int i{0}; i < r; i++)
    {
        *(mat + i) = new int[c];

        for (int j{0}; j < c; ++j)
            cin >> *(*(mat + i) + j);
    }

    int *arr = matrixFlatten(mat, r, c);

    for (int i{0}; i < r * c; ++i)
        cout << *(arr + i) << " ";
    cout << endl;

    delete[] arr;

    for (int i{0}; i < r; i++)
        delete[] *(mat + i);

    delete[] mat;
}