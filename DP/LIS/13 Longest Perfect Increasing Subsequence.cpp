// https://www.spoj.com/problems/LPIS/

/*
Find the longest perfect increasing subsequence of given sequence.
In a perfect increasing subsequence the difference between any two consecutive elements is always 1.

For example, let’s consider a sequence S = {5, 2, 6, 3, 7, 8, 4}
{5, 7, 8} is an increasing subsequence of sequence S, but not a perfect increasing subsequence.
But {5, 6, 7, 8} is perfect increasing subsequence as the difference between any two consecutive elements is exactly 1.

CONSTRAINTS:
1 <= N <= 1e5
1 <= a[i] <= 1e6

OUTPUT:
A single integer in a line denoting the length of the longest perfect increasing subsequence.

Sample Input: #1
9
5 1 5 6 2 3 8 7 4
Sample Output: #1
4

Sample Input: #2
8
2 2 1 3 5 4 5 6
Sample Output: #2
5
*/


const int N = 1e6+5;
int n, m;

void solve() {
    cin >> n;
    vector<int> a(n);
    f(i, n) cin >> a[i];
    
    vector<int> dp(N, 0);
    int res = 1;

    for(int x: a) {
        dp[x] = dp[x - 1] + 1;
        res = max(res, dp[x]);
    }
    
    cout << res;
}
