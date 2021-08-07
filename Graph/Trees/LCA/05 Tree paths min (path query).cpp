#include<bits/stdc++.h>	
#define pb push_back
#define endl "\n"
#define F first
#define S second 
#define inf 2e9    
using namespace std;

const int N = 3e5 + 5;
const int up = 20;
int level[N];
int lca[N][up], min_wt[N][up];
vector<pair<int, int>> g[N];

void fill(){
	for(int i = 0; i < N; i++)
		for(int j = 0; j < up; j++)
			lca[i][j] = 1, min_wt[i][j] = inf;
}

void dfs(int v, int par, int depth = 0){
	level[v] = depth;
	for(auto z: g[v]){
		auto to = z.F;
		if(to == par)
			continue;
		dfs(to, v, depth + 1);
	}
}

void build(int v, int par, int wt){
	lca[v][0] = par;
	min_wt[v][0] = wt;
	for(int i = 1; i < up; i++){
		lca[v][i] = lca[lca[v][i - 1]][i - 1];
		min_wt[v][i] = min(min_wt[lca[v][i - 1]][i - 1], min_wt[v][i - 1]);
	}
	for(auto z: g[v]){
		auto to = z.F;
		if(to == par)
			continue;
		build(to, v, z.S);
	}
}

int retlca(int a, int b){
	if(level[a] > level[b])
		swap(a, b);
	int lev_diff = level[b] - level[a];
	int mn = inf;
	for(int i = up - 1; i >= 0; i--){
		if(!(lev_diff & (1 << i)))
			continue;
		mn = min(mn, min_wt[b][i]);
		b = lca[b][i];
	}
	if(a == b){
		return mn;
	}
	for(int i = up - 1; i >= 0; i--){
		if(lca[a][i] == lca[b][i])
			continue;

		mn = min(mn, min_wt[a][i]);
		a = lca[a][i];
		mn = min(mn, min_wt[b][i]);
		b = lca[b][i];
		
	}
	return min({mn, min_wt[a][0], min_wt[b][0]});
}

main() {	
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	fill();
	int n, m;
	cin >> n >> m;
	for(int i = 0, x, y, w; i < m; i++){
		cin >> x >> y >> w;
		g[x].pb({y, w});
		g[y].pb({x, w});
	}
	dfs(1, 1);
	build(1, 1, inf);
	int q;	cin >> q;
	while(q--){
		int a, b;
		cin >> a >> b;
		cout << retlca(a, b);
		cout << endl;
	}
}
