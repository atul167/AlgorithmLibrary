// https://www.geeksforgeeks.org/find-m-th-smallest-value-in-k-sorted-arrays/

/*
Given k sorted arrays of possibly different sizes, find m-th smallest value in the merged array.

Input: 
m = 5     
arr[][] = { {1, 3},
            {2, 4, 6},
            {0, 9, 10, 11}};
Output: 4
Explanation The merged array would be {0 1 2 3 4 6 9 10 11}.  The 5-th smallest element in this merged array is 4.

Input: 
m = 2
arr[][] = { {1, 3, 20},
            {2, 4, 6}};
Output: 2
Explanation The merged array would be {1 2 3 4 6 20}. The 2nd smallest element would be 2. 
*/


#include <bits/stdc++.h>
using namespace std;


int mergeKArrays(vector<vector<int> > arr, int m) {
    int res;

    // Create a min heap with k heap nodes.
    // Every heap node has first element of an array
    // {value, index of array,  index in the array}
    // {arr[i][j], i,  j}
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>> > pq;

    for (int i = 0; i < arr.size(); i++) {
        pq.push({ arr[i][0], i, 0 });
    }

    // Now one by one get the minimum element from min heap and replace it with next element of its array
    while (!pq.empty() && m--) {
        auto cur = pq.top();
        pq.pop();

        // i ==> Array Number
        // j ==> Index in the array number
        int i = cur[1];
        int j = cur[2];

        res = cur[0];

        // The next element belongs to same array as current.
        if (j + 1 < arr[i].size()) {
            pq.push({ arr[i][j + 1], i, j + 1 });
        }
    }

    return res;
}

int main() {
    vector<vector<int> > arr = { {1, 3},
        {2, 4, 6},
        {0, 9, 10, 11}
    } ;
    int m = 5;
    cout << mergeKArrays(arr, m);
    return 0;
}
