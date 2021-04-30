#include "includes/merge_sort.hpp"
#include "includes/order_statistic_set.hpp"
#include <iostream>

using namespace std;

int main() {
    int n, *arr;
    cin >> n;

    arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long invCnt1 = 0, invCnt2 = 0;
    // order_statistic_set mySet;
    // for (int i = n; i >= 0; i--) {
    //     invCnt1 += mySet.lowerBound(arr[i]);
    //     mySet.insert(arr[i]);
    // }

    mergeSort(arr, 0, n - 1, invCnt2);
    cout << invCnt2 << endl;
    return 0;
}