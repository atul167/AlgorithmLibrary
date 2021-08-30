// https://www.geeksforgeeks.org/longest-increasing-subsequence-using-bit/
// https://leetcode.com/problems/longest-increasing-subsequence/
// https://codeforces.com/problemset/problem/340/D

/*
GFG Approach:  

1) First, use coordinate compression (replace all values of the array to numbers ranging from 1 to N). 
   This will reduce the maximum number in the array and help us solve the above problem in NlogN time. Also, this will help us to reduce memory.
2) Make a new array BIT of length N + 1.
3) Now, traverse the array from left to right and add the current element to the BIT.
4) When ith element (A[i]) is inserted in the BIT, check for the length of the longest subsequence that can be formed till A[i] – 1. 
   Let this value be x. If x + 1 is greater than the current element in BIT, update the BIT.
*/


// https://codeforces.com/problemset/problem/340/D
// O(nlog(n))          [Increasing Subsequence]
const int N = 2e5+5;
int n, m;
int BIT[N];

void update(int i, int val) {
    while(i <= n) {
        BIT[i] = max(BIT[i], val);
        i += (i&-i);
    }
}
int query(int i) {
    int mx = 0;
    while(i > 0) {
        mx = max(mx, BIT[i]);
        i -= (i&-i);
    }
    return mx;
}

void solve() {
    cin >> n;
    vi nums(n);
    f(i, n) cin >> nums[i];
    
    // coordinate compression in sorted order
    vi temp = nums;
    sort(all(temp));
    map<int, int> mp;
    int c = 1;
    f(i, n) {
        if(mp.count(temp[i]) == 0) {
            mp[temp[i]] = c++;
        }
    }

    f(i, n) nums[i] = mp[nums[i]];
    
    int LIS = 0;
    for(int i = 0; i < n; i++) {
        int x = query(nums[i]);
        update(nums[i], x + 1);
        LIS = max(LIS, x + 1);
    }

    cout << LIS;
}
