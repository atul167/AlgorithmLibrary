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



// Method 1
class Solution {
public:
    long long maxProduct(vector<int> arr, int n) {
        // base case
        if (n == 0) {
            return 0;
        }

        // maintain two variables to store the maximum and minimum product ending at the current index
        long long max_ending = arr[0], min_ending = arr[0];

        // to store the maximum product subarray found so far
        long long max_so_far = arr[0];

        // traverse the given array
        for (int i = 1; i < n; i++) {
            long long temp = max_ending;

            // update the maximum product ending at the current index
            max_ending = max<long long>({arr[i], arr[i] * max_ending, arr[i] * min_ending});

            // update the minimum product ending at the current index
            min_ending = min<long long>({arr[i], arr[i] * temp, arr[i] * min_ending});

            max_so_far = max<long long>(max_so_far, max_ending);
        }

        // return maximum product
        return max_so_far;
    }
};













// Method 2
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



// Method 2
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
