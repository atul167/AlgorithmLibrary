// https://codeforces.com/problemset/problem/204/A


int dp[20][10][10][2];
string str;

int digit_dp(int pos, int firstDig, int curDig, int tight) {
    if(pos == str.length()) {
        return firstDig == curDig;
    };

    if(dp[pos][firstDig][curDig][tight] != -1) return dp[pos][firstDig][curDig][tight];
    
    int res = 0;
    int ub = tight ? (str[pos] - '0') : 9;

    for(int i = 0; i <= ub; i++) {
        if(pos == 0)
            res += digit_dp(pos + 1, i, i, (tight & (i == ub)));
        else
            res += digit_dp(pos + 1, firstDig, i, (tight & (i == ub)));
    }
    
    return dp[pos][firstDig][curDig][tight] = res;
}

int go(int n) {
    str = to_string(n);
    memset(dp, -1, sizeof(dp));
    return digit_dp(0, 0, 0, 1);
}

void solve() {
    int x, y, l, r;
    cin >> l >> r;

    int res = 0;
    if(r <= 10) {
        loop(i, l, r) if(i <= 9) res++;
        cout << res << endl;
        return;
    }

    if(l <= 10) {
        loop(i, l, 10) if(i <= 9) res++;
        l = 11;
    }

    res += go(r) - go(l-1);
    cout << res << endl;
}
