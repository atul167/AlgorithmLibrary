// Usage:

/*
next_permutation(s.begin(), s.end())
*/


// Print all permutaions of string
void solve() {
    string s;
    cin >> s;
    // sorting is required
    sort(s.begin(), s.end());
    do {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));
}
