// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

/*
Given an n x m integers matrix, return the length of the longest increasing path in matrix.
From each cell, you can either move in four directions: left, right, up, or down. 
You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

Input: matrix = [[9,9,4],
                 [6,6,8],
                 [2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].

Input: matrix = [[3,4,5],
                 [3,2,6],
                 [2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
*/



class Solution {
public:
    int n, m;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = { -1, 0, 1, 0};
    vector<vector<int>> vis, dp;

    bool isSafe(int i, int j) {
        if(i < 0 || i >= n || j < 0 || j >= m)
            return false;
        return true;
    }

    void dfs(int i, int j, vector<vector<int>>& matrix) {
        vis[i][j] = 1;
        dp[i][j] = 0;

        for(int z = 0; z < 4; z++) {
            int ni = i + dx[z], nj = j + dy[z];
            if(!isSafe(ni, nj)) continue;
            if(matrix[ni][nj] <= matrix[i][j]) continue;

            if(!vis[ni][nj]) {
                dfs(ni, nj, matrix);
            }

            dp[i][j] = max(dp[i][j], 1 + dp[ni][nj]);
        }
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size(), m = matrix[0].size();
        vis = vector<vector<int>>(n, vector<int>(m, 0));
        dp = vector<vector<int>>(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j]) dfs(i, j, matrix);
            }
        }
        
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                res = max(res, dp[i][j]);
            }
        }
        return res + 1;
    }
};
