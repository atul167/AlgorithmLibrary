// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

/*
Example:
Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
*/

/*
Note: This will give TLE
    string res = "";
    while(!st.empty()) {
        char x = st.top();
        st.pop();
        if(cnt > 0 && x == '(') {
            cnt--;
        } else {
            res = x + res;
        }
    }
    
Use this:
    int n = st.size() - cnt;
    string res(n, ' ');
    int idx = n - 1;
    while(!st.empty()) {
        char x = st.top();
        st.pop();
        if(cnt > 0 && x == '(') {
            cnt--;
        } else {
            res[idx] = x;
            idx--;
        }
    }
*/


class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> st;
        int cnt = 0;

        for (char x : s) {
            if (x != '(' and x != ')') {
                st.push(x);
            }
            else if (x == '(') {
                cnt++;
                st.push(x);
            }
            else if (x == ')' && cnt > 0) {
                cnt--;
                st.push(x);
            }
        }

        int n = st.size() - cnt;
        string res(n, ' ');
        int idx = n - 1;
        while (!st.empty()) {
            char x = st.top();
            st.pop();
            if (cnt > 0 && x == '(') {
                cnt--;
            } else {
                res[idx] = x;
                idx--;
            }
        }

        return res;
    }
};
