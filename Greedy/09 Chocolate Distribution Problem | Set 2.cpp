// https://www.geeksforgeeks.org/chocolate-distribution-problem-set-2/

/*
Given an array A[] consisting of N integers, where each value represents the marks of the ith student.
The task is to find the minimum number of chocolates required to be distributed such that:
a) each student should be awarded with at least one chocolate
b) a student with higher marks should be awarded more chocolates than his adjacent students.

Examples:
Input: A[] = {10, 30, 20}
Output: 4
Explanation : Since, 30 is larger than its adjacent, so the second student must get more chocolates. 
Therefore, the minimum chocolates can be distributed as {1, 2, 1} = 1 + 2 + 1 = 4

Input: A[] = {23, 14, 15, 14, 56, 29, 14}
Output: 12
*/



// Time = O(n), Space = O(n)

#include <iostream>
using namespace std;

// FUnction to print minimum number of chocolates required
void minChocolates(int A[], int n) {
    int B[n];

    // Distribute 1 chocolate to each
    for (int i = 0; i < n; i++) {
        B[i] = 1;
    }

    // Traverse from left to right
    for (int i = 1; i < n; i++) {
        if (A[i] > A[i - 1])
            B[i] = B[i - 1] + 1;
        else
            B[i] = 1;
    }

    // Traverse from right to left
    for (int i = n - 2; i >= 0; i--) {
        if (A[i] > A[i + 1])
            B[i] = max(B[i + 1] + 1, B[i]);
        else
            B[i] = max(B[i], 1);
    }

    // Initialize sum
    int sum = 0;

    // Find total sum
    for (int i = 0; i < n; i++) {
        sum += B[i];
    }

    // Return sum
    cout << sum << "\n";
}

int main() {
    int A[] = { 23, 14, 15, 14, 56, 29, 14 };
    int n = sizeof(A) / sizeof(A[0]);
    minChocolates(A, n);
}
