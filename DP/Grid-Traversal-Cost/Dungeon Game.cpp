// https://leetcode.com/problems/dungeon-game/

/*
The demons had captured the princess and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of m x n rooms laid out in a 2D grid. 
Our valiant knight was initially positioned in the top-left room and must fight his way through dungeon to rescue the princess.
The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.
Some of the rooms are guarded by demons (represented by negative integers), so the knight loses health upon entering these rooms; 
other rooms are either empty (represented as 0) or contain magic orbs that increase the knight's health (represented by positive integers).
To reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.
Return the knight's minimum initial health so that he can rescue the princess.

Note that any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.
*/

/*
abs(DP[i][j]) represents min strength the Knight should have if he starts the game from the (i, j)th point to reach (n-1, m-1)th point
*/ 

// Recursive
class Solution {
public:
    int n, m;
    int calculate(int i, int j, vector<vector<int>>& dungeon, vector<vector<int>>& dp) {
        // base cases
        if (i == n - 1 && j == m - 1) {
            return dp[i][j] = min(0, dungeon[i][j]);
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        // last row
        if (i == n - 1) {
            return dp[i][j] = min(0, dungeon[i][j] + calculate(i, j + 1, dungeon, dp));
        }
        // last column
        if (j == m - 1) {
            return dp[i][j] = min(0, dungeon[i][j] + calculate(i + 1, j, dungeon, dp));
        }

        return dp[i][j] = min(0, dungeon[i][j] + max(calculate(i + 1, j, dungeon, dp), calculate(i, j + 1, dungeon, dp)));
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        n = dungeon.size();
        m = dungeon[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return 1 + abs(calculate(0, 0, dungeon, dp));
    }
};


// DP
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        vector<vector<int>> dp(n,vector<int>(m));
        
        for(int i = n-1; i >= 0; --i) {
            for(int j = m-1; j >= 0; --j) {
                //Bottom-Right cell (Princess Cell)
                if(i == n - 1 && j == m - 1) {
                    dp[i][j] = min(0, dungeon[i][j]);
                }
                //last row
                else if(i == n - 1) {
                    dp[i][j] = min(0, dungeon[i][j] + dp[i][j + 1]);
                }
                //last col
                else if(j == m - 1) {
                    dp[i][j] = min(0, dungeon[i][j] + dp[i + 1][j]);
                }
                else {
                    dp[i][j] = min(0, dungeon[i][j] + max(dp[i][j + 1], dp[i + 1][j]));
                }
            }
        }
        return 1 + abs(dp[0][0]);
    }
};
