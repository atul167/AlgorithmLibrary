// https://youtu.be/COk73cpQbFQ
// https://www.geeksforgeeks.org/quick-sort/
// https://www.geeksforgeeks.org/cpp-program-for-quicksort/

/*
Worst Case: O(n^2)
Average Case: O(nlogn)
Best Case: O(nlogn)
*/

#include<bits/stdc++.h>
using namespace std;

/*
This function takes last element as pivot,
places the pivot element at its correct position in sorted array,
and places all smaller (smaller than pivot) to left of pivot
and all greater elements to righ of pivot 
*/
int partition(vector<int>& arr, int start, int end) {
    int pivot = arr[end];
    int pIndex = start;

    for (int i = start; i <= end - 1; i++) {
        // If current element is smaller than or equal to pivot
        if (arr[i] <= pivot) {
            swap(arr[i], arr[pIndex]);
            pIndex++;
        }
    }
    swap(arr[end], arr[pIndex]);
    return pIndex;
}

void quickSort(vector<int>& arr, int start, int end) {
    if (start < end) {
        // pi is partitioning index
        int pi = partition(arr, start, end);
        // arr[pi] is now at right place
        // separately sort elements before partition and after partition
        quickSort(arr, start, pi - 1);
        quickSort(arr, pi + 1, end);
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] <<  " ";
    }
}
