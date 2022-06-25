// https://www.scaler.com/hire/test/problem/length-of-longest-consecutive-ones/

/*
Given a binary string A. It is allowed to do at most one swap between any 0 and 1. (i.e chose any one 0 and any one 1 and swap them)
Find and return the length of the longest consecutive 1’s that can be achieved.

Input 1:
A = "111000"
Output 1:
3

Input 2:
A = "111011101"
Output 2:
7
Explanation:
After swapiing A = "111111100"
*/



int maximum_one(string &s) {
    // To count all 1's in the string
    int cnt_one = 0;
     int n=s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == '1')
            cnt_one++;
    }

    // To store cumulative 1's
    int left[n], right[n];

    if (s[0] == '1')
        left[0] = 1;
    else
        left[0] = 0;

    if (s[n - 1] == '1')
        right[n - 1] = 1;
    else
        right[n - 1] = 0;
        
    for (int i = 1; i < n; i++) {
        if (s[i] == '1')
            left[i] = left[i - 1] + 1;
        else
            left[i] = 0;
    }

    for (int i = n - 2; i >= 0; i--) {
        if (s[i] == '1')
            right[i] = right[i + 1] + 1;

        else
            right[i] = 0;
    }

    int max_cnt = 0;
    
    for(int i=0; i<n; ++i )
        max_cnt=max(max_cnt,max(right[i],left[i]));
    
    for (int i = 1; i < n - 1; i++) {
        if (s[i] == '0') {
            int sum = left[i - 1] + right[i + 1];

            if (sum < cnt_one)
                sum++;

            max_cnt = max(max_cnt, sum);
        }
    }

    return max_cnt;
}

int Solution::solve(string A) {
    return maximum_one(A);
}
