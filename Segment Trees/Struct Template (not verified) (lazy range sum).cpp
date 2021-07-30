const int N = 1e6+5;
int n, m;
 
int arr[N];

struct data {
    //Use required attributes
    int val;
    //Default Values
    data() : val(0) {};
};

struct SegTree {
    int N;
    vector<data> st;
    vector<bool> cLazy;
    vector<int> lazy;

    void init(int n) {
        N = n;
        st.resize(4 * N + 5);
        cLazy.assign(4 * N + 5, false);
        lazy.assign(4 * N + 5, 0);
    }

    //Write reqd merge functions
    void merge(data &cur, data &l, data &r) {
        cur.val = l.val + r.val;
    }
    
    //Handle lazy propagation appriopriately
    void propagate(int node, int L, int R) {
        if(L != R) {
            cLazy[node*2] = 1;
            cLazy[node*2 + 1] = 1;
            lazy[node*2] += lazy[node];
            lazy[node*2 + 1] += lazy[node];
        }
        st[node].val += (R - L + 1) * lazy[node];
        cLazy[node] = 0;
        lazy[node] = 0;
    }

    void build(int node, int L, int R) {
        if(L == R) {
            st[node].val = arr[L];
            return;
        }
        int M = (L + R)/2;
        build(node*2, L, M);
        build(node*2 + 1, M + 1, R);
        merge(st[node], st[node*2], st[node*2+1]);
    }

    data Query(int node, int L, int R, int i, int j) {
        if(cLazy[node]) 
            propagate(node, L, R);
        if(j < L || i > R) 
            return data();
        if(i <= L && R <= j) 
            return st[node];

        int M = (L + R)/2;
        data left = Query(node*2, L, M, i, j);
        data right = Query(node*2 + 1, M + 1, R, i, j);
        data cur;
        merge(cur, left, right);
        return cur;
    }

    data pQuery(int node, int L, int R, int pos) {
        if(cLazy[node]) 
            propagate(node, L, R);
        if(L == R) 
            return st[node];

        int M = (L + R)/2;
        if(pos <= M)
            return pQuery(node*2, L, M, pos);
        else
            return pQuery(node*2 + 1, M + 1, R, pos);
    }   

    void Update(int node, int L, int R, int i, int j, int val) {
        if(cLazy[node]) 
            propagate(node, L, R);
        if(j < L || i > R) 
            return;

        if(i <= L && R <= j) {
            cLazy[node] = 1;
            lazy[node] = val;
            propagate(node, L, R);
            return;
        }
        int M = (L + R)/2;
        Update(node*2, L, M, i, j, val);
        Update(node*2 + 1, M + 1, R, i, j, val);
        merge(st[node], st[node*2], st[node*2 + 1]);
    }

    void pUpdate(int node, int L, int R, int pos, int val) {
        if(cLazy[node]) 
            propagate(node, L, R);
        if(L == R) {
            cLazy[node] = 1;
            lazy[node] = val;
            propagate(node, L, R);
            return;
        }

        int M = (L + R)/2;
        if(pos <= M)
            pUpdate(node*2, L, M, pos, val);
        else
            pUpdate(node*2 + 1, M + 1, R, pos, val);

        merge(st[node], st[node*2], st[node*2 + 1]);
    }

    data query(int pos) {
        return pQuery(1, 1, N, pos);
    }

    data query(int l, int r) {
        return Query(1, 1, N, l, r);
    }

    void update(int pos, int val) {
        pUpdate(1, 1, N, pos, val);
    }

    void update(int l, int r, int val) {
        Update(1, 1, N, l, r, val);
    }
};

void solve() {
    SegTree st;
    st.init(n);
    st.build(1, 1, n);
} 
