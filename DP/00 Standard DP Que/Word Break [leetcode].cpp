// https://leetcode.com/problems/word-break/
// https://leetcode.com/problems/word-break-ii/


/*
Word Break I

Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
Note that the same word in the dictionary may be reused multiple times in the segmentation.


Example 1:
Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:
Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
*/




// Method: Top-down
class Solution {
public:
    int n;
    unordered_set<string> wordSet;
    
    bool go(int pos, string s, vector<int>& dp) {
        if (pos >= n)  return true;
        
        if (dp[pos] != -1) return dp[pos];
        
        for (int i = pos; i < n; i++) {
            if (wordSet.count(s.substr(pos, i - pos + 1)) && go(i + 1, s, dp)) {
                return dp[pos] = 1;
            }
        }
        return dp[pos] = 0;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        for(string s: wordDict) {
            wordSet.insert(s);
        }
        vector<int> dp(n, -1);
        return go(0, s, dp);
    }
};









// Method: Bottom-up
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

        dp[0] = 1;
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= i; j ++) {
                string tmp = s.substr(i - j, j);
                if(wordSet.find(tmp) != wordSet.end()) {
                    dp[i] = dp[i] || dp[i - j];
                    if(dp[i]) break;
                }
            }
        }
        
        return dp[n];
    }
};























/*
Word Break II

Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. 
Return all such possible sentences in any order.
Note that the same word in the dictionary may be reused multiple times in the segmentation.

Example 1:
Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]
*/


class Solution {
public:
    vector<string> res;
    int n;
    unordered_set<string> wordSet;

    void go(int pos, string temp, string& s) {
        if (pos == n)  {
            // remove extra space
            temp = temp.substr(0, temp.size() - 1);
            res.push_back(temp);
            return;
        }

        for (int i = pos; i < n; i++) {
            if (wordSet.count(s.substr(pos, i - pos + 1))) {
                go(i + 1, temp + s.substr(pos, i - pos + 1) + " ", s);
            }
        }
    }


    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        for (string s : wordDict) {
            wordSet.insert(s);
        }
        go(0, "", s);
        return res;
    }
};
