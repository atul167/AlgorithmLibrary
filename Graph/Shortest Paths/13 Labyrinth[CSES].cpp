// https://cses.fi/problemset/task/1193/

/*
You are given a map of a labyrinth, and your task is to find a path from start to end. You can walk left, right, up and down.

Input:
The first input line has two integers n and m: the height and width of the map.
Then there are n lines of m characters describing the labyrinth. Each character is . (floor), # (wall), A (start), or B (end). There is exactly one A and one B in the input.

Output:
First print "YES", if there is a path, and "NO" otherwise.
If there is a path, print the length of the shortest such path and its description as a string consisting of characters L (left), R (right), U (up), and D (down). You can print any valid solution.

Constraints
1 ≤ n, m ≤ 1000
*/



const int N = 1000;
int n, m;

// 0 = up, 1 = right, 2 = down, 3 = left
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
string stepDir = "URDL";

char g[N+5][N+5];
bool vis[N+5][N+5];
// previousStep stores the previous direction that we moved in to arrive that this cell
int previousStep[N+5][N+5];

bool isSafe(int i, int j) {
    if(i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || g[i][j] == '#')
        return false;
    return true;
}

void solve() {
    cin >> n >> m;

    queue<pair<int, int>> q;
    pair<int, int> source, dest;

    f(i, n) {
        f(j, m) {
            cin >> g[i][j];
            if (g[i][j] == 'A') {
                source = {i, j};
            } else if (g[i][j] == 'B') {
                dest = {i, j};
            }
        }
    }

    q.push(source);
    vis[source.first][source.second] = 1;

    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        int x = u.first, y = u.second;

        f(z, 4) {
            int nx = x + dx[z], ny = y + dy[z];
            if (!isSafe(nx, ny)) continue;

            vis[nx][ny] = true;
            previousStep[nx][ny] = z;
            q.push({nx, ny});
        }
    }

    if (!vis[dest.first][dest.second]) {
        cout << "NO" << endl;
        return;
    }
    
    cout << "YES" << endl;
    vector<int> steps;
    while (dest != source) {
        int p = previousStep[dest.first][dest.second];
        steps.push_back(p);
        // undo the previous step to get back to the previous square
        // Notice how we subtract dx/dy, whereas we added dx/dy before
        dest = {dest.first - dx[p], dest.second - dy[p]};
    }

    reverse(steps.begin(), steps.end());
    cout << steps.size() << endl;
    for (int c: steps) {
        cout << stepDir[c];
    }
    cout << endl;
} 
