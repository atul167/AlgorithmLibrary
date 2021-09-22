// https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/

/*
Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. 
If there is no such subarray, return -1.


Example 1:
Input: nums = [1], k = 1
Output: 1

Example 2:
Input: nums = [1,2], k = 4
Output: -1

Example 3:
Input: nums = [2,-1,2], k = 3
Output: 3
 

Constraints:
1 <= nums.length <= 10^5
-10^5 <= nums[i] <= 10^5
1 <= k <= 10^9
*/


/*
// https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/discuss/143726/C%2B%2BJavaPython-O(N)-Using-Deque

What makes this problem hard is that we have negative values (otherwise we could have used sliding window or binary search).
*/


class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int res = n + 1;
        deque<int> d;

        for (int i = 0; i < n; i++) {
            if (i > 0) nums[i] += nums[i - 1];

            if (nums[i] >= k) res = min(res, i + 1);

            while (d.size() > 0 && nums[i] - nums[d.front()] >= k) {
                res = min(res, i - d.front());
                d.pop_front();
            }
            while (d.size() > 0 && nums[i] <= nums[d.back()]) {
                d.pop_back();
            }

            d.push_back(i);
        }
        return res <= n ? res : -1;
    }
};
