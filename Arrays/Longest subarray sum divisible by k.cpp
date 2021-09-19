// https://www.geeksforgeeks.org/longest-subarray-sum-divisible-k/

class Solution {
public:
    int longSubarrWthSumDivByK(int arr[], int n, int k) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int res = 0, prefSumMod = 0;

        for (int i = 0; i < n; i++) {
            prefSumMod = (prefSumMod + arr[i]) % k;
            if (prefSumMod < 0) prefSumMod += k;

            if (mp.find(prefSumMod) == mp.end()) mp[prefSumMod] = i;

            res = max(res, i - mp[prefSumMod]);
        }

        return res;
    }
};
