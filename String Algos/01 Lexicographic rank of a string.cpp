// https://www.techiedelight.com/calculate-rank-lexicographically-sorted-permutations/
// https://www.interviewbit.com/problems/sorted-permutation-rank/
// https://www.geeksforgeeks.org/lexicographic-rank-of-a-string/



// Function to find the lexicographic rank of a string
#include <bits/stdc++.h>
using namespace std;

#define mod 1000003;

int fact(int n) {
    if (n == 0) return 1;
    return (n * fact(n - 1)) % mod;
}

int findRank(string s) {
    int res = 0;
    int n = s.length();

    for (int i = 0; i < n; i++) {
        int c = 0;
        for (int j = i + 1; j < n; j++) {
            if (s[j] < s[i])
                c++;
        }
        res += ( (c * fact(n - i - 1)) ) % mod;
    }
    // res = cnt of smaller strings + 1
    return (res + 1 ) % mod;
}


int main() {
    string str = "ACBFR";

    cout << findRank(str) << endl;

    return 0;
}
