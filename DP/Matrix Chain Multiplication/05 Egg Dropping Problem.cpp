// https://leetcode.com/problems/super-egg-drop/
// https://www.geeksforgeeks.org/egg-dropping-puzzle-dp-11/
// https://youtu.be/UvksR0hR9nA

/*
You are given k identical eggs and you have access to a building with n floors labeled from  1 to n.
You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, 
and any egg dropped at or below floor f will not break.
Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). 
If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.
Return the minimum number of moves that you need to determine with certainty what the value of f is.

Constraints:
1 <= k <= 100
1 <= n <= 10^4
*/



// TLE Solution
class Solution {
public:
    int superEggDrop(int k, int n) {
        int eggs = k, floors = n;
        int dp[eggs + 1][floors + 1];
        memset(dp, 0, sizeof dp);

        // i = egg, j = floor
        for (int i = 1; i <= eggs; i++) {
            for (int j = 1; j <= floors; j++) {
                // only 1 egg
                if (i == 1) {
                    dp[i][j] = j;
                }
                // only 1 floor
                else if (j == 1) {
                    dp[i][j] = 1;
                } else {
                    int mn = INT_MAX;
                    int l = 0, r = j - 1;
                    while(l < j && r >= 0) {
                        // egg breaks
                        int v2 = dp[i - 1][l];
                        // egg survives
                        int v1 = dp[i][r];
                        mn = min(mn, max(v1, v2));
                        l++; r--;
                    }
                    dp[i][j] = mn + 1;
                }
            }
        }

        return dp[eggs][floors];
    }
};


// AC Solution
class Solution {
public:
    int superEggDrop(int k, int n) {
        int eggs = k, floors = n;
        int dp[eggs + 1][floors + 1];
        memset(dp, 0, sizeof dp);

        // i = egg, j = floor
        for (int i = 1; i <= eggs; i++) {
            for (int j = 1; j <= floors; j++) {
                // only 1 egg
                if (i == 1) {
                    dp[i][j] = j;
                }
                // only 1 floor
                else if (j == 1) {
                    dp[i][j] = 1;
                } else {
                    int l = 1, r = j, temp = 0, ans = INT_MAX;
                    while(l <= r) {
                        int mid = (l + r) / 2;
                        int left = dp[i - 1][mid - 1];
                        int right = dp[i][j - mid];
                        temp = 1 + max(left, right);
                        if(left < right) l = mid + 1;
                        else r = mid - 1;
                        ans = min(ans, temp);
                    }
                    dp[i][j] = ans;
                }
            }
        }

        return dp[eggs][floors];
    }
};
























// ❌ This Solution will give TLE
class Solution {
public:
    int superEggDrop(int k, int n) {
        int eggs = k, floors = n;
        
        int dp[eggs+1][floors+1];
        for(int i = 0; i <= floors; i++) dp[0][i] = INT_MAX;
        for(int i = 0; i <= floors; i++) dp[1][i] = i;
        for(int i = 0; i <= eggs; i++) dp[i][0] = 0;
        for(int i = 0; i <= eggs; i++) dp[i][1] = 1;
        
        for(int i = 2; i <= eggs; i++) {
            for(int j = 2; j <= floors; j++) {
                int curr_ans = INT_MAX;
                int l = 0, r = j-1;
                while(l < j && r >= 0){
                    curr_ans = min(curr_ans, max(dp[i-1][l], dp[i][r]));
                    l++; r--;
                }
                dp[i][j] = curr_ans + 1;
            }
        }
        return dp[eggs][floors];
    }
};

// ✅ Using Binary Search
class Solution {
public:
    int superEggDrop(int k, int n) {
        int eggs = k, floors = n;
        
        int dp[eggs+1][floors+1];
        for(int i = 0; i <= floors; i++) dp[0][i] = INT_MAX;
        for(int i = 0; i <= floors; i++) dp[1][i] = i;
        for(int i = 0; i <= eggs; i++) dp[i][0] = 0;
        for(int i = 0; i <= eggs; i++) dp[i][1] = 1;
        
        for(int i = 2; i <= eggs; i++) {
            for(int j = 2; j <= floors; j++) {
                int l = 1, r = j, temp = 0, ans = INT_MAX;
                while(l <= r) {
                    int mid = (l + r) / 2;
                    int left = dp[i - 1][mid - 1];
                    int right = dp[i][j - mid];
                    temp = 1 + max(left, right);
                    if(left < right) l = mid + 1;
                    else r = mid - 1;
                    ans = min(ans, temp);
                }
                dp[i][j] = ans;
            }
        }
        return dp[eggs][floors];
    }
};
