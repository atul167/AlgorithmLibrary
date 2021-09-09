// https://www.geeksforgeeks.org/find-the-largest-subarray-with-0-sum/


void solve() {
    cin >> n;
    vector<int> arr(n);
    f(i, n) cin >> arr[i];

    // Map to store the previous sums 
    unordered_map<int, int> prevSums; 
  
    int sum = 0; // Initialize the sum of elements 
    int max_len = 0; // Initialize result 
  
    // Traverse through the given array 
    for (int i = 0; i < n; i++) { 
        // Add current element to sum 
        sum += arr[i]; 
  
        if (arr[i] == 0 && max_len == 0) {
            max_len = 1; 
        }
        if (sum == 0) {
            max_len = i + 1; 
        }
  
        // Look for this sum in Hash table 
        if (prevSums.find(sum) != prevSums.end()) { 
            // If this sum is seen before, then update max_len 
            max_len = max(max_len, i - prevSums[sum]); 
        }  else { 
            // Else insert this sum with index in hash table 
            prevSums[sum] = i; 
        } 
    } 
  
    cout << max_len; 
}
