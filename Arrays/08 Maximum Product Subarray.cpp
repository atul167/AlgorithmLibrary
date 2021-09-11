// https://www.geeksforgeeks.org/maximum-product-subarray/


/*
When we are at index j:

maxp = maximum product of suffix (i, i+1, ..., j) ending at index j (i.e. including arr[j])
     = (arr[i] * arr[i+1] * ... * arr[j]), where i <= j
minp = minimum product of suffix (i, i+1, ..., j) ending at index j (i.e. including arr[j])
     = (arr[i] * arr[i+1] * ... * arr[j]), where i <= j

(last index j is included same as we do in dp LIS) 


NOTE: 
Same problem can be extended to calculate Minimum Product Subarray
*/


// Maximum Product Subarray
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






// Minimum Product Subarray
class Solution {
public:
    long long maxProduct(vector<int> arr, int n) {
        long long ans, maxp, minp;
        ans = maxp = minp = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] < 0) swap(maxp, minp);

            maxp = max<long long int>(maxp * arr[i], arr[i]);
            minp = min<long long int>(minp * arr[i], arr[i]);
            ans = min<long long>(ans, minp);
        }
        return ans;
    }
};
