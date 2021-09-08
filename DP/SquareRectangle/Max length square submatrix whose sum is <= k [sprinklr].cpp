/*
Given a rectangular matrix.
Find a maximum side square submattrix whose sum <= k.
*/


const int N = 1e5 + 5;
int n, m, k;

vector<vector<int>> matrix;
vector<vector<int>> dp;

void initDp() {
    dp = vector<vector<int>>(n+1, vector<int>(m+1, 0));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            dp[i][j] = matrix[i-1][j-1] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }
}

int getSubmatrixSum(int r1, int c1, int r2, int c2) {
    r1++, c1++, r2++, c2++;
    return dp[r2][c2] - dp[r2][c1-1] - dp[r1-1][c2] + dp[r1-1][c1-1];
}

bool check(int mid) {
    for(int i = 0; i <= n-mid; i++) {
        for(int j = 0; j <= m-mid; j++) {
            int r1 = i, c1 = j, r2 = i+mid-1, c2 = j+mid-1;
            if(getSubmatrixSum(r1, c1, r2, c2) <= k) return true;
        }
    }

    return false;
}


void findMaxSum() {
    initDp();

    int lo = 1, hi = min(n, m);

    while(lo < hi) {
        // int mid = (lo + hi + 1) / 2;
        int mid = lo + (hi - lo + 1) / 2;
        
        if(check(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }

    cout << lo << endl;
}
 
void solve() {
    matrix = { { 1, 2, 10, 2 },
             { 1, 3, 10, 1 },
             { 2, 1, 1, 1 },
             { 4, 1, 1, 1 },
             { 1, 1, 1, 1 } };
    k = 13;

    n = matrix.size(), m = matrix[0].size();
    f(i, n) {
        f(j, m) cout << matrix[i][j] << " ";
        cout << endl;
    }
    findMaxSum();
}
