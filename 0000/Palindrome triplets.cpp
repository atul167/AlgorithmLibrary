void PalindromicSubstrings(string s){
    int n = s.size();
    int dp[n][n] = {0}, pref[n][n] = {0}, suf[n][n] = {0};

    for(int gap = 0; gap < n; gap++) {
        for(int i=0, j=gap;  j<n;  i++, j++) {
            if(gap == 0) {
                dp[i][j] = 1;
            } else if(gap == 1) {
                if(s[i] == s[j]) dp[i][j] = 1;
                else dp[i][j] = 0;
            } else {
                if(s[i] == s[j] && dp[i + 1][j - 1]) dp[i][j] = 1;
                else dp[i][j] = 0;
            }
        }
    }

    for(int j = 0; j < n; j++) {
        for(int i = 0; i <= j; i++) {
            if(i == 0)
                pref[i][j] = dp[i][j];
            else 
                pref[i][j] = pref[i-1][j] + dp[i][j];
        }
    }
    for(int i = 1; i < n; i++) pref[i][i] += pref[i-1][i-1];

    for(int i = 0; i < n; i++) {
        for(int j = n-1; j >= i; j--) {
            if(j == n-1)
                suf[i][j] = dp[i][j];
            else 
                suf[i][j] = suf[i][j+1] + dp[i][j];
        }
    }
    for(int i = n-2; i >= 0; i--) suf[i][i] += suf[i+1][i+1];

    int res = 0;
    for(int gap = 0; gap < n; gap++) {
        for(int i=0, j=gap;  j<n;  i++, j++) {
            if(i-1 >= 0 && j+1 < n) {
                int x = pref[i-1][i-1] * dp[i][j] * suf[j+1][j+1];
                res += x;
            }
        }
    }
    cout << res << endl;

}
