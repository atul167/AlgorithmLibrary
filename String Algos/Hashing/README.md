```
class Solution {
public:
    #define ll long long
    struct Hashing {
        ll add(ll a, ll b, ll mod) {
            ll res = (a + b) % mod;
            if (res < 0) res += mod;
            return res;
        }
        ll mult(ll a, ll b, ll mod) {
            ll res = (a * 1LL * b) % mod;
            if (res < 0) res += mod;
            return res;
        }
        ll power(ll a, ll b, ll mod) {
            a %= mod;
            ll res = 1;
            while (b) {
                if (b & 1) res = (res * a) % mod;
                a = (a * a) % mod;
                b >>= 1;
            }
            return res;
        }

        ll n;
        ll base = 256, mod = 1e9L + 9;
        vector<ll> p, p_inv, hash;

        void init(string s) {
            n = s.size();
            p = vector<ll>(n);
            p_inv = vector<ll>(n);
            hash = vector<ll>(n);

            p[0] = 1;
            p_inv[0] = 1;
            ll pw_inv = power(base, mod - 2, mod);
            for(ll i = 1; i <= n-1; i++) {
                p[i] = mult(p[i - 1], base, mod);
                p_inv[i] = mult(p_inv[i - 1], pw_inv, mod);
            }

            for(ll i = 0; i < n; i++) {
                hash[i] = add((i == 0) ? 0 : hash[i - 1], mult(p[n - 1 - i], s[i] - 'a' + 1, mod), mod);
            }
        }

        ll getHash(ll l, ll r) {
            ll h = hash[r];
            if(l > 0) h -= hash[l - 1];
            if(h < 0) h += mod;
            h = mult(h, p_inv[n - 1 - r], mod);
            return h;
        }
    };

    
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        
        if(m == 0) return 0;
        if(n == 0) return -1;

        Hashing hashStr, hashPat;
        hashStr.init(haystack);
        hashPat.init(needle);


        ll patternHash = hashPat.getHash(0, m - 1);

        for (int i = 0; i <= n - m; i++) {
            ll stringHash = hashStr.getHash(i, i + m - 1);
            if(stringHash == patternHash) {
                return i;
            }
        }
        
        return -1;
    }
};
```
