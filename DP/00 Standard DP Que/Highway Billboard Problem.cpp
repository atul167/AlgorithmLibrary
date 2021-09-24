
// Method 1.1
// Time = O(n ^ 2), Space = O(n ^ 2)

#include <bits/stdc++.h>
using namespace std;

int M, t, n;
vector<int> x, revenue;

int go(int i, int prevPos) {
    if (i >= n) return 0;

    if (prevPos == -1) {
        int a = go(i + 1, -1);
        int b = revenue[i] + go(i + 1, i);

        return max(a, b);
    }

    int res = go(i + 1, prevPos);
    if (x[i] - x[prevPos] > t) {
        res = max(res, revenue[i] + go(i + 1, i));
    }
    return res;
}

int main() {
    M = 15;
    x = {6, 9, 12, 14};
    revenue = {5, 6, 3, 7};
    t = 2;

    n = x.size();

    cout << go(0, -1) << endl;
}








// Method 1.2 (LIS variation)
// Time = O(n ^ 2), Space = O(n)

#include <bits/stdc++.h>
using namespace std;

int M, t, n;
vector<int> x, revenue;

int main() {
    M = 15;
    x = {6, 9, 12, 14};
    revenue = {5, 6, 3, 7};
    t = 2;

    n = x.size();

    // LIS variation
    vector<int>dp(n);
    int res = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = revenue[i];
        res = max(res, revenue[i]);
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (x[i] - x[j] > t) {
                dp[i] = max(dp[i], dp[j] + revenue[i]);
            }
        }
        res = max(res, dp[i]);
    }

    cout << res << endl;
}
