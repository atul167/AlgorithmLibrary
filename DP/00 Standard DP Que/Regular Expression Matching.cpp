// https://leetcode.com/problems/regular-expression-matching/
// https://youtu.be/DJvw8jCmxUU

/*
Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:
a) '.' Matches any single character.
b) '*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).
It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
 

Example 1:
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:
Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

Example 3:
Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".

Example 4:
Input: s = "aab", p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".

Example 5:
Input: s = "mississippi", p = "mis*is*p*."
Output: false
 

Constraints:
1 <= s.length <= 20
1 <= p.length <= 30
s contains only lowercase English letters.
p contains only lowercase English letters, '.', and '*'.
It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
*/


/*
We define dp[i][j] to be true if s[0..i) matches p[0..j) and false otherwise. 
The state equations will be:

dp[i][j] = dp[i - 1][j - 1], if p[j - 1] != '*' && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
dp[i][j] = dp[i][j - 2], if p[j - 1] == '*' and the pattern repeats for 0 time;
dp[i][j] = dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'), if p[j - 1] == '*' and the pattern repeats for at least 1 time.
*/


class Solution {
public:
    bool isMatch(string str, string pat) {
        int n = str.size(), m = pat.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // empty pattern can match with empty string
        dp[0][0] = 1;

        // empty str
        for (int j = 1; j <= m; j++) {
            // assuming (j-2 >= 0) since pat will not start with '*'
            if (pat[j - 1] == '*' && (j - 2 >= 0)) {
                dp[0][j] = dp[0][j - 2];
            } else {
                // pat[j - 1] = '.' or 'character'
                dp[0][j] = 0;
            }
        }

        // String cannot match with empty pattern
        for (int i = 1; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (pat[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2];
                    if (pat[j - 2] == '.' || pat[j - 2] == str[i - 1]) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }

                // Current characters are considered as matching in two cases
                // (a) current character of pattern is '.'
                // (b) characters actually match
                else if (pat[j - 1] == '.' || str[i - 1] == pat[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }

                // If characters don't match (str[i-1] != pat[j-1])
                else dp[i][j] = false;
            }
        }

        return dp[n][m];
    }
};
