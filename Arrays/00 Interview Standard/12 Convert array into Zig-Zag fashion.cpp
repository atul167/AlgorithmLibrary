// https://www.geeksforgeeks.org/convert-array-into-zig-zag-fashion/

/*
Given an array of DISTINCT elements, rearrange the elements of array in zig-zag fashion in O(n) time. 
The converted array should be in form a < b > c < d > e < f. 

Example:

Input: arr[] = {4, 3, 7, 8, 6, 2, 1} 
Output: arr[] = {3, 7, 4, 8, 2, 6, 1}

Input: arr[] = {1, 4, 3, 2} 
Output: arr[] = {1, 4, 2, 3}
*/

/*
A Simple Solution is to first sort the array. After sorting, exclude the first element, swap the remaining elements in pairs. 
(i.e. keep arr[0] as it is, swap arr[1] and arr[2], swap arr[3] and arr[4], and so on). 
Time complexity: O(N log N) since we need to sort the array first.
*/


/*
Since the relation needed is a < b > c < d > e < f, it means the odd position elements have to be greater than its adjacent 
i.e. the even position elements. Simply traverse the array at the odd positions and check if it is greater than its adjacent elements, 
if it is not then swap them.
*/

#include <iostream>
using namespace std;

// Program for zig-zag conversion of array
void zigZag(int a[], int n)
{
	for (int i = 1; i < n; i += 2)
	{
	
		// Check if previous element
		// is greater than the current element
		// then swap them
		if (a[i - 1] > a[i])
			swap(a[i], a[i - 1]);

		// if next element is greater than
		// then the current element then
		// also swap them.
		if (i + 1 < n && (a[i + 1] > a[i]))
			swap(a[i], a[i + 1]);
	}
}

int main()
{
	int arr[] = { 4, 3, 7, 8, 6, 2, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	zigZag(arr, n);
	cout << "[ ";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << "]";
	return 0;
}

