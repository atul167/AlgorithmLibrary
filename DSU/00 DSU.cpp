// Path compression DSU

/*--------------------DSU BEGIN----------------------------------*/
int par[N];
void initialize() {
    for(int i = 0; i < N; i++) {
        par[i] = -1;
    }
}
int findParent(int a) {
    if(par[a] < 0)
        return a;
    return par[a] = findParent(par[a]);
}
void unionSet(int a, int b){
    a = findParent(a);
    b = findParent(b);
    if(a == b) return;
    if(par[a] > par[b]) swap(a,b);
    par[a] += par[b];
    par[b] = a;
}
/*--------------------DSU END------------------------------------*/













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


























unordered_map<ll,ll> par, size;

void initialize(){
	for(ll i=1; i<=n; i++){
		par[i]=i;
		size[i]=1;
	}
}

ll find_par(ll a){
	if(par[a]==a)
		return a;
	return find_par(par[a]);
}

void union_set(ll a, ll b){
	a=find_par(a);
	b=find_par(b);
	if(a==b)
		return;
	if(size[a]<size[b])
		swap(a,b);
	par[b]=a;
	size[a]+=size[b];
}

int32_t main()
{
	IOS
	ll t,k,x,y,z,p,q,u,v,ct=0,flag=0;
	cin>>n;
	initialize();
	cin>>t;
	while(t--){
		cin>>x>>y;
		cout<<find_par(x)<<" "<<find_par(y)<<endl;
		union_set(x,y);
		cout<<find_par(x)<<" "<<find_par(y)<<endl;
	}
}
