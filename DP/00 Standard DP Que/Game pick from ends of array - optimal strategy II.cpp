// https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1

/*
You are given an array A of size N. The array contains integers and is of even length. 
The elements of the array represent N coin of values V1, V2, ....Vn. You play against an opponent in an alternating way.
In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the value of the coin.
You need to determine the maximum possible amount of money you can win if you go first.
Note: Both the players are playing optimally.

Example 1:
Input:
N = 4
A[] = {5,3,7,10}
Output: 15
Explanation: The user collects maximum value as 15(10 + 5)

Example 2:
Input:
N = 4
A[] = {8,15,3,7}
Output: 22
Explanation: The user collects maximum value as 22(7 + 15)
*/




// Method 1: (TLE)
class Solution {
public:
    #define ll long long

    // minimax returns player1score - player2score
    ll minimax(int left, int right, bool isMax, int nums[], vector<vector<vector<ll>>>& dp) {
        // Terminating condition
        if (left > right) {
            return 0;
        }

        if (dp[left][right][isMax] != -1) return dp[left][right][isMax];

        //  If current move is maximizer, find the maximum attainable value
        if (isMax) {
            ll l = nums[left] + minimax(left + 1, right, false, nums, dp);
            ll r = nums[right] + minimax(left, right - 1, false, nums, dp);
            return dp[left][right][isMax] = max(l, r);
        }

        // Else (If current move is Minimizer), find the minimum attainable value
        else {
            ll l = -nums[left] + minimax(left + 1, right, true, nums, dp);
            ll r = -nums[right] + minimax(left, right - 1, true, nums, dp);
            return dp[left][right][isMax] = min(l, r);
        }
    }

    long long maximumAmount(int arr[], int n) {
        vector<vector<vector<ll>>> dp(n + 5, vector<vector<ll>>(n + 5, vector<ll>(2, -1)));
        ll x = minimax(0, n - 1, 1, arr, dp);

        ll sum = 0;
        for (int i = 0; i < n; i++) sum += arr[i];

        /*
            player1 + player2 = sum
            player1 - player2 = x

            player1 = (sum + x) / 2;
        */

        return (sum + x) / 2;
    }
};







// Method 2: (TLE)
class Solution {
public:
#define ll long long

    // minimax returns player1score - player2score
    ll minimax(int left, int right, bool isMax, int nums[], vector<vector<vector<ll>>>& dp) {
        // Terminating condition
        if (left > right) {
            return 0;
        }

        if (dp[left][right][isMax] != -1) return dp[left][right][isMax];

        //  If current move is maximizer, find the maximum attainable value
        if (isMax) {
            ll l = nums[left] + minimax(left + 1, right, false, nums, dp);
            ll r = nums[right] + minimax(left, right - 1, false, nums, dp);
            return dp[left][right][isMax] = max(l, r);
        }

        // Else (If current move is Minimizer), find the minimum attainable value
        else {
            ll l = minimax(left + 1, right, true, nums, dp);
            ll r = minimax(left, right - 1, true, nums, dp);
            return dp[left][right][isMax] = min(l, r);
        }
    }

    long long maximumAmount(int arr[], int n) {
        vector<vector<vector<ll>>> dp(n + 5, vector<vector<ll>>(n + 5, vector<ll>(2, -1)));
        ll x = minimax(0, n - 1, 1, arr, dp);

        return x;
    }
};
