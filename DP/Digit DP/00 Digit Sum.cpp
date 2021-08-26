// SPOJ Digit Sum
// https://www.spoj.com/problems/PR003004/
 


int dp[18][150][2];
string str;

int digit_dp(int pos, int sum, int tight){
    if(pos == str.length()) return sum;

    if(dp[pos][sum][tight] != -1) return dp[pos][sum][tight];
    
    int res = 0;
    int ub = tight ? (str[pos] - '0') : 9;

    for(int i = 0; i <= ub; i++) {
        res += digit_dp(pos + 1, sum + i, (tight & (i == ub)));
    }
    
    return dp[pos][sum][tight] = res;
}

int go(int num) {
    str = to_string(num);
    memset(dp, -1, sizeof(dp));
    return digit_dp(0, 0, 1);
}

void solve() {
    int l, r;
    cin >> l >> r;
    cout << go(r) - go(l - 1) << endl;
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
