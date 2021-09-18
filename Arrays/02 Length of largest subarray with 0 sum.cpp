// https://www.geeksforgeeks.org/find-the-largest-subarray-with-0-sum/
// https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1


class Solution {
public:
    int maxLen(vector<int>& arr, int n) {
        // Map to store the previous sums
        unordered_map<int, int> prevSums;

        int sum = 0;
        int max_len = 0;

        // Traverse through the given array
        for (int i = 0; i < n; i++) {
            sum += arr[i];

            if (sum == 0) {
                max_len = i + 1;
            }

            if (prevSums.find(sum) != prevSums.end()) {
                max_len = max(max_len, i - prevSums[sum]);
            }  else {
                prevSums[sum] = i;
            }
        }

        return max_len;
    }
};







class Solution {
public:
    int maxLen(vector<int>& arr, int n) {
        // Map to store the previous sums
        unordered_map<int, int> prevSums;
        
        prevSums[0] = -1;

        int sum = 0;
        int max_len = 0;

        // Traverse through the given array
        for (int i = 0; i < n; i++) {
            sum += arr[i];

            if (prevSums.find(sum) != prevSums.end()) {
                max_len = max(max_len, i - prevSums[sum]);
            }  else {
                prevSums[sum] = i;
            }
        }

        return max_len;
    }
};
