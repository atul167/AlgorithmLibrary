// https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/



#include <bits/stdc++.h>
using namespace std;

void printRepeatingAndMissing(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        while (arr[i] != arr[arr[i] - 1]) {
            swap(arr[i], arr[arr[i] - 1]);
        }
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] != i + 1) {
            cout << "Repeating: " << arr[i] << endl;
            cout << "Missing: " << i + 1 << endl;
        }
    }
}

int main() {
    int arr[] = { 1, 2, 3, 8, 2, 3, 5, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printRepeatingAndMissing(arr, n);
}






class Solution {
public:
    int *findTwoElement(int *arr, int n) {
        int *res = new int[2];
        for (int i = 0; i < n; i++) {
            while (arr[i] != arr[arr[i] - 1]) {
                swap(arr[i], arr[arr[i] - 1]);
            }
        }

        for (int i = 0; i < n; i++) {
            if (arr[i] != i + 1) {
                res[0] = arr[i];
                res[1] = i + 1;
            }
        }

        return res;
    }
};





















// https://www.interviewbit.com/problems/repeat-and-missing-number-array/

/*
Note: vector is immutable (i.e we cannot aply swap sort)

You are given a read only array of n integers from 1 to n.
Each integer appears exactly once except A which appears twice and B which is missing.
Return A and B.
Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example:
Input:[3 1 2 5 3] 
Output:[3, 4] 
*/



// First approach: using sum of squares

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long int n = A.size();
    long long int sumOfN = (n * (n+1) ) /2, sumOfNsq = (n * (n +1) *(2*n +1) ) / 6;
    long long int twice = 0, missing = 0;
    
    for(int i = 0; i < n; i++){
       sumOfN -= (long long int)A[i];
       sumOfNsq -= (long long int)A[i] * (long long int)A[i];
    }
    
    missing = (sumOfN + sumOfNsq / sumOfN) / 2;
    twice = missing - sumOfN;
    return {twice, missing};
}





// Second approach: using xor

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    int xo = 0;
    for (int i = 0; i < n; i++) {
        xo = xo ^ A[i];
        xo = xo ^ (i + 1);
    }
    int setbit = xo & (~(xo - 1));
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] & setbit)
            x = x ^ A[i];
        else
            y = y ^ A[i];
        if ((i + 1)&setbit)
            x = x ^ (i + 1);
        else y = y ^ (i + 1);
    }
    vector<int> res(2);
    for (int i = 0; i, n; i++) {
        if (A[i] == x) {
            res[0] = x;
            res[1] = y;
            break;
        } else if (A[i] == y) {
            res[0] = y;
            res[1] = x;
            break;
        }
    }
    return res;
}
