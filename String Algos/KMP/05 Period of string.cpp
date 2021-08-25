// https://leetcode.com/problems/repeated-substring-pattern/

class Solution {
public:
    bool prefix_function(string &s) {
        int n = (int)s.length();
        vector<int> pi(n);
        pi[0] = 0;
        for (int i = 1; i < n; i++) {
            int j = pi[i-1];
            while (j > 0 && s[i] != s[j]) {
                j = pi[j-1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            pi[i] = j;
        }
        int period = n - pi[n - 1];
        return pi[n - 1] && (n % period == 0);
    }
    
    bool repeatedSubstringPattern(string s) {
        return prefix_function(s);
    }
};
