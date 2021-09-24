// https://www.hackerrank.com/challenges/billboards/problem

/*
Constraints:
1 <= n <= 1e5
1 <= k <= n
0 <= a[i] <= 2e9
*/



/*
Note:
Maximum subsequence sum such that no K elements are consecutive.
https://www.geeksforgeeks.org/maximum-subsequence-sum-such-that-no-k-elements-are-consecutive/
For this problem - replace k with (k - 1)
*/




// Time = O(n * k), Space = O(n)
const int N = 1e5 + 5;
int n, m, k;


void solve() {
    cin >> n >> k;
    vector<int> a = vector<int>(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    if (n <= k) {
        int res = 0;
        for (int i = 1; i <= n; i++) res += a[i];
        cout << res << endl;
        return;
    }

    vector<int> dp(n + 1);
    dp[0] = 0;
    for (int i = 1; i <= k; i++) {
        dp[i] = dp[i - 1] + a[i];
    }

    for (int i = k + 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        int sum = 0;
        for (int j = i; j > i - k; j--) {
            sum += a[j];
            dp[i] = max(dp[i], sum + dp[j - 2]);
        }
    }

    cout << dp[n] << endl;
}







// Time = O(n * k), Space = O(n * k)
const int N = 1e5 + 5;
int n, m, k;

vector<int> a;
int dp[N][100];

int go(int pos, int state) {
    if (pos >= n) return 0;

    if (dp[pos][state] != -1) return dp[pos][state];

    int x = 0, y = 0;
    if (state < k) {
        x = a[pos] + go(pos + 1, state + 1);
    }
    y = go(pos + 1, 0);

    return dp[pos][state] = max(x, y);
}

void solve() {
    cin >> n >> k;
    a = vector<int>(n);
    f(i, n) cin >> a[i];
    memset(dp, -1, sizeof dp);
    cout << go(0, 0);
}
