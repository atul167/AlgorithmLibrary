// https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1
// https://www.geeksforgeeks.org/find-median-row-wise-sorted-matrix/

/*
Given a row wise sorted matrix of size n x m where n and m are always odd, find the median of the matrix.
*/


/*
Simple Method: 
Store all the elements of the given matrix in an array of size n * m. 
Then we can sort the array and find the median element in O(n*m*log(n*m)).


An efficient approach: 
Use a binary search algorithm. The idea is that for a number to be median there should be exactly (n / 2) numbers which are less than this number. 
So, we try to find the count of numbers less than all the numbers. 

Below is the step by step algorithm for this approach: 
a) First, we find the minimum and maximum elements in the matrix. 
b) Then we use binary search on our range of numbers from minimum to maximum, we find the mid of the min and max and get a count of numbers less than our mid. 
c) For a number to be median, there should be (n * m) / 2 numbers smaller than that number. 
   So for every number, we get the count of numbers less than that by using upper_bound() in each row of the matrix, 
   if it is less than the required count, the median must be greater than the selected number, else the median must be less than or equal to the selected number.
*/

// FFFFFFFTTTTTTTTT

class Solution {
public:
    int median(vector<vector<int>> &matrix, int n, int m) {
        int lo = INT_MAX, hi = INT_MIN;
        for (int i = 0; i < n; i++) {
            // Finding the minimum element
            lo = min(lo, matrix[i][0]);
            // Finding the maximum element
            hi = max(hi, matrix[i][m - 1]);
        }
        
        int desired = (n * m + 1) / 2;
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            
            int cnt = 0;
            // Find count of elements smaller than mid
            for (int i = 0; i < n; ++i) {
                cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            
            if (cnt >= desired)
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};





class Solution{   
public:
    bool check(int mid, int desired, vector<vector<int>> &matrix, int n, int m) {
        // Find count of elements smaller than mid
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }
        
        return cnt >= desired;
    }
    
    int median(vector<vector<int>> &matrix, int n, int m) {
        int lo = INT_MAX, hi = INT_MIN;
        for (int i = 0; i < n; i++) {
            // Finding the minimum element
            lo = min(lo, matrix[i][0]);
            // Finding the maximum element
            hi = max(hi, matrix[i][m - 1]);
        }
        
        int desired = (n * m + 1) / 2;
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (check(mid, desired, matrix, n, m))
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};
