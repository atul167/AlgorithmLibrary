// https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1
// https://www.geeksforgeeks.org/print-all-pairs-with-given-sum/

/*
Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.

Example 1:
Input:
N = 4, K = 6
arr[] = {1, 5, 7, 1}
Output: 2
Explanation: 
arr[0] + arr[1] = 1 + 5 = 6 and arr[1] + arr[3] = 5 + 1 = 6.

Example 2:
Input:
N = 4, X = 2
arr[] = {1, 1, 1, 1}
Output: 6
Explanation: 
Each 1 will produce sum 2 with any 1.
*/


class Solution {
public:
    int getPairsCount(int arr[], int n, int k) {
        sort(arr, arr + n);
        int i = 0, j = n - 1;
        int res = 0;

        while (i < j) {
            if (arr[i] + arr[j] == k) {
                int tempI = i;
                while (tempI < j && (arr[tempI] + arr[j]) == k) {
                    res++;
                    tempI++;
                }
                j--;
            }
            else if (arr[i] + arr[j] < k) {
                i++;
            }
            else if (arr[i] + arr[j] > k) {
                j--;
            }
        }
        return res;
    }
};


class Solution {
public:
    int getPairsCount(int arr[], int n, int k) {
        sort(arr, arr + n);
        int i = 0, j = n - 1;
        int res = 0;

        while (i < j) {
            if (arr[i] + arr[j] == k) {
                int tempI = i;
                while (tempI < j && (arr[tempI] == arr[i])) {
                    res++;
                    tempI++;
                }
                j--;
            }
            else if (arr[i] + arr[j] < k) {
                i++;
            }
            else if (arr[i] + arr[j] > k) {
                j--;
            }
        }
        return res;
    }
};





class Solution {
public:
    int getPairsCount(int arr[], int n, int k) {
        unordered_map<int, int> mp;

        int res = 0;
        for (int i = 0; i < n; i++) {
            res += mp[k - arr[i]];
            mp[arr[i]]++;
        }

        return res;
    }
};
