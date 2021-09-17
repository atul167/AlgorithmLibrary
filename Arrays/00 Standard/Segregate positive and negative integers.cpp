// https://www.techiedelight.com/positive-and-negative-integers-segregate/

/*
Input:  [9, -3, 5, -2, -8, -6, 1, 3]
Output: [-3, -2, -8, -6, 5, 9, 1, 3]

We can solve this problem in linear time by using the partitioning logic of Quicksort (https://www.techiedelight.com/quicksort)
The idea is to use 0 as a pivot element and make one pass of the partition process. 
The resultant array will satisfy the given constraints.

*/

#include <iostream>
#include <algorithm>
using namespace std;

void partition(int a[], int n) {
    int pIndex = 0;

    // each time we find a negative number, `pIndex` is incremented,
    // and that element would be placed before the pivot
    for (int i = 0; i < n; i++) {
        // pivot is 0 
        if (a[i] < 0) {
            swap(a[i], a[pIndex]);
            pIndex++;
        }
    }
}

int main() {
    int a[] = { 9, -3, 5, -2, -8, -6, -1, 3 };
    int n = sizeof(a) / sizeof(a[0]);

    partition(a, n);

    // print the rearranged array
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
