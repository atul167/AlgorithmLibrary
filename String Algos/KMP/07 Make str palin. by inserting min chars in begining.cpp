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


vector < int > computeLPSArray(string str) {
    int M = str.length();
    vector < int > lps(M);
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M) {
        if (str[i] == str[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];

            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int Solution::solve(string str) {
    string revStr = str;
    reverse(revStr.begin(), revStr.end());
    string concat = str + "$" + revStr;
    vector < int > lps = computeLPSArray(concat);
    return (str.length() - lps.back());
}
