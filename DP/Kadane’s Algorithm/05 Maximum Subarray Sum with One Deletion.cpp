// https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/

/*
Given an array of integers, return the maximum sum for a non-empty subarray (contiguous elements) with at most one element deletion. 
In other words, you want to choose a subarray and optionally delete one element from it 
so that there is still at least one element left and the sum of the remaining elements is maximum possible.

Note that the subarray needs to be non-empty after deleting one element.

Example 1:
Input: arr = [1,-2,0,3]
Output: 4
Explanation: Because we can choose [1, -2, 0, 3] and drop -2, thus the subarray [1, 0, 3] becomes the maximum value.

Example 2:
Input: arr = [1,-2,-2,3]
Output: 3
Explanation: We just choose [3] and it's the maximum sum.

Example 3:
Input: arr = [-1,-1,-1,-1]
Output: -1
Explanation: The final subarray needs to be non-empty. You can't choose [-1] and delete -1 from it, then get an empty subarray to make the sum equals to 0.
*/

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> maxEndHere(n), maxStartHere(n);

        int cur = 0;
        for (int i = 0; i < n; i++) {
            cur = max(arr[i], cur + arr[i]);
            maxEndHere[i] = cur;
        }
        cur = 0;
        for (int i = n - 1; i >= 0; i--) {
            cur = max(arr[i], cur + arr[i]);
            maxStartHere[i] = cur;
        }

        int res = INT_MIN;
        for (int i = 0; i < n; i++) {
            res = max({res, maxEndHere[i], maxStartHere[i]});
            if (i > 0 && i < n - 1) {
                res = max(res, maxEndHere[i - 1] + maxStartHere[i + 1]);
            }
        }
        return res;
    }
};
