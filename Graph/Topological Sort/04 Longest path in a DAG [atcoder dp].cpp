// https://atcoder.jp/contests/dp/tasks/dp_g

/*
Consider:
No cycles can exist in the graph, i.e. a DAG is formed.
The problem becomes to get the longest path in the DAG.
Topological sort can iterate the vertices of a DAG in the linear ordering.
Using Kahn's algorithm(BFS) to implement topological sort while counting the levels can give us the longest chain of nodes in the DAG.
*/

const int N = 3e5+5;
int n, m;

vi g[N];
int dp[N], indegree[N];

void kahn() {
    queue<int> q;
    loop(i, 1, n) {
        if(indegree[i] == 0) q.push(i);
    }

    int path_len = 0;
    while(!q.empty()) {
        int sz = q.size();
        f(i, sz) {
            int u = q.front();
            q.pop();

            for(int v: g[u]) {
                indegree[v]--;
                if(indegree[v] == 0) q.push(v);
            }
        }
        path_len += 1;
    }
    cout << path_len - 1 << endl;
}

void solve() {
    int u, v;
    cin >> n >> m;
    f(i, m) {
        cin >> u >> v;
        g[u].pb(v);
        indegree[v]++;
    }
    kahn();
}

