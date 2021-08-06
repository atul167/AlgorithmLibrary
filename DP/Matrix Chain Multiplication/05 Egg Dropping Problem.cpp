// https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1
// https://www.geeksforgeeks.org/egg-dropping-puzzle-dp-11/

// https://youtu.be/UvksR0hR9nA


class Solution {
public:
    //Function to find minimum number of attempts needed in order to find the critical floor.
    int eggDrop(int eggs, int floors) {
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
                    for (int mj = j - 1, pj = 0; mj >= 0; mj--, pj++) {
                        // egg survives
                        int v1 = dp[i][mj];
                        // egg breaks
                        int v2 = dp[i - 1][pj];

                        int val = max(v1, v2);
                        mn = min(mn, val);
                    }

                    dp[i][j] = mn + 1;
                }
            }
        }

        return dp[eggs][floors];
    }
};
