// https://cp-algorithms.com/string/string-hashing.html#toc-tgt-5


const int N = 1e5;
int n, m;

int count_unique_substrings(string const& s) {
    int n = s.size();
    const int p = 31;
    const int mod = 1e9 + 9;

    vector<int> p_pow(n);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++)
        p_pow[i] = (p_pow[i-1] * p) % mod;

    vector<int> h(n + 1, 0);
    for (int i = 0; i < n; i++) {
        h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % mod;
    }

    // for substring s(i, i+l-1): left=i, right=i+l-1
    // from prefix (1 index based), cur_h = ((h[right+1] - h[left]) / p^i) % m = ((h[i + l] - h[i]) / p^i) % m
    // But we do not use inverse_mod here for p^i.
    // Hash calculation of substring concept:-
    // https://cp-algorithms.com/string/string-hashing.html#toc-tgt-3
    
    int cnt = 0;
    for (int l = 1; l <= n; l++) {
        set<int> hs;
        for (int i = 0; i <= n - l; i++) {
            long long cur_h = (h[i + l] - h[i] + mod) % mod;
            cur_h = (cur_h * p_pow[n-1-i]) % mod;
            hs.insert(cur_h);
        }
        cnt += hs.size();
    }
    return cnt;
}

void solve() {
    string s;
    cin >> s;
    cout << count_unique_substrings(s) << endl;
}
