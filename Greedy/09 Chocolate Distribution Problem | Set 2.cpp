// https://www.geeksforgeeks.org/chocolate-distribution-problem-set-2/


#include <iostream>
using namespace std;

// FUnction to print minimum number
// of candies required
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
