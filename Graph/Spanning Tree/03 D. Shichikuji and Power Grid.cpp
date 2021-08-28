// https://codeforces.com/contest/1245/problem/D



const int N = 2e3+5;
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


vector<vector<int>> input, result;

int kruskals() {
    sort(input.begin(), input.end());
    DSU dsu;
    dsu.init(n);

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


int x[N], y[N], c[N], k[N];

int distance(int i, int j) {
    return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

void solve() {
    cin >> n;
    loop(i, 1, n) cin >> x[i] >> y[i];

    loop(i, 1, n) cin >> c[i];
    loop(i, 1, n) cin >> k[i];

    loop(i, 1, n) {
        input.pb({c[i], 0, i});
    }

    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <=n ; j++) {
            input.pb({(k[i] + k[j]) * distance(i, j), i, j});
        }
    }

    int res = kruskals();
    cout << res << endl;

    vector<int> v1;
    vector<pair<int, int>> v2;
    for(auto it: result) {
        int w = it[0], u = it[1], v = it[2];
        if(u == 0) {
            v1.pb(v);
        } else {
            v2.pb({u, v});
        }
    }

    cout << v1.size() << endl;
    for(int i: v1) cout << i << " ";
    cout << endl;
    
    cout << v2.size() << endl;
    for(auto i: v2) cout << i.F << " " << i.S << endl;
}
