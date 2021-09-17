// https://leetcode.com/problems/make-sum-divisible-by-p/

/*
Given an array of positive integers nums, remove the smallest subarray (possibly empty) 
such that the sum of the remaining elements is divisible by p. 
It is not allowed to remove the whole array.
Return the length of the smallest subarray that you need to remove, or -1 if it's impossible.

Example 1:
Input: nums = [3,1,4,2], p = 6
Output: 1
Explanation: The sum of the elements in nums is 10, which is not divisible by 6. 
We can remove the subarray [4], and the sum of the remaining elements is 6, which is divisible by 6.
*/


class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size(), res = n, need = 0, cur = 0;
        for (int x: nums) need = (need + x) % p;
        
        unordered_map<int, int> last;
        last[0] = -1;
        
        for (int i = 0; i < n; ++i) {
            cur = (cur + nums[i]) % p;
            last[cur] = i;
            int want = (cur - need + p) % p;
            if (last.count(want))
                res = min(res, i - last[want]);
        }
        return res < n ? res : -1;
    }
};
