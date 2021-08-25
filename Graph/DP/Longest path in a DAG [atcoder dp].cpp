// https://atcoder.jp/contests/dp/tasks/dp_g
// https://www.geeksforgeeks.org/longest-path-in-a-directed-acyclic-graph-dynamic-programming/


// Method 1.1
const int N = 3e5+5;
int n, m;
vi g[N];
int dp[N];

int dfs(int u) {
    if(dp[u]) return dp[u];

    for (int v: g[u]) {
        dp[u] = max(dp[u], 1 + dfs(v));
    }

    return dp[u];
}

void solve() {
    int u, v;
    cin >> n >> m;
    f(i, m) cin >> u >> v, g[u].pb(v);

    memset(dp, 0, sizeof dp);

    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, dfs(i));
    }

    cout << res << endl;
}










// Method 1.2
const int N = 3e5+5;
int n, m;
vi g[N];
int dp[N];

int dfs(int u) {
    if(dp[u] != -1) return dp[u];
    dp[u] = 0;

    for (int v: g[u]) {
        dp[u] = max(dp[u], 1 + dfs(v));
    }

    return dp[u];
}

void solve() {
    int u, v;
    cin >> n >> m;
    f(i, m) cin >> u >> v, g[u].pb(v);

    memset(dp, -1, sizeof dp);

    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, dfs(i));
    }

    cout << res << endl;
}






// Method 1.3
const int N = 3e5+5;
int n, m;
vi g[N];
int dp[N];

void solve() {
    int u, v;
    cin >> n >> m;
    f(i, m) cin >> u >> v, g[u].pb(v);

    memset(dp, 0, sizeof dp);

    std::function<int(int)> dfs = [&] (int u) {
        if (dp[u]) return dp[u];
        
        for (int v: g[u]) {
            dp[u] = max(dp[u], 1 + dfs(v));
        }
        
        return dp[u];
    };

    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, dfs(i));
    }

    cout << res << endl;
}

















// Method 2
const int N = 3e5+5;
int n, m;
vi g[N];
int vis[N];
int dp[N];

void dfs(int u) {
    vis[u] = 1;
    dp[u] = 0;

    for (int v: g[u]) {
        if(!vis[v]) {
            dfs(v);
        }

        dp[u] = max(dp[u], 1 + dp[v]);
    }
} 

void solve() {
    int u, v;
    cin >> n >> m;
    f(i, m) cin >> u >> v, g[u].pb(v);

    for (int i = 1; i <= n; i++) {
        if(!vis[i]) {
            dfs(i);
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, dp[i]);
    }
    cout << res << endl;
}
