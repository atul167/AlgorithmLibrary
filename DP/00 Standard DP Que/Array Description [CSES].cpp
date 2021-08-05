// https://cses.fi/problemset/task/1746/

/*
You know that an array has n integers between 1 and m, and the absolute difference between two adjacent values is at most 1.
Given a description of the array where some values may be unknown, your task is to count the number of arrays that match the description.

Input:
The first input line has two integers n and m: the array size and the upper bound for each value.
The next line has n integers x1,x2,…,xn: the contents of the array. Value 0 denotes an unknown value.

Output:
Print one integer: the number of arrays modulo 10^9+7.

Constraints:
1 ≤ n ≤ 10^5
1 ≤ m ≤ 100
0 ≤ xi ≤ m
*/

const int N = 1e5+5;
int n, m;

int a[N];
int dp[N][105];

int go(int i, int prev) {
    if(i == n) {
        return 1;
    }
    if(a[i] != 0 && abs(a[i] - prev) > 1) {
        return 0;
    }

    if(dp[i][prev] != -1) return dp[i][prev];

    int res = 0;

    if(i == 0) {
        if(a[i] == 0) {
            loop(j, 1, m) {
                res += go(i+1, j);
                res = (res + MOD) % MOD;
            }
        } else {
            res += go(i+1, a[i]);
            res = (res + MOD) % MOD;
        }
    } else {
        if(a[i] == 0) {
            int j = prev - 1;
            if(j > 0) {
                res += go(i+1, j);
                res = (res + MOD) % MOD;
            }

            j = prev;
            res += go(i+1, j);
            res = (res + MOD) % MOD;
            
            j = prev + 1;
            if(j <= m) {
                res += go(i+1, j);
                res = (res + MOD) % MOD;
            }
        } else {
            res += go(i+1, a[i]);
            res = (res + MOD) % MOD;
        }
    }

    return dp[i][prev] = res;
}

void solve() {
    cin >> n >> m;
    f(i, n) cin >> a[i];

    if(n == 1) {
        if(a[0] == 0) {
            cout << m << endl;
        } else {
            cout << 1 << endl;
        }
        return;
    }

    memset(dp, -1, sizeof dp);
    cout << go(0, a[0]);
}
