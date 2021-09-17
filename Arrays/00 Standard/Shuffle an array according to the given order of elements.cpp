// https://www.techiedelight.com/shuffle-array-according-to-given-order/



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to shuffle an array according to the given order of elements
void shuffle(auto &arr, auto &pos) {
    // traverse the array from left to right
    for (int i = 0; i < arr.size(); i++) {
        // loop till the current set is swapped
        while (pos[i] != i) {
            // update `arr[]` and `pos[]` with the correct order of elements
            swap(arr[pos[i]], arr[i]);
            swap(pos[pos[i]], pos[i]);
        }
    }
}

int main() {
    vector<int> arr = { 1, 2, 3, 4, 5 };    // input array
    vector<int> pos = { 3, 2, 4, 1, 0 };    // position array

    shuffle(arr, pos);

    for (int i : arr) {
        cout << i << " ";
    }

    return 0;
}































#include <stdio.h>

// Function to shuffle an array according to the given order of elements
void shuffle(int arr[], int pos[], int n) {
    // create an auxiliary array of size `n`
    int aux[n];

    // fill the auxiliary array with the correct order of elements
    for (int i = 0; i < n; i++) {
        aux[pos[i]] = arr[i];
    }

    // copy the auxiliary array back to the given array
    for (int i = 0; i < n; i++) {
        arr[i] = aux[i];
    }
}

int main(void) {
    // input array
    int arr[] = { 1, 2, 3, 4, 5 };

    // position array
    int pos[] = { 3, 2, 4, 1, 0 };

    int n = sizeof(arr) / sizeof(arr[0]);

    shuffle(arr, pos, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
