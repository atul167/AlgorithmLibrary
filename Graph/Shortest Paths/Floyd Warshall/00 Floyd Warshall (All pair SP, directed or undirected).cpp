// It's a dynamic programming solution


ll g[N][N], dis[N][N];

void solve() {
    ll k, x, y, u, v, p, q;
    cin >> n >> m;
    loop(i, 1, n) {
        loop(j, 1, n) {
            if (i == j)
                g[i][j] = 0;
            else
                g[i][j] = INT_MAX;
        }
    }
    f(i, m) {
        cin >> u >> v >> x;
        g[u][v] = x;
        g[v][u] = x; // comment it if directed graph
    }
    loop(i, 1, n) {
        loop(j, 1, n) {
            dis[i][j] = g[i][j];
        }
    }
    loop(k, 1, n) {
        loop(i, 1, n) {
            loop(j, 1, n) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    loop(i, 1, n) {
        loop(j, 1, n) {
            cout << dis[i][j] << " ";
        }
        cout << endl;
    }
}
