// https://leetcode.com/problems/time-needed-to-inform-all-employees/

/*
A company has n employees with a unique ID for each employee from 0 to n - 1. The head of the company is the one with headID.
Each employee has one direct manager given in the manager array where manager[i] is the direct manager of the i-th employee, manager[headID] = -1. 
Also, it is guaranteed that the subordination relationships have a tree structure.

The head of the company wants to inform all the company employees of an urgent piece of news. 
He will inform his direct subordinates, and they will inform their subordinates, and so on until all employees know about the urgent news.
The i-th employee needs informTime[i] minutes to inform all of his direct subordinates 
(i.e., After informTime[i] minutes, all his direct subordinates can start spreading the news).

Return the number of minutes needed to inform all the employees about the urgent news.
*/

// Method 1.1
class Solution {
public:
    int n, m;

    vector<vector<int>> g, revG;
    vector<int> inDegree, dp;
    
    int topologicalSort(vector<int>& informTime) {
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
                dp[i] = informTime[i];
            }
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(int next: g[node]) {
                inDegree[next]--;
                if(inDegree[next] == 0) q.push(next);
            }

            // The below block computes the DP
            int mx = informTime[node];
            for(int prev: revG[node]) {
                mx = max(mx, dp[prev] + informTime[node]);
            }

            dp[node] = mx;
        }

        int res = 0;
        for(int i = 0; i < n; i++) {
            res = max(res, dp[i]);
        }
        return res;
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        this->n = n;
        g = vector<vector<int>>(n);
        revG = vector<vector<int>>(n);
        inDegree = vector<int>(n, 0);
        dp = vector<int>(n, 0);
        
        for(int i = 0; i < n; i++) {
            int u = manager[i];
            int v = i;
            if(u != -1) {
                g[u].push_back(v);
                revG[v].push_back(u);
                inDegree[v]++;
            }
        }
        return topologicalSort(informTime);
    }
};













// Method 1.2
class Solution {
public:
    int n, m;

    vector<vector<int>> g, revG;
    vector<int> inDegree, dp;
    
    int topologicalSort(vector<int>& informTime) {
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
                dp[i] = informTime[i];
            }
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(int next: g[node]) {
                inDegree[next]--;
                if(inDegree[next] == 0) q.push(next);
            }

            // The below block computes the DP
            int mx = 0;
            for(int prev: revG[node]) {
                mx = max(mx, dp[prev] + informTime[node]);
            }

            dp[node] = max(dp[node], mx);
        }

        int res = 0;
        for(int i = 0; i < n; i++) {
            res = max(res, dp[i]);
        }
        return res;
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        this->n = n;
        g = vector<vector<int>>(n);
        revG = vector<vector<int>>(n);
        inDegree = vector<int>(n, 0);
        dp = vector<int>(n, 0);
        
        for(int i = 0; i < n; i++) {
            int u = manager[i];
            int v = i;
            if(u != -1) {
                g[u].push_back(v);
                revG[v].push_back(u);
                inDegree[v]++;
            }
        }
        return topologicalSort(informTime);
    }
};
















// Method 2.1
class Solution {
public:
    int n, m;
    vector<vector<int>> g;
    vector<int> dp;

    int dfs(int u, vector<int>& informTime) {
        if(dp[u]) return dp[u];
        dp[u] = informTime[u];

        for (int v: g[u]) {
            dp[u] = max(dp[u], informTime[u] + dfs(v, informTime));
        }

        return dp[u];
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        this->n = n;
        g = vector<vector<int>>(n);
        dp = vector<int>(n, 0);
        
        for(int i = 0; i < n; i++) {
            int u = manager[i];
            int v = i;
            if(u != -1) {
                g[u].push_back(v);
            }
        }
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, dfs(i, informTime));
        }

        return res;
    }
};









// Method 2.2
class Solution {
public:
    int n, m;
    vector<vector<int>> g;
    vector<int> dp;

    void dfs(int u, vector<int>& informTime) {
        if(dp[u]) return;
        dp[u] = informTime[u];

        for (int v: g[u]) {
            dfs(v, informTime);
            dp[u] = max(dp[u], informTime[u] + dp[v]);
        }
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        this->n = n;
        g = vector<vector<int>>(n);
        dp = vector<int>(n, 0);
        
        for(int i = 0; i < n; i++) {
            int u = manager[i];
            int v = i;
            if(u != -1) {
                g[u].push_back(v);
            }
        }
        
        for (int i = 0; i < n; i++) {
            dfs(i, informTime);
        }
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, dp[i]);
        }

        return res;
    }
};










// Method 2.3
class Solution {
public:
    int n, m;
    vector<vector<int>> g;
    vector<int> dp;

    void dfs(int u, vector<int>& informTime) {
        if(dp[u] != -1) return;
        dp[u] = informTime[u];

        for (int v: g[u]) {
            dfs(v, informTime);
            dp[u] = max(dp[u], informTime[u] + dp[v]);
        }
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        this->n = n;
        g = vector<vector<int>>(n);
        dp = vector<int>(n, -1);
        
        for(int i = 0; i < n; i++) {
            int u = manager[i];
            int v = i;
            if(u != -1) {
                g[u].push_back(v);
            }
        }
        
        for (int i = 0; i < n; i++) {
            dfs(i, informTime);
        }
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, dp[i]);
        }

        return res;
    }
};
