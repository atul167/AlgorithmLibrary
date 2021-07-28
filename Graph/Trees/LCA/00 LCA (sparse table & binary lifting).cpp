const int N = 2e5+5;
int n, m;
 
vector<int> g[N];
int level[N];

// height is not the height of tree but log2(N) of nodes
// int height=(int)ceil(log2(N));
// (Sparse Table) or LCA[i][j] represents 2^(j)th parent of node i
// int LCA[N][(int)ceil(log2(N))+1];

const int height = 30;
int LCA[N][height + 5];

void dfs(int u, int par, int lvl) {
    level[u] = lvl;
    LCA[u][0] = par;

    for(auto v: g[u]) {
        if(v != par) {
            dfs(v, u, lvl + 1);
        }
    }
}

// generating sparse table
void init() {
    // initializing parent and level of each node
    dfs(1, -1, 0);

    for(int i = 1; i <= height; i++) {
        for(int node = 1; node <= n; node++) {
            // for 2^i node, first getting 2^(i - 1)th node
            int parNode = LCA[node][i - 1];
            if(parNode != -1) {
                // 2^(i)th node = 2^(i - 1)th + 2^(i - 1)th node
                LCA[node][i] = LCA[parNode][i - 1];
            } else {
                LCA[node][i] = -1;
            }
        }
    }
}

// binary lifting
int getLCA(int a, int b) {
    if(level[b] < level[a]) swap(a, b);

    int d = level[b] - level[a];

    // method 1
    for(int i = 0; i < height; i++) {
        if(d & (1<<i)) b = LCA[b][i];
    }

    // method 2
    // for(int i = height-1; i >= 0; i--) {
    //     if(d & (1<<i)) b = LCA[b][i];
    // }

    // method 3
    // while(d) {
    //     int i = log2(d);
    //     b = LCA[b][i];
    //     d -= (1 << i);
    // }

    if(a == b) return a;

    // naive approach O(n)
    // while(LCA[a][0] != LCA[b][0]){
    //     a = LCA[a][0];
    //     b = LCA[b][0];
    // }

    // efficient approach O(logn)
    for(int i = 0; i < height; i++) {
        if(LCA[a][i] != LCA[b][i]) {
            a = LCA[a][i];
            b = LCA[b][i];
        }
    }

    // parent of a or b
    return LCA[a][0];
}
 
void solve() {
    int u, v;
    cin >> n;
    f(i, n-1) cin >> u >> v, g[u].pb(v), g[v].pb(u);

    init();
    cout << getLCA(7, 3);
}

/*
INPUT
7
1 2
1 3
2 4
2 5
3 6
6 7
OUTPUT
3
*/
