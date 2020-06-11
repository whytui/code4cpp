#include "ch11.h"

template<class T>
T sum(T a[], int n);

void findA()
{
    int arr[] = {1, 2, 3, 4, 5};
    int result = sum(arr, 4);
    cout << "result=" << result << endl;
}

template<class T>
T sum(T a[], int n)
{
    T theSum = 0;
    return accumulate(a, a + n, theSum);
}