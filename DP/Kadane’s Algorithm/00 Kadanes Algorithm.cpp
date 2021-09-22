// https://www.techiedelight.com/print-continuous-subarray-with-maximum-sum/

void kadane() {
    vector < int > arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = arr.size();

    int max_so_far = INT_MIN, max_ending_here = 0;
    int start = 0, end = 0;

    // stores starting index of a positive-sum sequence
    int beg = 0;

    // traverse the given array
    for (int i = 0; i < n; i++) {
        // update the maximum sum of subarray "ending" at index `i`
        max_ending_here = max_ending_here + arr[i];

        // update result if the current subarray sum is found to be greater
        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
            start = beg;
            end = i;
        }

        // if the maximum sum is negative, set it to 0
        if (max_ending_here < 0) {
            max_ending_here = 0;
            beg = i + 1;
        }
    }

    cout << "Sum = " << max_so_far << endl;

    cout << "Subarray = ";
    for (int i = start; i <= end; i++) {
        cout << arr[i] << " ";
    }
}












// Method 2

/*
For i'th index:
curr_max = max contiguous subarray sum ending at index i (including a[i]) 
*/

class Solution {
public:
    long long maxSubarraySum(int a[], int n) {
        long long max_so_far = a[0];
        long long curr_max = a[0];

        for (int i = 1; i < n; i++) {
            curr_max = max<long long>(a[i], curr_max + a[i]);
            max_so_far = max<long long>(max_so_far, curr_max);
        }

        return max_so_far;
    }
};
