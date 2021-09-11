// https://www.geeksforgeeks.org/maximum-product-subarray/


class Solution {
public:
    long long maxProduct(vector<int> arr, int n) {
        long long ans, maxp, minp;
        ans = maxp = minp = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] < 0) swap(maxp, minp);

            maxp = max<long long int>(maxp * arr[i], arr[i]);
            minp = min<long long int>(minp * arr[i], arr[i]);
            ans = max<long long>(ans, maxp);
        }
        return ans;
    }
};
