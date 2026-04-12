#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;

double innerProduct(vector<double> &v1, vector<double> &v2)
{
    return inner_product(v1.begin(), v1.end(), v2.begin(), 0.0);
};

double transformReduceProduct(vector<double> &v1, vector<double> &v2)
{

    vector<double> store(v1.size());
    transform(v1.begin(), v1.end(), v2.begin(), store.begin(), [](double a, double b)
              { return a * b; });

    return reduce(store.begin(), store.end(), 0.0);
};

int main()
{
    vector<double> v1{1, 2, 3, 4, 5};
    vector<double> v2{1, 2, 3, 4, 5};

    double inner_product = innerProduct(v1, v2);
    cout << "using inner_product: " << inner_product << endl;

    double transform_reduce_product = transformReduceProduct(v1, v2);
    cout << "using transform and reduce: " << transform_reduce_product << endl;
}