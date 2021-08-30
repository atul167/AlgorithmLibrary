// https://www.geeksforgeeks.org/maximum-sum-rectangle-in-a-2d-matrix-dp-27/
// https://youtu.be/yCQN096CwWM

// Time = O(n^3)
#include <bits/stdc++.h>
using namespace std;
 
int n, m;

int kadane(vector<int>& arr, int& start, int& finish) {
    // initialize sum, maxSum and
    int sum = 0, maxSum = INT_MIN, i;
 
    // Just some initial value to check for all negative values case
    finish = -1;
 
    // local variable
    int local_start = 0;
 
    for (i = 0; i < n; ++i) {
        sum += arr[i];
        if (sum < 0) {
            sum = 0;
            local_start = i + 1;
        } else if (sum > maxSum) {
            maxSum = sum;
            start = local_start;
            finish = i;
        }
    }
 
    // There is at-least one non-negative number
    if (finish != -1) return maxSum;
 
    // Special Case: When all numbers in arr[] are negative
    maxSum = arr[0];
    start = finish = 0;
 
    // Find the maximum element in array
    for (i = 1; i < n; i++) {
        if (arr[i] > maxSum) {
            maxSum = arr[i];
            start = finish = i;
        }
    }
    return maxSum;
}
 
void findMaxSum(vector<vector<int>>& matrix) {
    int maxSum = INT_MIN;
    int maxLeft, maxRight, maxTop, maxBottom;
 
    int left, right, start, finish;
    vector<int> arr;
 
    for (left = 0; left < m; ++left) {
        arr = vector<int>(n, 0);
 
        for (right = left; right < m; ++right) {

            for (int i = 0; i < n; ++i) {
                arr[i] += matrix[i][right];
            }
 
            int curSum = kadane(arr, start, finish);
 
            if (curSum > maxSum) {
                maxSum = curSum;
                maxLeft = left;
                maxRight = right;
                maxTop = start;
                maxBottom = finish;
            }
        }
    }
 
    cout << "(Top, Left) (" << maxTop << ", " << maxLeft << ")" << endl;
    cout << "(Bottom, Right) (" << maxBottom << ", " << maxRight << ")" << endl;
    cout << "Max sum is: " << maxSum << endl;
}
 
int main() {
    vector<vector<int>> matrix = { { 1, 2, -1, -4, -20 },
                                 { -8, -3, 4, 2, 1 },
                                 { 3, 8, 10, 1, 3 },
                                 { -4, -1, 1, 7, -6 } };
    n = matrix.size(), m = matrix[0].size();
    findMaxSum(matrix);
    return 0;
}




























class Solution {
public:
    int n, m;
    
    int kadane(vector<int>& arr, int& start, int& finish) {
        // initialize sum, maxSum and
        int sum = 0, maxSum = INT_MIN, i;
     
        // Just some initial value to check for all negative values case
        finish = -1;
     
        // local variable
        int local_start = 0;
     
        for (i = 0; i < n; ++i) {
            sum += arr[i];
            if (sum < 0) {
                sum = 0;
                local_start = i + 1;
            } else if (sum > maxSum) {
                maxSum = sum;
                start = local_start;
                finish = i;
            }
        }
     
        // There is at-least one non-negative number
        if (finish != -1) return maxSum;
     
        // Special Case: When all numbers in arr[] are negative
        maxSum = arr[0];
        start = finish = 0;
     
        // Find the maximum element in array
        for (i = 1; i < n; i++) {
            if (arr[i] > maxSum) {
                maxSum = arr[i];
                start = finish = i;
            }
        }
        return maxSum;
    }
    
    int maximumSumRectangle(int n, int m, vector<vector<int>> matrix) {
        this->n = n, this->m = m;
        int maxSum = INT_MIN;
        int maxLeft, maxRight, maxTop, maxBottom;
     
        int left, right, start, finish;
        vector<int> arr;
     
        for (left = 0; left < m; ++left) {
            arr = vector<int>(n, 0);
     
            for (right = left; right < m; ++right) {
                for (int i = 0; i < n; ++i) {
                    arr[i] += matrix[i][right];
                }
     
                int curSum = kadane(arr, start, finish);
     
                if (curSum > maxSum) {
                    maxSum = curSum;
                    maxLeft = left;
                    maxRight = right;
                    maxTop = start;
                    maxBottom = finish;
                }
            }
        }
     
        return maxSum;
    }
};
