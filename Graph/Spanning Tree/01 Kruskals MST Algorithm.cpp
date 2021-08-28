// https://cses.fi/problemset/task/1675/
// Road Reparation - CSES




const int N = 1e5+5;
int n, m;

struct DSU {
    vector<int> par;
    void init(int n) {
        par.resize(n+1, -1);
    }
    int findParent(int a) {
        if(par[a] < 0) return a;
        return par[a] = findParent(par[a]);
    }
    bool unionSet(int a, int b){
        a = findParent(a);
        b = findParent(b);
        if(a == b) return 0;
        if(par[a] > par[b]) swap(a,b);
        par[a] += par[b];
        par[b] = a;
        return 1;
    }
    bool sameSet(int x, int y) { 
        return findParent(x) == findParent(y); 
    }
    int size (int x) { 
        return -par[findParent(x)]; 
    }
};


vector<vector<int>> input;
vector<vector<int>> result;

int kruskals() {
    sort(input.begin(), input.end());
    DSU dsu;
    dsu.init(n+1);

    int cost = 0;
    for(auto it: input) {
        int w = it[0], u = it[1], v = it[2];
        int uParent = dsu.findParent(u);
        int vParent = dsu.findParent(v);
        if(uParent != vParent) {
            result.pb(it);
            cost += w;
            dsu.unionSet(uParent, vParent);
        }
    }

    return cost;
}

void solve() {
    int u, v, w;
    cin >> n >> m;
    f(i, m) {
        cin >> u >> v >> w;
        input.pb({w, u, v});
    }
    
    int cost = kruskals();
    
    for(auto it: result) {
        int w = it[0], u = it[1], v = it[2];
        cout << u << " " << v << " " << w << endl;
    }

    if(result.size() != n - 1) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    cout << cost << endl;
}
