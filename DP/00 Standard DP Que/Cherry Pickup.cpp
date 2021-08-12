// https://leetcode.com/problems/cherry-pickup/

/*
You are given an n x n grid representing a field of cherries, each cell is one of three possible integers.
a) 0 means the cell is empty, so you can pass through,
b) 1 means the cell contains a cherry that you can pick up and pass through, or
c) -1 means the cell contains a thorn that blocks your way.

Return the maximum number of cherries you can collect by following the rules below:
a) Starting at the position (0, 0) and reaching (n - 1, n - 1) by moving right or down through valid path cells (cells with value 0 or 1).
b) After reaching (n - 1, n - 1), returning to (0, 0) by moving left or up through valid path cells.
c) When passing through a path cell containing a cherry, you pick it up, and the cell becomes an empty cell 0.
d) If there is no valid path between (0, 0) and (n - 1, n - 1), then no cherries can be collected.
*/


// TLE Backtracking solution
class Solution {
public:
    int n;
    
    int go(int i, int j, int isBackTrip, vector<vector<int>>& grid) {
        if(isBackTrip) {
            if(grid[i][j] == -1) return INT_MIN;
            
            if(i == 0 && j == 0) {
                return grid[i][j];
            }
            
            int cherry = grid[i][j], res;
            // marked as visited by picking a cherry if any
            grid[i][j] = 0;
            
            if(i == 0) {
                res = cherry + go(i, j - 1, 1, grid);
            }
            else if(j == 0) {
                res = cherry + go(i - 1, j, 1, grid);
            } 
            else {
                res = cherry + max(go(i - 1, j, 1, grid), go(i, j - 1, 1, grid));
            }
            
            // backtracking
            grid[i][j] = cherry;
            
            return res;
        } else {
            if(grid[i][j] == -1) return INT_MIN;
            
            int cherry = grid[i][j], res, x = 0, y = 0;
            // marked as visited by picking a cherry if any
            grid[i][j] = 0;
            
            if(i == n - 1 && j == n - 1) {
                // res = cherry + max(go(i - 1, j, 1, grid), go(i, j - 1, 1, grid));
                
                // handle case when grid = [[1]] (i.e n = 1, m = 1)
                if(i - 1 >= 0) {
                    x = cherry + go(i - 1, j, 1, grid);
                }
                if(j - 1 >= 0) {
                    y = cherry + go(i, j - 1, 1, grid);
                }
                res = max({cherry, x, y});
            }
            
            else if(i == n - 1) {
                res = cherry + go(i, j + 1, 0, grid);
            }
            else if(j == n - 1) {
                res = cherry + go(i + 1, j, 0, grid);
            }
            else {
                res = cherry + max(go(i + 1, j, 0, grid), go(i, j + 1, 0, grid));
            }
            
            // backtracking
            grid[i][j] = cherry;
            
            return res;
        }
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        int res = go(0, 0, 0, grid);
        return max(0, res);
    }
};







// TLE Backtracking solution
class Solution {
public:
    int n, res;
    
    void backTrip(int i, int j, int total, vector<vector<int>>& grid) {
        if(i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == -1) return;
        
        if(i == 0 && j == 0) {
            res = max(res, total);
            return;
        }
        
        int cherry = grid[i][j];
        grid[i][j] = 0;
        backTrip(i - 1, j, total + cherry, grid);
        backTrip(i, j - 1, total + cherry, grid);
        grid[i][j] = cherry;
    }
    
    void go(int i, int j, int total, vector<vector<int>>& grid) {
        if(i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == -1) return;
        
        if(i == n - 1 && j == n - 1) {
            res = max(res, total + grid[i][j]);
            backTrip(i, j, total, grid);
            return;
        }
        
        int cherry = grid[i][j];
        grid[i][j] = 0;
        go(i + 1, j, total + cherry, grid);
        go(i, j + 1, total + cherry, grid);
        grid[i][j] = cherry;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        res = 0;
        go(0, 0, 0, grid);
        return res;
    }
};
