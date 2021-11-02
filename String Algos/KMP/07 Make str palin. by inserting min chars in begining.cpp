// https://www.scaler.com/problems/make-string-pallindrome/

/*
Given a string A of size N consisting only of lowercase alphabets. The only operation allowed is to insert characters in the beginning of the string.
Find and return how many minimum characters are needed to be inserted to make the string a palindrome string.

Problem Constraints
1 <= N <= 10^6

Input 1:
A = "abc"
Output 1:
2
Explanation 1:
Insert 'b' at beginning, string becomes: "babc".
Insert 'c' at beginning, string becomes: "cbabc".

Input 2:
A = "bb"
Output 2:
0
Explanation 2:
There is no need to insert any character at the beginning as the string is already a palindrome. 
*/


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

int Solution::solve(string str) {
    string revStr = str;
    reverse(revStr.begin(), revStr.end());
    string concat = str + "$" + revStr;
    vector < int > lps = prefix_function(concat);
    return (str.length() - lps.back());
}
