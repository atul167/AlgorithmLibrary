// https://www.lintcode.com/problem/857/
// http://buttercola.blogspot.com/2018/11/leetcode-727-minimum-window-subsequence.html
// https://anshika-bhargava0202.medium.com/leetcode-727-minimum-window-subsequence-21c40baff689


/*
Given strings S and T, find the minimum (contiguous) substring W of S, so that T is a subsequence of W.
If there is no such window in S that covers all characters in T, return the empty string "". 
If there are multiple such minimum-length windows, return the one with the smallest starting index.

Constraints:
1 <= |S| <= 20000
1 <= |T| <= 100
All the strings in the input will only contain lowercase letters.

Example 1:
Input：S="jmeqksfrsdcmsiwvaovztaqenprpvnbstl"，T="u"
Output：""
Explanation： unable to match

Example 2:
Input：S = "abcdebdde"， T = "bde"
Output："bcde"
Explanation："bcde" is the answer and "deb" is not a smaller window because the elements of T in the window must occur in order.
*/


class Solution {
public:
    /**
     * @param S: a string
     * @param T: a string
     * @return: the minimum substring of S
     */
    string minWindow(string &S, string &T) {
        // Write your code here
        int n = S.size(), m = T.size();
        if (n == 0 ||  m == 0) return "";
         
        int dp[n + 1][m + 1];
        
        for (int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }

        for (int j = 1; j <= m; j++) {
            dp[0][j] = -1;
        }
         
        int minLen = INT_MAX;
        int startPos = -1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = -1;
                 
                if (S[i - 1] == T[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
             
            if (dp[i][m] != -1) {
                int len = i - dp[i][m];
                if (len < minLen) {
                    startPos = dp[i][m];
                    minLen = len;
                }
            }
        }
         
        return startPos == -1 ? "" : S.substr(startPos, minLen);
    }
};
