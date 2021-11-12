// https://leetcode.com/problems/trapping-rain-water
// https://youtu.be/m18Hntz4go8

/*
Key point: 
For every column i we have to look at the max column height in left (0, ... i-1) and the max column height in right (i+1, ... n).
And then take the min of these two heights and subtract with the current height to get the water height at column i;
Sum these water heights for all columns;
*/



// O(n) time, O(1) space [Two pointer technique]
/*
Maintain left_max and right_max on the go using 2 pointer technique.
Always fill from lower boundary block heights [this will ensure min(left_max, right_max) to be used].
For example, if current height of left pointer is lower, we fill water in the left bin 
else if current height of right pointer is lower, we fill water in the right bin. 
Until left pointer meets right pointer, we filled the whole container.
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0) return 0;

        // maximum element on left and right sides of height[i]
        int left_max = 0, right_max = 0, res = 0;

        int lo = 0, hi = n - 1;
        
        while (lo <= hi) {
            if (height[lo] <= height[hi]) {
                if (height[lo] <= left_max) {
                    res += left_max - height[lo];
                }
                left_max = max(left_max, height[lo]);
                lo++;
            } else {
                if (height[hi] <= right_max) {
                    res += right_max - height[hi];
                }
                right_max = max(right_max, height[hi]);
                hi--;
            }
        }

        return res;
    }
};
