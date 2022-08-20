// https://codeforces.com/problemset/problem/327/A
// https://www.scaler.com/problems/flip/

/*
There are n integers a1, a2, ..., an. Each of those integers can be either 0 or 1. 
You are allowed to do exactly one move: choose two indices i and j (1  ≤ i ≤ j ≤ n) and flips all values of a in range [i, j]. 
The goal of the game is that after exactly one move to obtain the maximum number of ones.
*/


/*
Note the net change in the number of 1s in string S when we flip bits of string S.
Say it has A 0s and B 1s. Eventually, there are B 0s and A 1s.

So, the number of 1s increased by A - B. We want to choose a subarray that maximizes this. 
Note that if we change 1s to -1, the sum of values will give us A - B. 
Then, we have to find a subarray with the maximum sum, which can be done via Kadane’s Algorithm.
*/


// Method 1
void solve() {
    cin >> n;
    int a[n];
    f(i, n) cin >> a[i];

    int ones = 0;
    f(i, n) {
        if(a[i] == 1) ones++;
    }

    int mxSoFar = 0, mxEndingHere = 0;
    f(i, n) {
        if(a[i] == 0) mxSoFar++;
        else mxSoFar--;

        if(mxSoFar < 0) mxSoFar = 0;

        mxEndingHere = max(mxEndingHere, mxSoFar);
    }

    if(ones == n) {
        cout << n - 1 << endl;
    } else {
        cout << ones + mxEndingHere << endl;
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
