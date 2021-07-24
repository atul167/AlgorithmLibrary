#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define mod 1000000007
#define dbg if(debug)
#define size(x) (int)(x).size()
using namespace std;
typedef pair<int,int> pii;
#ifndef ONLINE_JUDGE
    const bool debug = 1;
#else
    const bool debug = 0;
#endif
 
//---------------------- PROVE, THEN WRITE ----------------------//
 
struct Test{

	int dp[1<<20][11][3];
	vector<int> a,parts;
	int solve(int mask,int k,int order,int n){
		if(k == 0)
			return 0;
		int &ans = dp[mask][k][order];
		if(ans != -1)
			return ans;

		ans = solve(mask,k-1,0,n);
		if(order == 0)
			parts[k] = k;

		if(order < 2)
			for(int i=0;i<n;++i){
				if(mask&(1<<i))
					continue;
				int tmp = parts[k];
				parts[k] &= a[i];
				int res = parts[k] - ((order==1)?tmp:0);
				ans = max(ans,solve(mask|(1<<i),k,order+1,n)+res);
			}

		if(order == 0)
			parts[k] = 0;

		return ans;
	}

	void solve(){
		int n,k;
		cin>>n>>k;
		memset(dp,-1,sizeof dp);
		a = vector<int> (n);
		parts = vector<int> (k+1);
		for(int& x: a)
			cin>>x;


		cout<<solve(0,k,0,n)<<'\n';



	}
};
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int _ = 1;
	// cin>>_;
	while(_--){
		Test t;
		t.solve();
	}

	return 0;
}











































#define ll long long
#define pii pair<int,int> 
#define pb push_back
#define all(x) (x).begin(),(x).end()
void func(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<pii> a,b;
    for(int i=0;i<n;++i){
        for(int len=1;i-len+1>=0 && i+len-1<n;++len){
            if(s[i-len+1]!=s[i+len-1])
                break;
            a.pb({i-len+1,i+len-1});
            b.pb({i+len-1,i-len+1});
        }
    }
    for(int i=0;i<n;++i){
        for(int len=1;i-len+1>=0 && i+len<n;++len){
            if(s[i-len+1]!=s[i+len])
                break;
            a.pb({i-len+1,i+len});
            b.pb({i+len,i-len+1});
        }
    }
    sort(all(a));
    sort(all(b));
    vector<int> cntr(n),cntl(n);
    ll ans = 0;
    for(int i=n-1;i>=0;--i){
        cntr[i] = a.end()-lower_bound(a.begin(),a.end(),pii(i+1,0));
        cntl[i] = lower_bound(b.begin(),b.end(),pii(i,0))-b.begin();
    }

    for(auto pp: a){
        int l = pp.ff;
        int r = pp.ss;
        ans += 1ll*cntl[l]*cntr[r];
    }

    cout<<ans<<'\n';

}
