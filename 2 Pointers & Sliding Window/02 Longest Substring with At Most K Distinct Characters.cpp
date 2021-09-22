// https://www.lintcode.com/problem/386

/*
Given a string S, find the length of the longest substring T that contains at most k distinct characters.

Example 1:
Input: S = "eceba" and k = 3
Output: 4
Explanation: T = "eceb"

Example 2:
Input: S = "WORLD" and k = 4
Output: 4
Explanation: T = "WORL" or "ORLD"
*/

class Solution {
public:
    /**
     * @param s: A string
     * @param k: An integer
     * @return: An integer
     */
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        // write your code here
        int n = s.size();
        set<char> st;
        map<char, int> freq;
        int res = 0;
        
        int l = 0, r = 0;
        while(r < n) {
            st.insert(s[r]);
            freq[s[r]]++;
            while(st.size() > k) {
                char ch = s[l];
                freq[ch]--;
                if(freq[ch] == 0) st.erase(ch);
                l++;
            }

            res = max(res, r - l + 1);
            r++;
        }

        return res;
    }
};
