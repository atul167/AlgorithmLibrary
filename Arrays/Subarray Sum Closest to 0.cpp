// https://www.lintcode.com/problem/139/
// https://www.geeksforgeeks.org/find-sub-array-sum-closest-0/

/*
Given an integer array, find a subarray with sum closest to zero.
Return the indexes of the first number and last number.
Return any valid answer.

It is guaranteed that the sum of any numbers is in [-2^{31},2^{31}-1]

Example 1:
Input: [-3,1,1,-3,5] 
Output: [0, 2]
Other valid answers: [0,2], [1,3], [1,1], [2,2], [0,4]

Expected O(nlogn) time.
*/



class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    
    vector<int> subarraySumClosest(vector<int> &nums) {
        int n = nums.size();
        int min_diff = INT_MAX, left = -1, right = -1;
    
        vector<pair<int, int>> pre_sum(n + 1);
    
        // To consider the case of subarray starting from beginning of the array
        pre_sum[0] = {0, -1};
    
        int sum = 0;
        // Store prefix sum with index
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            pre_sum[i+1] = {sum, i};
        }
    
        // Sort on the basis of pref sum
        sort(pre_sum.begin(), pre_sum.end());

    
        // Find two consecutive elements with minimum difference
        for (int i = 0; i < n; i++) {
            int diff = pre_sum[i+1].first - pre_sum[i].first;
    
            if (min_diff > diff) {
                min_diff = diff;
                left = min(pre_sum[i].second, pre_sum[i+1].second);
                right = max(pre_sum[i].second, pre_sum[i+1].second);
            }
        }

        if(left == -1 && right == -1) return {0, 0};
        return {left + 1, right};
    }
};
