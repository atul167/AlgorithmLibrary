// https://www.geeksforgeeks.org/find-duplicates-in-on-time-and-constant-extra-space/
// https://practice.geeksforgeeks.org/problems/find-duplicates-in-an-array/1

/*
Given an array of n elements that contains elements from 0 to n-1, with any of these numbers appearing any number of times. 
Find these repeating numbers in O(n) and using only constant memory space.

Example: 

Input : 
n = 7 
array[] = {1, 2, 3, 6, 3, 6, 1}

Output: 
1, 3, 6
*/


class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        vector<int> res;
        for (int i = 0; i < n; i++) {
            arr[arr[i] % n] = arr[arr[i] % n] + n;
        }
        
        for (int i = 0; i < n; i++) {
            if (arr[i] >= n * 2) {
                res.push_back(i);
            }
        }
        
        if(res.size() == 0) res.push_back(-1);
        return res;
    }
};
