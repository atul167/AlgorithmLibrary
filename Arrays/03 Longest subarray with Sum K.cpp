// https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

class Solution {
public:
    int lenOfLongSubarr(int arr[],  int n, int k)  {
        unordered_map<int, int> mp;
        int sum = 0, maxLen = 0, startIdx, endIdx;

        // traverse the given array
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (sum == k) {
                maxLen = i + 1;
                startIdx = 0;
                endIdx = i;
            }

            if (mp.find(sum - k) != mp.end()) {
                if (maxLen < (i - mp[sum - k])) {
                    maxLen = i - mp[sum - k];
                    startIdx = mp[sum - k] + 1;
                    endIdx = i;
                }
            }

            if (mp.find(sum) == mp.end()) mp[sum] = i;
        }

        // required maximum length
        return maxLen;
    }
};

















class Solution {
public:
    int lenOfLongSubarr(int arr[],  int n, int k)  {
        unordered_map<int, int> mp;
        int sum = 0, maxLen = 0, startIdx, endIdx;

        mp[0] = -1;

        // traverse the given array
        for (int i = 0; i < n; i++) {
            sum += arr[i];
  
            if (mp.find(sum - k) != mp.end()) {
                if (maxLen < (i - mp[sum - k])) {
                    maxLen = i - mp[sum - k];
                    startIdx = mp[sum - k] + 1;
                    endIdx = i;
                }
            }

            if (mp.find(sum) == mp.end()) mp[sum] = i;
        }

        // required maximum length
        return maxLen;
    }
};
