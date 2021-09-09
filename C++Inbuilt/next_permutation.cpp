// Print all permutaions of string


// Method 1: My own nextPermutation
bool nextPermutation(string& str) {
    int n = str.size();
    if(n == 0) return false;
    
    int i = n - 1;
    while(i > 0 && str[i] <= str[i - 1]) {
        i--;
    }
    
    // no next permutation, i.e. already largest
    if(i == 0) return false;
    
    int j = n - 1;
    while(str[j] <= str[i - 1]) {
        j--;
    }
    
    swap(str[i - 1], str[j]);
    reverse(str.begin() + i, str.end());
    return true;
}

void solve() {
    string s;
    cin >> s;

    // sorting is required
    sort(s.begin(), s.end());
    do {
        cout << s << endl;
    } while (nextPermutation(s));
}










// Method 2: Inbuilt next_permutation
void solve() {
    string s;
    cin >> s;
    // sorting is required
    sort(s.begin(), s.end());
    do {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));
}
