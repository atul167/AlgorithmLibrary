// https://leetcode.com/problems/repeated-string-match/

/*
Given two strings a and b, return the minimum number of times you should repeat string a so that string b is a substring of it. 
If it is impossible for b to be a substring of a after repeating it, return -1.

Note: string "abc" repeated 0 times is "",  repeated 1 time is "abc" and repeated 2 times is "abcabc". 

Example 1:
Input: a = "abcd", b = "cdabcdab"
Output: 3
Explanation: We return 3 because by repeating a three times "abcdabcdabcd", b is a substring of it.

Example 2:
Input: a = "a", b = "aa"
Output: 2
*/


class Solution {
public:
    vector<int> prefix_function(string &s) {
        int n = (int)s.length();
        vector<int> pi(n, 0);
        for (int i = 1; i < n; i++) {
            int j = pi[i - 1];
            while (j > 0 && s[i] != s[j]) {
                j = pi[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            pi[i] = j;
        }
        return pi;
    }

    int repeatedStringMatch(string A, string B) {
        int a = A.size(), b = B.size();
        // Making LPS array using string B
        vector<int>lps = prefix_function(B);

        // Search pattern 'B' in string 'A' in a circular fashion
        // 'i' represents the starting index of pattern 'B' in string 'A'
        // 'j' points to the current index in both strings 'A' and 'B'
        // (i + j) % a represents circular next index in 'A', as if it were linearly repeted

        int i = 0, j = 0;
        while (i < a) {
            // check for next in both
            if (B[j] == A[(i + j) % a]) {
                j++;
            } else {
                // even if no match found for the first letter of the pattern increment 'i'
                if (j == 0) {
                    i++;
                } else {
                    /* This else part is for case like:
                       A = "aaac", B = "aac"
                       A = "aaac", B = "aacaaac"
                    */
                    // updating 'i' here helps to keep pointed to the same position in 'A'
                    i += (j - lps[j - 1]);
                    j = lps[j - 1];
                    cout << i << " " << j << " ";
                }
            }

            if (j == b) {
                if ((i + j) % a) {
                    return (i + j) / a + 1;
                }
                return (i + j) / a;
            }
        }

        return -1;
    }
};
