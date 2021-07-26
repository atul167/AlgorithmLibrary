// https://cses.fi/problemset/task/1681/
// https://usaco.guide/problems/cses-1681-game-routes/solution


/*
Time Complexity: O(N + M)

This problem is very similar to the "Longest Flight Route" problem. 
Let dp[v] denote the number of paths reaching v. 

Clearly: 
dp[v] = Summation{edge u->v exists dp[u]},
        or 1 if v is src node

We process the nodes topologically so dp[u] will already have been computed before dp[v].
*/

const int N = 2e5+5;
int n, m;

vector<int> g[N];
vector<int> revG[N];
int parent[N], dp[N], inDegree[N];

// Does a topological sort
void topologicalSort() {
    queue<int> q;
    loop(i, 1, n) {
        if(inDegree[i] == 0) {
            q.push(i);
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
        for(int prev: revG[node]) {
            dp[node] = (dp[node] + dp[prev]) % MOD;
        }
    }

}

void solve() {
    int u, v;
    cin >> n >> m;

    loop(i, 1, n) {
        dp[i] = 0;
        inDegree[i] = 0;
    }

    f(i, m) {
        cin >> u >> v;
        inDegree[v]++;

        g[u].pb(v);
        revG[v].pb(u);
    }

    int src = 1, dest = n;
    dp[src] = 1;
    topologicalSort();

    cout << dp[dest] << endl;
}  
