// https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/dynamic-programming/k-concatenation-official/ojquestion
// https://youtu.be/qnoOu5Usb4o


/*
Given an integer array arr and an integer k, modify the array by repeating it k times.
For example, if arr = [1, 2] and k = 3 then the modified array will be [1, 2, 1, 2, 1, 2].
Return the maximum sub-array sum in the modified array.

Example 1:
Input: arr = [1,2], k = 3
Output: 9

Example 2:
Input: arr = [1,-2,1], k = 5
Output: 2
*/


#include <bits/stdc++.h>
using namespace std;

// int kadanes(vector<int>& arr) {
//     int maxEndingHere = 0, maxSoFar = INT_MIN;
//     for (int i = 0; i < arr.size(); i++) {
//         maxEndingHere += arr[i];
//         maxSoFar = max(maxSoFar, maxEndingHere);
//         if (maxEndingHere < 0) maxEndingHere = 0;
//     }
//     return maxSoFar;
// }

int kadanes(vector<int>& arr) {
    int cur = 0, res = INT_MIN;
    for (int i = 0; i < arr.size(); i++) {
        cur = max(arr[i], cur + arr[i]);
        res = max(res, cur);
    }
    return res;
}

int kConcatenationMaxSum(vector<int>& arr, int k) {
    // case 1:
    if (k == 1) {
        return kadanes(arr);
    }

    int sum = 0;
    for (int x : arr) {
        sum += x;
    }

    // generate tempArr = arr + arr
    vector<int> tempArr(arr.begin(), arr.end());
    for (int x : arr) tempArr.push_back(x);

    // case 2:
    if (sum < 0) {
        return kadanes(tempArr);
    }

    // case 3:
    return kadanes(tempArr) + (k - 2) * sum;
}

int main() {
    int n, k;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> k;
    cout << kConcatenationMaxSum(a, k) << endl;
}
