// single source shortest path (includes negative edges)
// this is directed version
// For questions related to visiting atleast K edges only consider relaxation from 0 to K only instead of (n-1)  

// drawback: If there is a cycle with negative (ie negative weight cycle), it fails
// it will work fine for cycles of positive weight

// therefore after relaxing >= n times, then also path weights are changing that means there is a negative weight cycle in the graph

// https://leetcode.com/problems/cheapest-flights-within-k-stops/

#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

typedef long long int ll;
#define int long long int
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FRE freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define debug cout << "debug" << endl;
#define f(i,n) for(ll i=0;i<n;i++)
#define fa(i,a,n) for(ll i=a;a<n?i<n:i>=n;a<n?i+=1:i-=1)
#define loop(i,a, n) for(ll i = a; i <= n; i++)
#define loopb(i,a, n) for(ll i = a; i >= n; i--)
#define pb push_back
#define pf push_front
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define setmem(x, k) memset(x, k, sizeof(x))
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define MOD 1000000007
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int>	vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef long double ld;
typedef vector<vector<ll>> matrix;
ll dx[] = {0, 1, 0, -1};
ll dy[] = {-1, 0, 1, 0};
const ll N = 1e5+5;
// ll a[N], b[N], dp[N], level[N], vis[N], in[N], out[N];
// vl g[N];
ll n, m;

void solve() {
	ll u, v, w, src;
	cin >> n >> m;
	vector<vector<ll>> g;
	f(i, m){
		cin >> u >> v >> w;
		vector<ll> temp;
		temp.pb(u);
		temp.pb(v);
		temp.pb(w);
		g.pb(temp);
	}
	cin >> src;
	vector<int> dis(n, INT_MAX);
    dis[src] = 0;
    for(int i = 1; i <= n-1; i++){
        vector<int> tempDis(dis);
        for(auto x: g){
            int u = x[0];
            int v = x[1];
            int d = x[2];
            tempDis[v] = min(tempDis[v], dis[u] + d);
        }
        dis = tempDis;
    }
    for(int i = 0; i < n; i++){
    	cout << dis[i] << " ";
    }
}

int32_t main() {
	IOS
	solve();
	cerr<<"Time elapsed : "<<clock()*1000.0/CLOCKS_PER_SEC<<"ms"<<'\n'; 
	return 0;
}
