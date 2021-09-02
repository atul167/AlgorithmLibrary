/* 
Key Idea: 
dp[i] is the length of the longest subsequence that ends at the i'th element
i.e. dp[i] is storing the value of LIS including nums[i] as the last element of the LIS array.
*/

// O(n.log(n))
// https://youtu.be/66w10xKzbRM


// O(n^2)
class Solution {
public:
    vector<int> LIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        
        if(n==0)
            return ans;
        
        int mx = 1;
        vector<int> dp(n+1, 1);
        
        for(int i=1; i < n; ++i) {
            for(int j=0; j < i; ++j) {
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            mx = max(mx, dp[i]);
        }
        
        //Now push the answer LIS
        int prev = -1;
        for(int i = n-1; i >= 0; i--) {
            if(dp[i] == mx &&  (prev > nums[i] || prev==-1)) {
                ans.push_back(nums[i]);
                mx -= 1;
                prev = nums[i];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


// O(nlog(n))          [Increasing Subsequence]
class Solution {
public:
    int lower_bound(vector<int>& a, int x) {
        int n = a.size();
        int lo = 0, hi = n;
        while(lo < hi) {
            int mid = (lo + hi) / 2;
            if(a[mid] >= x) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        
        vector<int> seq;
        seq.push_back(nums[0]);
        
        for(int i = 1; i < n; i++) {
            if(nums[i] > seq.back()) {
                seq.push_back(nums[i]);
            } else {
                // int idx = lower_bound(seq.begin(), seq.end(), nums[i]) - seq.begin();
                int idx = lower_bound(seq, nums[i]);
                seq[idx] = nums[i];
            }
        }
        
        return seq.size();
    }
};



// O(nlog(n))          [Non decreasing Subsequence]
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        
        vector<int> seq;
        seq.push_back(nums[0]);
        
        for(int i = 1; i < n; i++) {
            if(nums[i] >= seq.back()) {
                seq.push_back(nums[i]);
            } else {
                int idx = upper_bound(seq.begin(), seq.end(), nums[i]) - seq.begin();
                seq[idx] = nums[i];
            }
        }
        
        return seq.size();
    }
};




// Using BIT 
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
