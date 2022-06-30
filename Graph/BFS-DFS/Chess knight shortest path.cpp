// https://www.geeksforgeeks.org/minimum-steps-reach-target-knight/



int n, m;
int row[] = {2, 2, -2, -2, 1, 1, -1, -1};
int col[] = { -1, 1, 1, -1, 2, -2, 2, -2};
map<pair<int, int>, int> visited;

struct Node {
    int x, y, dist;
    Node(int x, int y, int dist = 0): x(x), y(y), dist(dist) {}
};

bool valid(int x, int y) {
    if (x < 0 || y < 0 || x >= 8 || y >= 8 || visited[ {x, y}]) return false;
    return true;
}

int bfs(pair<int, int> src, pair<int, int> dest) {
    queue<Node> q;
    q.push({src.F, src.S, 0});
    visited[src] = 1;

    while (!q.empty()) {
        Node node = q.front();
        q.pop();
        int x = node.x;
        int y = node.y;
        int dist = node.dist;

        if (x == dest.F && y == dest.S) {
            return dist;
        }

        f(z, 8) {
            int x1 = x + row[z], y1 = y + col[z];
            if (valid(x1, y1)) {
                q.push({x1, y1, dist + 1});
                visited[ {x1, y1}] = 1;
            }
        }
    }
    return -1;
}

void solve() {
    int u, v;
    pair<int, int> src = {4, 5};
    pair<int, int> dest = {1, 1};
    // pair<int, int> src = {0, 7};
    // pair<int, int> dest = {7, 0};
    cout << bfs(src, dest);
}
