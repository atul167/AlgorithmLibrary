// https://practice.geeksforgeeks.org/problems/maximize-toys0331/1


// Method 1: O(nlogn)
class Solution{
public:
    int toyCount(int n, int k, vector<int> arr) {
        sort(arr.begin(), arr.end());
        int res = 0, sum = 0;
    
        for(int i = 0; i < n; i++) {
            if(sum + arr[i] <= k) {
                sum += arr[i];
                res++;
            } else {
                break;
            }
        }
    
        return res;
    }
};



// Method 2: O(nlogn)
class Solution {
public:
    int toyCount(int n, int k, vector<int> arr) {
        sort(arr.begin(), arr.end());
        int res = 0, sum = 0, l = 0;

        for (int r = 0; r < n; r++) {
            sum += arr[r];

            while (sum > k) {
                sum -= arr[l];
                l++;
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};






// Method 3: O(n^2) [0-1 Knapsack Concept]
class Solution {
public:
    int toyCount(int n, int k, vector<int> arr) {
        int dp[n + 1][k + 1];

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                if (i == 0 || j == 0) dp[i][j] = 0;
                else if (j < arr[i - 1]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - arr[i - 1]] + 1);
                }
            }
        }

        return dp[n][k];
    }
};
