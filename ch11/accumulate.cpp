#include "ch11.h"

template<class T>
T sum(T a[], int n);

template<class T>
T product(T a[], int n);

template<class T>
T custom(T a[], int n);

void accumulateDemo()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n1 = sum(arr, sizeof(arr) / sizeof(int));
    int n2 = product(arr, sizeof(arr) / sizeof(int));
    int n3 = custom(arr, sizeof(arr) / sizeof(int));
    cout << "result=" << n1 << endl;
    cout << "result=" << n2 << endl;
    cout << "result=" << n3 << endl;
}

/**
 * 计算累加和
 * @tparam T
 * @param a
 * @param n
 * @return
 */
template<class T>
T sum(T a[], int n)
{
    T theSum = 0;
    return accumulate(a, a + n, theSum);
}

/**
 * 计算乘积
 * @tparam T
 * @param a
 * @param n
 * @return
 */
template<class T>
T product(T a[], int n)
{
    T theProduct = 1;
    return accumulate(a, a + n, theProduct, multiplies<T>());
}

/**
 * 自定处理求和，条件如下
 * 1.如果是偶数，则当前元素*2；
 * 2.如果不是偶数，则当前元素+1；
 * @tparam E
 */
template<typename E>
struct customFunc : public binary_function<E, E, E>
{
    // _GLIBCXX14_CONSTEXPR
    E
    // prev 代表上一次的元素，第一次为指定的初始值
    // item 代表当前元素
    operator()(const E &prev, const E &item) const
    {
        // 等价于 item%2 != 0
        if (item % 2)
        {
            return prev + (item + 1);
        } else
        {
            return prev + item * 2;
        }
    }
};

template<class T>
T custom(T a[], int n)
{
    T theCustom = 0;
    return accumulate(a, a + n, theCustom, customFunc<T>());
}