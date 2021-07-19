// https://codeforces.com/problemset/problem/327/A


// Method 1
void solve() {
    cin >> n;
    int a[n];
    f(i, n) cin >> a[i];

    int mx = 0, mxSoFar = 0, ones = 0;
    f(i, n) {
        if(a[i] == 1) ones++;
        
        if(a[i] == 0) mxSoFar++;
        else mxSoFar--;

        if(mxSoFar < 0) mxSoFar = 0;

        mx = max(mx, mxSoFar);
    }

    if(ones == n) {
        cout << n-1 << endl;
    } else {
        cout << ones + mx << endl;
    }
}






// Method 2
void solve() {
    int x, y, z;
    cin >> n;
    vi a(n);
    f(i, n) cin >> a[i];

    vi b = a;

    f(i, n) {
        if(a[i] == 1) a[i] = -1;
        if(a[i] == 0) a[i] = 1;
    }

    int max_so_far = 0, max_ending_here = 0;

    int start = 0, end = 0;
    int beg = 0;

    for (int i = 0; i < n; i++) {
        max_ending_here = max_ending_here + a[i];

        if (max_ending_here < 0) {
            max_ending_here = 0;
            beg = i + 1;
        }

        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
            start = beg;
            end = i;
        }
    }

    // reversing 1 to 0 and 0 to 1 in the found range
    for(int i = start; i <= end; i++) {
        b[i] = 1 - b[i];
    }

    int res = 0;
    f(i, n) res += b[i];
    cout << res << endl;
}
