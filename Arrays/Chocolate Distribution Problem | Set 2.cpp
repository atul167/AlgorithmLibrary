https://www.geeksforgeeks.org/chocolate-distribution-problem-set-2/


#include <iostream>
using namespace std;

// FUnction to print minimum number
// of candies required
void minChocolates(int A[], int N)
{
	int B[N];

	// Distribute 1 chocolate to each
	for (int i = 0; i < N; i++) {
		B[i] = 1;
	}

	// Traverse from left to right
	for (int i = 1; i < N; i++) {
		if (A[i] > A[i - 1])
			B[i] = B[i - 1] + 1;
		else
			B[i] = 1;
	}

	// Traverse from right to left
	for (int i = N - 2; i >= 0; i--) {
		if (A[i] > A[i + 1])
			B[i] = max(B[i + 1] + 1, B[i]);
		else
			B[i] = max(B[i], 1);
	}

	// Initialize sum
	int sum = 0;

	// Find total sum
	for (int i = 0; i < N; i++) {
		sum += B[i];
	}

	// Return sum
	cout << sum << "\n";
}

// Driver Code
int main()
{

	// Given array
	int A[] = { 23, 14, 15, 14, 56, 29, 14 };

	// Size of the given array
	int N = sizeof(A) / sizeof(A[0]);

	minChocolates(A, N);
}
