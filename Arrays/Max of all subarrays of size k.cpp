// https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/

/*
Algorithm:  

1) Create a deque to store k elements.
2) Run a loop and insert first k elements in the deque. 
   Before inserting the element, check if the element at the back of the queue is smaller than the current element, 
   if it is so remove the element from the back of the deque, until all elements left in the deque are greater than the current element. 
   Then insert the current element, at the back of the deque.
3) Print the front element of the deque.
4) Now, run a loop from k to end of the array.
5) Remove the element from the front of the queue if they are out of the current window.
6) Insert the next element in the deque. Before inserting the element, check if the element at the back of the queue is smaller than the current element, 
   if it is so remove the element from the back of the deque, until all elements left in the deque are greater than the current element. 
   Then insert the current element, at the back of the deque.
7) Print the maximum element of the window.
*/



#include <bits/stdc++.h>
using namespace std;

// A Dequeue (Double ended queue) based method for printing maximum element of all subarrays of size k
void printKMax(int arr[], int n, int k) {

    // Create a Double Ended Queue, Qi that will store indexes of array elements
    // The queue will store indexes of useful elements in every window 
    // It will maintain decreasing order of values from front to rear in Qi, 
    // i.e., arr[Qi.front[]] to arr[Qi.rear()] are sorted in decreasing order
    deque<int> Qi(k);

    /* Process first k (or first window) elements of array */
    int i;
    for (i = 0; i < k; ++i) {
        // For every element, the previous smaller elements are useless so remove them from Qi
        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()]) {
            // Remove from rear
            Qi.pop_back();
        }

        // Add new element at rear of queue
        Qi.push_back(i);
    }

    // The element at the front of
    // the queue is the largest element of
    // previous window, so print it
    cout << arr[Qi.front()] << " ";

    // Process rest of the elements, i.e., from arr[k] to arr[n-1]
    for (; i < n; ++i) {
        // Remove the elements which
        // are out of this window
        while ((!Qi.empty()) && Qi.front() <= i - k) {
            // Remove from front of queue
            Qi.pop_front();
        }


        // Remove all elements smaller than the currently being added element 
        // (remove useless elements)
        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()]) {
            Qi.pop_back();
        }

        // Add current element at the rear of Qi
        Qi.push_back(i);

        // Print the maximum element of last window
        cout << arr[Qi.front()] << " ";
    }
}

int main() {
    int arr[] = { 12, 1, 78, 90, 57, 89, 56 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    printKMax(arr, n, k);
    return 0;
}
