// https://atcoder.jp/contests/dp/tasks/dp_g
// https://www.geeksforgeeks.org/longest-path-in-a-directed-acyclic-graph-dynamic-programming/

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
