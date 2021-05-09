// https://leetcode.com/problems/count-sorted-vowel-strings/

class Solution {
public:
    int n;
    int dp[60][5];
    int go(int pos, int state) {
        if(pos == n) {
            return 1;
        }
        
        if(dp[pos][state] != -1) return dp[pos][state];
        
        int res = 0;
        for(int i = state; i < 5; i++) {
            res += go(pos+1, i);
        }
        return dp[pos][state] = res;
    }
    int countVowelStrings(int n) {
        this->n = n;
        memset(dp, -1, sizeof dp);
        return go(0, 0);
    }
};






class Solution {
public:
    int countVowelStrings(int n) {
        int dp[n][5];
        for(int j = 0; j < 5; j++) dp[0][j] = 1;
        
        for(int i = 1; i < n; i++) {
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][0] + dp[i-1][1];
            dp[i][2] = dp[i-1][0] + dp[i-1][1] + dp[i-1][2];
            dp[i][3] = dp[i-1][0] + dp[i-1][1] + dp[i-1][2] + dp[i-1][3];
            dp[i][4] = dp[i-1][0] + dp[i-1][1] + dp[i-1][2] + dp[i-1][3] + dp[i-1][4];
        }
        
        // Method 2
        // for(int i = 1; i < n; i++) {
        //     dp[i][0] =            dp[i-1][0];
        //     dp[i][1] = dp[i][0] + dp[i-1][1];
        //     dp[i][2] = dp[i][1] + dp[i-1][2];
        //     dp[i][3] = dp[i][2] + dp[i-1][3];
        //     dp[i][4] = dp[i][3] + dp[i-1][4];
        // }
        
        int res = 0;
        for(int j = 0; j < 5; j++) {
            res += dp[n-1][j];
        }
        return res;
    }
};
