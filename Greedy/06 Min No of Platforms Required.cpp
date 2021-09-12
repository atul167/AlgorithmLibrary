// https://youtu.be/dxVcMDI7vyI
// https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/
// https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

/*
Method 1:
O(n^2)

The idea is to take every interval one by one and find the number of intervals that overlap with it. 
Keep track of the maximum number of intervals that overlap with an interval. 
Finally, return the maximum value.
*/
#include <algorithm> 
#include <iostream> 
 
using namespace std; 
  
// Returns minimum number of platforms reqquired 
int findPlatform(int arr[], int dep[], int n) 
{ 
  
    // plat_needed indicates number of platforms 
    // needed at a time 
    int plat_needed = 1, result = 1; 
    int i = 1, j = 0; 
  
    // run a nested  loop to find overlap 
    for (int i = 0; i < n; i++) { 
        // minimum platform 
        plat_needed = 1; 
  
        for (int j = i + 1; j < n; j++) { 
            // check for overlap 
            if ((arr[i] >= arr[j] && arr[i] <= dep[j]) ||  (arr[j] >= arr[i] && arr[j] <= dep[i])) 
                plat_needed++; 
        } 
  
        // update result 
        result = max(result, plat_needed); 
    } 
  
    return result; 
} 

int main() 
{ 
    int arr[] = { 900, 940, 950, 1100, 1500, 1800 }; 
    int dep[] = { 910, 1200, 1120, 1130, 1900, 2000 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << "Minimum Number of Platforms Required = " << findPlatform(arr, dep, n); 
    return 0; 
} 








/*
Method 2:
O(n log n)

The idea is to consider all events in sorted order. 
Once the events are in sorted order, trace the number of trains at any time keeping track of trains that have arrived, but not departed.
*/
class Solution{
public:
    // Function to find the minimum number of platforms required at the railway station such that no train waits.
    const int N = 1e5;
    
    int findPlatform(int arr[], int dep[], int n) {
        // Sort arrival and departure arrays
        sort(arr, arr + n);
        sort(dep, dep + n);
    
        // plat_needed indicates number of platforms needed at a time
        int plat_needed = 1, result = 1;
        int i = 1, j = 0;
    
        // Similar to merge in merge sort to process all events in sorted order
        while (i < n && j < n) {
            // If next event in sorted order is arrival, increment count of platforms needed
            // if (arr[i] <= dep[j]) { // use this if necessary
            if (arr[i] <= dep[j]) {
                plat_needed++;
                i++;
            }
            // Else decrement count of platforms needed
            else {
                plat_needed--;
                j++;
            }
    
            result = max(result, plat_needed);
        }
    
        return result;
    }
};














// Method 3.1: Cumulative Sum
class Solution{
public:
    // Function to find the minimum number of platforms required at the railway station such that no train waits.
    const int N = 1e5;
    
    int findPlatform(int arr[], int dep[], int n) {
        int pref[N] = {0};
    
        for(int i = 0; i < n; i++) {
            pref[arr[i]]++;
            pref[dep[i]+1]--;
        }
    
        for(int i = 1; i < N; i++) {
            pref[i] += pref[i-1];
        }
    
        int res = 0;
        for(int i = 0; i < N; i++) {
            res = max(res, pref[i]);
        }
    
        return res;
    }
};



// Method 3.2: Cumulative Sum
class Solution{
public:
    // Function to find the minimum number of platforms required at the railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n) {
        map<int, int> prefix;
    
        for(int i = 0; i < n; i++) {
            prefix[arr[i]]++;
            prefix[dep[i]+1]--;
        }
        
        int cnt = 0;
        auto prevItr = prefix.begin();
        for(auto it = prefix.begin(); it != prefix.end(); it++) {
            if(cnt == 0) {
                cnt++;
                continue;
            }
            prefix[it->first] += prefix[prevItr->first];
            prevItr = it;
        }
    
        int res = 0;
        for(auto it: prefix) {
            res = max(res, it.second);
        }
    
        return res;
    }
};
