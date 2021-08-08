// https://atcoder.jp/contests/abc176/tasks/abc176_d


// Method 1
const int N = 1e3+5;
int n, m;

string g[N];
int srcX, srcY, destX, destY;

bool isSafe(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= m || g[x][y] == '#')
        return false;
    return true;
}

void bfs01() {
    vector<vector<int>> dist(n, vector<int>(m, INF));

    deque<pair<int, int>> q;
    q.push_back({srcX, srcY});
    dist[srcX][srcY] = 0;

    while(!q.empty()) {
        auto it = q.front();
        q.pop_front();
        int x = it.first, y = it.second;

        if(x == destX && y == destY) {
            cout << dist[destX][destY];
            return;
        }

        for(int z = 0; z < 4; z++) {
            int nx = x + dx[z], ny = y + dy[z];
            if(!isSafe(nx, ny)) continue;

            int w = 0;
            if(dist[nx][ny] > dist[x][y] + w) {
                dist[nx][ny] = dist[x][y] + w;
                q.push_front({nx, ny});
            }
        }

        for(int nx = x - 2; nx <= x + 2; nx++) {
            for(int ny = y - 2; ny <= y + 2; ny++) {
                if(!isSafe(nx, ny)) continue;

                int w = 1;
                if(dist[nx][ny] > dist[x][y] + w) {
                    dist[nx][ny] = dist[x][y] + w;
                    q.push_back({nx, ny});
                }
            }
        }
    }

    cout << -1;
}

void solve() {
    int x, y, z;
    cin >> n >> m;
    cin >> srcX >> srcY;
    cin >> destX >> destY;

    f(i, n) cin >> g[i];

    srcX--, srcY--, destX--, destY--;
    bfs01();
}


































// Method 2
const int N = 1e3+5;
int n, m;

string g[N];
int srcX, srcY, destX, destY;

bool isSafe(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= m || g[x][y] == '#')
        return false;
    return true;
}

void bfs01() {
    vector<vector<int>> dist(n, vector<int>(m, INF));
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    deque<pair<int, int>> q;
    q.push_back({srcX, srcY});
    dist[srcX][srcY] = 0;

    while(!q.empty()) {
        auto it = q.front();
        q.pop_front();
        int x = it.first, y = it.second;

        if(x == destX && y == destY) {
            cout << dist[destX][destY];
            return;
        }

        if(vis[x][y]) continue;

        vis[x][y] = true;

        for(int z = 0; z < 4; z++) {
            int nx = x + dx[z], ny = y + dy[z];
            if(!isSafe(nx, ny)) continue;

            int w = 0;
            if(dist[nx][ny] > dist[x][y] + w) {
                dist[nx][ny] = dist[x][y] + w;
                q.push_front({nx, ny});
            }
        }

        for(int nx = x - 2; nx <= x + 2; nx++) {
            for(int ny = y - 2; ny <= y + 2; ny++) {
                if(!isSafe(nx, ny)) continue;

                int w = 1;
                if(dist[nx][ny] > dist[x][y] + w) {
                    dist[nx][ny] = dist[x][y] + w;
                    q.push_back({nx, ny});
                }
            }
        }
    }

    cout << -1;
}

void solve() {
    int x, y, z;
    cin >> n >> m;
    cin >> srcX >> srcY;
    cin >> destX >> destY;

    f(i, n) cin >> g[i];

    srcX--, srcY--, destX--, destY--;
    bfs01();
}


































// Method 3
const int N = 1e3+5;
int n, m;

string g[N];
int srcX, srcY, destX, destY;

bool isSafe(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= m || g[x][y] == '#')
        return false;
    return true;
}

void bfs01() {
    vector<vector<int>> dist(n, vector<int>(m, INF));

    deque<pair<int, int>> q;
    q.push_back({srcX, srcY});
    dist[srcX][srcY] = 0;

    while(!q.empty()) {
        auto it = q.front();
        q.pop_front();
        int x = it.first, y = it.second;

        for(int z = 0; z < 4; z++) {
            int nx = x + dx[z], ny = y + dy[z];
            if(!isSafe(nx, ny)) continue;

            int w = 0;
            if(dist[nx][ny] > dist[x][y] + w) {
                dist[nx][ny] = dist[x][y] + w;
                q.push_front({nx, ny});
            }
        }

        for(int nx = x - 2; nx <= x + 2; nx++) {
            for(int ny = y - 2; ny <= y + 2; ny++) {
                if(!isSafe(nx, ny)) continue;

                int w = 1;
                if(dist[nx][ny] > dist[x][y] + w) {
                    dist[nx][ny] = dist[x][y] + w;
                    q.push_back({nx, ny});
                }
            }
        }
    }

    if(dist[destX][destY] != INF) cout << dist[destX][destY] << endl;
    else cout << -1;
}

void solve() {
    int x, y, z;
    cin >> n >> m;
    cin >> srcX >> srcY;
    cin >> destX >> destY;

    f(i, n) cin >> g[i];

    srcX--, srcY--, destX--, destY--;
    bfs01();
}
