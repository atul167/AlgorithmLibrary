// https://leetcode.com/problems/count-square-submatrices-with-all-ones/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int dp[n+1][m+1];
        memset(dp, 0, sizeof dp);
        
        for(int i = 1; i <= n; i++){
        	for(int j = 1; j <= m; j++){
        		if(matrix[i - 1][j - 1] == 1)
        			dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
        	}
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
        	for(int j = 1; j <= m; j++){
        		ans += dp[i][j];
        	}
        }
        return ans;
    }
};
