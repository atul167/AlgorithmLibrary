// https://leetcode.com/problems/palindrome-partitioning-ii/
// https://www.geeksforgeeks.org/palindrome-partitioning-dp-17/

// TLE solution O(n^3) (MCM - memoized)
class Solution {
public:
    vector<vector<bool>> isPalindrome;
    int n;
    string s;
    int dp[2005][2005];    
    
    void precomputeIsPalindrome(string s) {
        int n = s.size();
        isPalindrome.resize(n, vector<bool>(n));
        for(int gap = 0; gap < n; gap++) {
            for(int i=0, j=gap;  j<n;  i++, j++) {
                isPalindrome[i][j] = false;
                if(gap == 0) {
                    isPalindrome[i][j] = true;
                } else if(gap == 1) {
                    if(s[i] == s[j]) isPalindrome[i][j] = true;
                    else isPalindrome[i][j] = false;
                } else {
                    if(s[i] == s[j] && isPalindrome[i + 1][j - 1]) {
                        isPalindrome[i][j] = true;
                    } else {
                        isPalindrome[i][j] = false;
                    }
                }
            }
        }
    }
    
    int go(int i, int j) {
        if (i == j) return 0;
        
        if(isPalindrome[i][j]) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int res = INT_MAX;
        for (int k = i; k < j; k++) {
            int leftCost = go(i, k);
            int rightCost = go(k + 1, j);
            res = min(res, leftCost + rightCost + 1);

        }
        
        return dp[i][j] = res;
    }
    int minCut(string s) {
        n = s.size();
        this->s = s;
        precomputeIsPalindrome(s);
        
        memset(dp, -1, sizeof dp);
        return go(0, n - 1);
    }
};















// TLE solution O(n^3) (MCM - gap method)
class Solution {
public:
    vector<vector<bool>> isPalindrome;
    int n;
    
    void precomputeIsPalindrome(string s) {
        isPalindrome.resize(n, vector<bool>(n));
        for(int gap = 0; gap < n; gap++) {
            for(int i=0, j=gap;  j<n;  i++, j++) {
                isPalindrome[i][j] = false;
                if(gap == 0) {
                    isPalindrome[i][j] = true;
                } else if(gap == 1) {
                    if(s[i] == s[j]) isPalindrome[i][j] = true;
                    else isPalindrome[i][j] = false;
                } else {
                    if(s[i] == s[j] && isPalindrome[i + 1][j - 1]) {
                        isPalindrome[i][j] = true;
                    } else {
                        isPalindrome[i][j] = false;
                    }
                }
            }
        }
    }

    int minCut(string s) {
        n = s.size();
        precomputeIsPalindrome(s);
        
        // dp[i][j] = min cuts required for substring 1...j
        vector<vector<int>> dp(n, vector<int>(n));

        for (int gap = 0; gap < n; gap++) {
            for (int i = 0, j = gap; j < n; i++, j++) {
                if (gap == 0) {
                    dp[i][j] = 0;
                } else if (gap == 1) {
                    if(s[i] == s[j]) dp[i][j] = 0;
                    else dp[i][j] = 1;
                } else {
                    if(isPalindrome[i][j]) dp[i][j] = 0;
                    else {
                        dp[i][j] = INT_MAX;
                        for (int k = i; k < j; k++) {
                            int leftCost = dp[i][k];
                            int rightCost = dp[k + 1][j];

                            dp[i][j] = min(dp[i][j], leftCost + rightCost + 1);
                        }
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};
