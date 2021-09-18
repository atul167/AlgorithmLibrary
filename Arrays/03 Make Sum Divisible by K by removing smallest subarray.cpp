// https://leetcode.com/problems/make-sum-divisible-by-p/
// https://www.geeksforgeeks.org/length-of-smallest-subarray-to-be-removed-to-make-sum-of-remaining-elements-divisible-by-k/

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
    int minSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        // Remainder when total_sum is divided by K
        int total_sum_rem = 0;
        for (int i = 0; i < n; i++) {
            total_sum_rem = (total_sum_rem + nums[i]) % k;
        }

        // If given array is already divisible by K
        if (total_sum_rem == 0) return 0;

        // Stores curr_remainder and the most recent index at which curr_remainder has occured
        unordered_map<int, int> mp;
        mp[0] = -1;

        int curr_remainder = 0;

        // Stores required answer
        int res = n;

        for (int i = 0; i < n; i++) {
            curr_remainder = (curr_remainder + nums[i]) % k;

            // Update current remainder index
            mp[curr_remainder] = i;

            int mod = (curr_remainder - total_sum_rem + k) % k;

            // If mod already exists in map the subarray exists
            if (mp.count(mod)) res = min(res, i - mp[mod]);
        }

        return res < n ? res : -1;
    }
};

















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
