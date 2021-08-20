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
        
        for(char x: s) {
            if(x != '(' and x != ')') {
                st.push(x);
            }
            else if(x == '(') {
                cnt++;
                st.push(x);
            }
            else if(x == ')' && cnt > 0) {
                cnt--;
                st.push(x);
            }
        }
        
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
        
        return res;
    }
};






















// TLE solution
class Solution {
public:
    bool isBalanced(string s) {
        int cnt = 0;
        for(char x: s) {
            if(x == '(') cnt++;
            if(x == ')') cnt--;
            if(cnt < 0) return false;
        }
        return (cnt == 0);
    }
    
    string minRemoveToMakeValid(string s) {
        queue<string> q;
        map<string, bool> vis;
        q.push(s);
        vis[s] = 1;
        
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                string u = q.front();
                q.pop();

                if(isBalanced(u)) {
                    return u;
                }

                for(int i = 0; i < u.size(); i++) {
                    if(s[i] == '(' or s[i] == ')') {
                        string v = u.substr(0, i) + u.substr(i+1);
                        if(!vis[v]) {
                            q.push(v);
                            vis[v] = 1;
                        }
                    }
                }
            }
        }
        return "";
    }
};
