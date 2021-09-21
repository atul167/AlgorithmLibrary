// https://leetcode.com/problems/arithmetic-slices/
// https://youtu.be/rSi4MpGEz1M

/*
An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.
Given an integer array nums, return the number of arithmetic subarrays of nums.

Example 1:
Input: nums = [1,2,3,4]
Output: 3
Explanation: We have 3 arithmetic slices in nums: [1, 2, 3], [2, 3, 4] and [1,2,3,4] itself.

Example 2:
Input: nums = [1]
Output: 0
*/



class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        vector<int> dp(n, 0);

        for (int i = 2; i < n; i++) {
            int dif = nums[i] - nums[i - 1];
            if (nums[i - 1] - nums[i - 2] != dif) {
                dp[i] = 0;
            } else {
                dp[i] = dp[i - 1] + 1;
            }
        }

        int res = 0;
        for (int i = 0; i < n; i++) res += dp[i];
        return res;
    }
};
