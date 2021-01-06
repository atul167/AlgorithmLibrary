// https://leetcode.com/problems/largest-divisible-subset/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        
        if(n==0)
            return ans;
        
        sort(nums.begin(), nums.end());
        
        int mx = 1;
        vector<int> dp(n+1, 1);
        
        for(int i=1; i < n; ++i) {
            for(int j=0; j < i; ++j) {
                if(nums[i] % nums[j] == 0){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            mx = max(mx, dp[i]);
        }
        
        //Now push the answer LIS
        int prev = -1;
        for(int i = n-1; i >= 0; i--) {
            if(dp[i] == mx &&  (prev % nums[i] == 0 || prev==-1)) {
                ans.push_back(nums[i]);
                mx -= 1;
                prev = nums[i];
            }
        }
        return ans;
    }
};
