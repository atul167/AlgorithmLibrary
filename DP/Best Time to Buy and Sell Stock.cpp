/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

You can do at most one transaction
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        int minCostPrice = INT_MAX;
        for(int i = 0; i < n; i++) {
            minCostPrice = min(minCostPrice, prices[i]);
            profit = max(profit, prices[i] - minCostPrice);
        }
        return profit;
    }
};










/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

You can do as many transactions as you like
*/

class Solution {
public:
    int n;

    int fun(int pos, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        if(pos >= n) return 0;

        if(dp[pos][buy] != -1) return dp[pos][buy];

        if(buy) {
            return dp[pos][buy] = max(-prices[pos] + fun(pos + 1, 0, prices, dp), fun(pos + 1, 1, prices, dp));
        } else {
            return dp[pos][buy] = max(prices[pos] + fun(pos + 1, 1, prices, dp), fun(pos + 1, 0, prices, dp));
        }
    }

    int maxProfit(vector<int>& prices) {
        n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        //passing here buy=1 because we will first buy then sell 
        return fun(0, 1, prices, dp);
    }
};


//PEAK_VALLEY APPROACH
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int diff = 0;
        for(int i = 1; i < n; ++i) {
            if(prices[i] > prices[i-1])
                diff += prices[i]-prices[i-1];
        }
        return diff;
    }
};










/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

You may complete at most two transactions.
*/

class Solution {
public:
    int n;

    int fun(int pos, int buy, int cnt, vector<int>& prices, vector<vector<vector<int>>>& dp) {
        if(pos >= n || cnt >= 2) return 0;

        if(dp[pos][buy][cnt] != -1) return dp[pos][buy][cnt];

        if(buy) {
            return dp[pos][buy][cnt] = max(-prices[pos] + fun(pos + 1, 0, cnt, prices, dp), fun(pos + 1, 1, cnt, prices, dp));
        } else {
            return dp[pos][buy][cnt] = max(prices[pos] + fun(pos + 1, 1, cnt + 1, prices, dp), fun(pos + 1, 0, cnt, prices, dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        //Use 3-D vector -> 3 states {pos, buy/sell, count}
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(2, -1)));
        //passing here buy=1 because we will first buy then sell 
        return fun(0, 1, 0, prices, dp);
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int k = 2;
        int dp[k + 1][n];
        for(int i = 0; i < k+1; i++) {
            int max_el = INT_MIN;
            for(int j = 0; j < n; j++) {
                // i = 0 means no of transcations = 0
                // j = 0 means there is only day 1
                if(i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else {
                    max_el = max(max_el , dp[i-1][j-1] - prices[j-1]);
                    // max(we make no transc on jth day, we sell stock on jth day) 
                    dp[i][j] = max(dp[i][j - 1], prices[j] + max_el);
                }
            }
        }
        return dp[k][n - 1];
    }
};










/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

You may complete at most k transactions.
*/

class Solution {
public:
    int n, k;

    int fun(int pos, int buy, int cnt, vector<int>& prices, vector<vector<vector<int>>>& dp) {
        if(pos >= n || cnt >= k) return 0;

        if(dp[pos][buy][cnt] != -1) return dp[pos][buy][cnt];

        if(buy) {
            return dp[pos][buy][cnt] = max(-prices[pos] + fun(pos + 1, 0, cnt, prices, dp), fun(pos + 1, 1, cnt, prices, dp));
        } else {
            return dp[pos][buy][cnt] = max(prices[pos] + fun(pos + 1, 1, cnt + 1, prices, dp), fun(pos + 1, 0, cnt, prices, dp));
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        this->k = k;
        //Use 3-D vector -> 3 states {pos, buy/sell, count}
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        //passing here buy=1 because we will first buy then sell 
        return fun(0, 1, 0, prices, dp);
    }
};


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n == 0 || k == 0) return 0;
        int dp[k + 1][n];
        for(int i = 0; i < k+1; i++) {
            int max_el = INT_MIN;
            for(int j = 0; j < n; j++) {
                // i = 0 means no of transcations = 0
                // j = 0 means there is only day 1
                if(i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else {
                    max_el = max(max_el , dp[i-1][j-1] - prices[j-1]);
                    // max(we make no transc on jth day, we sell stock on jth day) 
                    dp[i][j] = max(dp[i][j - 1], prices[j] + max_el);
                }
            }
        }
        return dp[k][n - 1];
    }
};










/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

You can do as many transactions as you like but 
after you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
*/

class Solution {
public:
    int n;

    int fun(int pos, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        if(pos >= n) return 0;

        if(dp[pos][buy] != -1) return dp[pos][buy];

        if(buy) {
            return dp[pos][buy] = max(-prices[pos] + fun(pos + 1, 0, prices, dp), fun(pos + 1, 1, prices, dp));
        } else {
            // After you sell your stock, you cannot buy stock on next day, thus:
            // prices[pos] + fun(pos + 2, 1, prices, dp)
            return dp[pos][buy] = max(prices[pos] + fun(pos + 2, 1, prices, dp), fun(pos + 1, 0, prices, dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        //passing here buy=1 because we will first buy then sell 
        return fun(0, 1, prices, dp);
    }
};
