
// Paint House I
// https://www.lintcode.com/problem/515/
/*
There are a row of n houses, each house can be painted with one of the three colors: red, blue or green. 
The cost of painting each house with a certain color is different. 
You have to paint all the houses such that no two adjacent houses have the same color, and you need to cost the least. Return the minimum cost.
The cost of painting each house with a certain color is represented by a n x 3 cost matrix. 
For example, costs[0][0] is the cost of painting house 0 with color red; costs[1][2] is the cost of painting house 1 with color green, and so on... 
Find the minimum cost to paint all houses.
*/

class Solution {
public:
    /**
     * @param costs: n x 3 cost matrix
     * @return: An integer, the minimum cost to paint all houses
     */
    int minCost(vector<vector<int>> &costs) {
        int n = costs.size();
        if(n == 0) return 0;
        vector<vector<int>> dp(n, vector<int>(3, 0));
        dp[0] = costs[0];

        for(int i = 1; i < n; i++) {
            dp[i][0] = costs[i][0] + min(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = costs[i][1] + min(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = costs[i][2] + min(dp[i-1][0], dp[i-1][1]);
        }

        return min({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
    }
};













// Paint House II
// https://www.lintcode.com/problem/516/
/*
There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. 
You have to paint all the houses such that no two adjacent houses have the same color.
The cost of painting each house with a certain color is represented by a n x k cost matrix. 
For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... 
Find the minimum cost to paint all houses.
*/

// Method 1: Time = O(n*m*m), Space = O(n*m)
class Solution {
public:
    /**
     * @param costs: n x k cost matrix
     * @return: an integer, the minimum cost to paint all houses
     */
    int minCostII(vector<vector<int>> &costs) {
        int n = costs.size();
        if(n == 0) return 0;
        int m = costs[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[0] = costs[0];

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int mn = 1e9;
                for(int k = 0; k < m; k++) {
                    if(k != j)
                        mn = min(mn, dp[i-1][k]);
                }
                dp[i][j] = costs[i][j] + mn;
            }
        }

        int res = 1e9;
        for(int j = 0; j < m; j++) {
            res = min(res, dp[n-1][j]);
        }
        return res;
    }
};


// Method 2: Time = O(n*m), Space = 1
// Explanation: https://www.cnblogs.com/airwindow/p/4804011.html
class Solution {
public:
    /**
     * @param costs: n x k cost matrix
     * @return: an integer, the minimum cost to paint all houses
     */
    int minCostII(vector<vector<int>> &costs) {
        int n = costs.size();
        if(n == 0) return 0;
        int m = costs[0].size();
        if(m == 0) return 0;

        int min1 = INT_MAX, min2 = INT_MAX;
        
        for(int i = 0; i < m; i++) {
            if(costs[0][i] < min1) {
                min2 = min1;
                min1 = costs[0][i];
            } else if(costs[0][i] < min2) {
                min2 = costs[0][i];
            }
        }
        
        if(n == 1) return min1;
        
        int curmin1, curmin2;
        
        for(int i = 1; i < n; i++) {
            curmin1 = curmin2 = INT_MAX;
            for(int j = 0; j < m; j++) {
                if(costs[i - 1][j] != min1) {
                    costs[i][j] += min1;
                } else {
                    costs[i][j] += min2;
                }
                
                if(costs[i][j] < curmin1) {
                    curmin2 = curmin1;
                    curmin1 = costs[i][j];
                } else if(costs[i][j] < curmin2) {
                    curmin2 = costs[i][j];
                }
            }
            
            min1 = curmin1;
            min2 = curmin2;
        }
        
        return min1;
    }
};
