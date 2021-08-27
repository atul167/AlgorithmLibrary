// https://www.geeksforgeeks.org/find-duplicates-in-on-time-and-constant-extra-space/
// https://practice.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1

class Solution {
public:
    // Utility function that puts all non-positive (0 and negative) numbers on left side of arr[] and return count of such numbers
    int segregate(int arr[], int n) {
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] <= 0) {
                swap(arr[i], arr[j]);
                // increment count of non-positive integers
                j++;
            }
        }

        return j;
    }

    // Find the smallest positive missing number in an array that contains all positive integers
    int findMissingPositive(int arr[], int size) {
        int i;

        // Mark arr[i] as visited by
        // making arr[arr[i] - 1] negative.
        // Note that 1 is subtracted
        // because index start
        // from 0 and positive numbers start from 1
        for (i = 0; i < size; i++) {
            if (abs(arr[i]) - 1 < size && arr[abs(arr[i]) - 1] > 0)
                arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        }

        // Return the first index value at which is positive
        for (i = 0; i < size; i++) {
            if (arr[i] > 0) {
                // 1 is added because indexes start from 0
                return i + 1;
            }
        }
        return size + 1;
    }

    // Find the smallest positive missing number in an array of both positive and negative integers
    int missingNumber(int arr[], int n) {
        // First separate negative and positive numbers
        int shift = segregate(arr, n);

        // findMissingPositive for positive part
        return findMissingPositive(arr + shift, n - shift);
    }
};
