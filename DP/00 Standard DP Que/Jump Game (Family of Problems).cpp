// https://leetcode.com/problems/jump-game/
// https://leetcode.com/problems/jump-game-ii/

/*
Jump game I:
You are given an integer array nums. You are initially positioned at the array's first index, 
and each element in the array represents your maximum jump length at that position.
Return true if you can reach the last index, or false otherwise.
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxIndex = 0;
        
        for(int i = 0; i < n; i++) {
            if(i > maxIndex) {
                return false;
            }
            int reach = i + nums[i];
            maxIndex = max(maxIndex, reach);
        }
        return true;
    }
};








// Jump game II
/*
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.
You can assume that you can always reach the last index.
*/

// Method 1
class Solution {
public:
    int INF = 1e9;
    
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INF);
        dp[0] = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) continue;
            for(int j = 1; j <= nums[i]; j++) {
                if(i + j >= n) break;
                dp[i + j] = min(dp[i + j], dp[i] + 1);
            }
        }
        return dp[n-1];
    }
};

// Method 2
class Solution {
public:
    int INF = 1e9;
    int n;
    
    int go(int pos, vector<int>& jump, vector<int>& dp) {
        if(pos == n - 1) {
            return 0;
        }
        if(pos >= n || jump[pos] == 0) {
            return INF;
        }
        
        if(dp[pos] != -1) return dp[pos];

        int res = INF;
        for(int i = 1; i <= jump[pos]; i++) {
            res = min(res, 1 + go(pos + i, jump, dp));
        }

        return dp[pos] = res;
    }
    
    int jump(vector<int>& nums) {
        n = nums.size();
        vector<int> dp(n+5, -1);
        return go(0, nums, dp);
    }
};


// Method 3
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0, curEnd = 0, curFar = 0;
        
        for(int i = 0; i < n - 1; i++) {
            curFar = max(curFar, i + nums[i]);
            if(i == curEnd) {
                jumps++;
                curEnd = curFar;
            }
            if(curEnd >= n-1) {
                break;
            }
        }
        
        if(curEnd < n-1) return -1;
        return jumps;
    }
};
