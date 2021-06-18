/*
KMP algorithm depends on prefix function (PI array) for its implementation

You are given a string s of length n. 
The prefix function for this string is defined as an array π of length n.
π[i] = length of the longest proper prefix of the substring s[0…i] which is also a suffix of this substring. 

NOTE: A proper prefix of a string is a prefix that is not equal to the string itself. By definition, π[0] = 0.

Exampple:
String         : a b c a b c d
Prefix function: 0 0 0 1 2 3 0

Exampple:
String         : a a b a a a b
Prefix function: 0 1 0 1 2 2 3
*/




/*
Trivial Algorithm:

Mathematically the definition of the prefix function can be written as follows:
π[i] = max k (k from 0...i {s[0...k-1] == s[i-(k-1)...i]})
*/
// O(n^3)
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 0; i < n; i++) {
        for (int k = 0; k <= i; k++) {
            if (s.substr(0, k) == s.substr(i-k+1, k)) {
                pi[i] = k;
            }
        }
    }
    return pi;
}




// generates PI array (or LPS [largest prefix suffix])
vector<int> prefix_function(string &s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j-1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

vector<int> find_occurences(string &text, string &pattern){
    string cur = pattern + '#' + text;
    int sz1 = text.size(), sz2 = pattern.size();
    vector<int> v;
    vector<int> lps = prefix_function(cur);

    for(int i = sz2 + 1; i <= sz1 + sz2; i++) {
        if(lps[i] == sz2) {
            v.push_back(i - 2 * sz2);
        }
    }
    return v;
}

void solve(){
    string s, pat;
    cin >> s >> pat;
    vector<int> res = find_occurences(s, pat);
    for(int x: res) cout << x << " ";
}

int32_t main() {
    IOS
    clock_t begin = clock();
    ll T = 1;
    // cin >> T;
    while(T--)
    solve();
    cerr<<"Time elapsed : "<<(clock()-begin)*1000.0/CLOCKS_PER_SEC<<"ms"<<'\n';
    return 0;
}

/*
INP:
ashwaniashwani
ash

OUT:
0 7
*/
