// https://leetcode.com/problems/3sum

/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, 
and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.
*/




class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> res;
        
        for(int i = 0; i < n - 2; i++) {
            int l = i + 1, r = n - 1;
            
            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if(sum  == 0) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    
                    // to handle duplicates
                    while(l + 1 < r && nums[l] == nums[l + 1]) l++;
                    while(l < r - 1 && nums[r] == nums[r - 1]) r--;
                    // while(l < r && nums[l] == nums[l + 1]) l++;
                    // while(l < r && nums[r] == nums[r - 1]) r--;
                    l++;
                    r--;
                    
                } else if(sum > 0) {
                    r--;
                } else {
                    l++;
                }
            }
            
            // to handle duplicates
            while(i + 1 < n && nums[i] == nums[i + 1]) i++;
        }
        
        return res;
    }
};
