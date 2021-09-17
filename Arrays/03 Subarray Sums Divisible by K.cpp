// https://leetcode.com/problems/subarray-sums-divisible-by-k/

/*
Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

Example 1:
Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
*/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int, int> mp;
        mp[0] = 1;
        
        int prefix = 0, res = 0;
        
        for (int x: nums) {
            prefix = (prefix + x + k) % k;
            if(prefix < 0) prefix += k;
            
            res += mp[prefix];
            mp[prefix]++;
        }
        return res;
    }
};
