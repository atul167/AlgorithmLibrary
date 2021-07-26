// https://cses.fi/problemset/task/1680/
// https://youtu.be/9HMawd5jn9A


const int N = 2e5+5;
int n, m;
int dis[N], parent[N];
vector<pair<int, int> > g[N];
 
void dijkstra(int source, int destination) {
    for(int i = 1; i <= n; i++) {
        dis[i] = -INF;
        parent[i] = -1;
    }
 
    dis[source] = 0;
    set<pair<int, int>> s;
    s.insert({0, source});
 
    while(!s.empty()) {
        auto x = *(s.begin());
        s.erase(x);
        int u = x.second;
 
        for(auto it: g[u]) {
            int v = it.first;
            int w = it.second;
            if(dis[v] < dis[u] + w) {
                s.erase({dis[v], v});
                dis[v] = dis[u] + w;
                s.insert({dis[v], v});
                parent[v] = u;
            }
        }
    }
 
    int node = destination;
    vector<int> res;
    while(parent[node] != -1) {
        res.push_back(node);
        node = parent[node];
    }
    res.push_back(source);

    if(res.size() == 1) {
        cout << "IMPOSSIBLE\n";
    }

    cout << res.size() << endl;

    reverse(res.begin(), res.end());
    for(auto i: res) {
        cout << i << " ";
    }
}
 
void solve() {
    int u, v, w;
    cin >> n >> m;
    f(i, m) {
        cin >> u>> v;
        g[u].push_back({v, 1});
    }
    dijkstra(1, n);
}
