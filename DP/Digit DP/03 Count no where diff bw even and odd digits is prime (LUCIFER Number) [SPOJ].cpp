// https://www.spoj.com/problems/LUCIFER
// https://youtu.be/XfeWIsrCS1o



bool isPrime(int x) {
    if(x <= 1) return false;
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0) return false;
    }
    return true;
}

int dp[11][2][60][60];
string str;

int digit_dp(int pos = 0, int tight = 1, int eveSum = 0, int oddSum = 0) {
    if(pos == str.length()) {
        if(str.size() % 2) {
            /*
            Eg: 1234
            My soln.
            eveSum = 1 + 3
            oddSum = 2 + 4
            Acc to que.
            eveSum = 3 + 1
            oddSum = 4 + 2
            */
            return isPrime(oddSum - eveSum);
        } else {
            /*
            Eg: 12345
            My soln.
            eveSum = 1 + 3 + 5
            oddSum = 2 + 4
            Acc to que.
            eveSum = 4 + 2
            oddSum = 5 + 3 + 1
            */
            return isPrime(eveSum - oddSum);
        }
    }

    if(dp[pos][tight][eveSum][oddSum] != -1) return dp[pos][tight][eveSum][oddSum];

    int res = 0;
    int ub = tight ? str[pos] - '0' : 9;
    for(int i = 0; i <= ub; i++) {
        int od = oddSum, ev = eveSum;
        if(pos % 2) {
            od += i;
        } else {
            ev += i;
        }
            res += digit_dp(pos + 1, tight & (i == ub), ev, od);
    }
    return dp[pos][tight][eveSum][oddSum] = res;
}

void solve() {
    int l, r, totalCount, digit;
    cin >> l >> r;

    memset(dp, -1, sizeof dp);
    str = to_string(r);
    int ans1 = digit_dp(0, 1, 0, 0);

    memset(dp, -1, sizeof dp);
    str = to_string(l - 1);
    int ans2 = digit_dp(0, 1, 0, 0);

    cout << ans1 - ans2 << endl;
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
