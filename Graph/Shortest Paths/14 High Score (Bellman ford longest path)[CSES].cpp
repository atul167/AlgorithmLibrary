// https://cses.fi/problemset/task/1673/

// https://youtu.be/WMTIoCkVFw4
// Method 1
void dfs(int u, vector<int>& vis, vector<vector<int>>& g) {
    vis[u] = 1;
    for(int v: g[u]) {
        if (!vis[v]) {
            dfs(v, vis, g);
        }
    }
} 
 
void solve() {
    int u, v, w;
    cin >> n >> m;
    vector<vector<int>> g(n+1);
    vector<vector<int>> revG(n+1);
    vector<tuple<int, int, int>> edges;
    f(i, m) {
        cin >> u >> v >> w;
        edges.pb({u, v, -w});
        g[u].pb(v);
        revG[v].pb(u);
    }

    vector<int>vis(n+1), revVis(n+1);
    dfs(1, vis, g);
    dfs(n, revVis, revG);

    vector<int> dis(n+1, INF);
    dis[1] = 0;
    bool flag = 0;
    // loop from 1 to n to keeo track of negative weight cycle on n'th iteration
    for (int i = 1; i <= n; i++) {
        flag = 0;
        for(auto it: edges) {
            tie(u, v, w) = it;
            if(vis[u] and revVis[v] and dis[v] > dis[u] + w) {
                flag = 1;
                dis[v] = dis[u] + w;
            }
        }
    }

    if(flag) cout << -1 << endl;
    else cout << -dis[n] << endl;
}
