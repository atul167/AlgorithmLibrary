// https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/

/*
Partition a set into two subsets such that the difference of subset sums is minimum
*/


void solve() {
    cin >> n;
    int a[n];
    f(i, n) cin >> a[i];

    int sum = 0;
    for(int i = 0; i < n; i++) sum += a[i];

    bool dp[n + 1][sum + 1];
    for (int i = 0; i <= n; i++) dp[i][0] = 1;
    for (int j = 1; j <= sum; j++) dp[0][j] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < a[i - 1]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - a[i - 1]];
            }
        }
    }

    // Initialize difference of two sums.
    int diff = INT_MAX;
 
    // Find the largest j such that dp[n][j] is true where j loops from sum/2 t0 0
    for (int j = sum / 2; j >= 0; j--) {
        // Find the
        if (dp[n][j]) {
            diff = sum - 2 * j;
            break;
        }
    }
    cout << diff << endl;
}
