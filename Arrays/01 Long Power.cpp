
void long_pow(int x, int y) {
    vector<int> res;
    res.pb(1);
    int carry = 0;
    for(int i = 1; i <= y; i++) {
        for(int j = 0; j < res.size(); j++) {
            int prod = res[j] * x + carry;
            res[j] = prod % 10;
            carry = prod / 10;
        }
        while(carry) {
            res.pb(carry % 10);
            carry /= 10;
        }
    }
    for(int i = res.size() - 1; i >= 0; i--) {
        cout << res[i];
    }
    cout << endl;
}
 
void solve() {
    ll t, l, r;
    long_pow(2, 100);
} 
