// https://leetcode.com/problems/search-a-2d-matrix/

/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
a) Integers in each row are sorted from left to right.
b) The first integer of each row is greater than the last integer of the previous row.

Example 1:
Input: 
matrix = [[1,3,5,7],
          [10,11,16,20],
          [23,30,34,60]], 
target = 3
Output: true
*/



/*
According to given constraints, if we push all the elements in a 1-D vector then all the elements will be sorted.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();

        int lo = 0, hi = n * m - 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int x = mid / m, y = mid % m;

            if (matrix[x][y] == target) return true;

            if (matrix[x][y] < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return false;
    }
};
