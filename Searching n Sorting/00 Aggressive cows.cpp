// https://www.spoj.com/problems/AGGRCOW/

/*
Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. 
The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).
His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. 
To prevent the cows from hurting each other, John wants to assign the cows to the stalls, 
such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
*/


// TTTTTFFFFF

const int N = 1e6+5;
int n, m;

bool check(int mid, int c, vector<int>& a) {
    int cnt = 1, prevPos = 0;
    for(int i = 1; i < n; i++) {
        if(a[i] - a[prevPos] >= mid) {
            prevPos = i, cnt++;
        }
    }
    return cnt >= c;
}
 
void solve() {
    int x, y, c;
    cin >> n >> c;
    vector<int> a(n);
    f(i, n) cin >> a[i];
 
    sort(all(a));
 
    int lo = 0, hi = a[n-1];
    while(lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;

        if(check(mid, c, a)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    cout << lo << endl;
}
 
signed main() {
    IOS
    clock_t begin = clock();
    PRECISION(10);
    int t = 1;
    cin >> t;
    f(i, t) {
        solve();
    }
    cerr << "Time elapsed: " << (clock() - begin) * 1000.0 / CLOCKS_PER_SEC << "ms" << '\n';
}
