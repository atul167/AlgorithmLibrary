// https://leetcode.com/problems/sort-colors/
// dutch national flag algorithm
// https://youtu.be/oaVa-9wmpns

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo = 0; 
        int hi = nums.size() - 1; 
        int mid = 0; 

        while (mid <= hi) { 
            int x = nums[mid];
            
            if(x == 0) {
                swap(nums[lo++], nums[mid++]); 
            }
            
            if(x == 1) {
                mid++; 
            }
            
            if(x == 2) {
                swap(nums[mid], nums[hi--]); 
            }
        }
    }
};
