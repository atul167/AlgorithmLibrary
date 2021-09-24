// Method 1: Space = O(1)
class Solution {
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        int inc = arr[0];
        int exc = 0;
        
        for(int i = 1; i < n; i++) {
            int newExc = max(inc, exc);
            inc = exc + arr[i];
            exc = newExc;
        }
        
        return max(inc, exc);
    }
};








// Method 2: Space = O(n)
class Solution {
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n) {
        if(n == 1) return arr[0];
    	if(n == 2) return max(arr[0], arr[1]);
    	
    	int dp[n] = {0};
    	dp[0] = arr[0];
    	dp[1] = max(arr[0], arr[1]);
    	
    	for(int i = 2; i < n; i++) {
    		dp[i] = max({dp[i-1], arr[i] + dp[i-2]});
    	}
    
    	return dp[n-1];
    }
};







// Method 2: Space = O(n)
class Solution {
public:
    static const int N = 1e5 + 5;
    int dp[N][2];
    int n;

    int go(int pos, int state, int a[]) {
        if (pos >= n) return 0;

        if (dp[pos][state] != -1) return dp[pos][state];

        int x = 0, y = 0;
        if (state == 0) {
            x = a[pos] + go(pos + 1, 1, a);
        }
        y = go(pos + 1, 0, a);

        return dp[pos][state] = max(x, y);
    }

    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n) {
        this->n = n;
        memset(dp, -1, sizeof dp);
        return go(0, 0, arr);
    }
};













// Time = O(n * k), Space = O(n)
const int N = 1e5 + 5;
int n, m, k;


void solve() {
    cin >> n;
    vector<int> a = vector<int>(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    k = 1;

    if (n <= k) {
        int res = 0;
        for (int i = 1; i <= n; i++) res += a[i];
        cout << res << endl;
        return;
    }

    vector<int> dp(n + 1);
    dp[0] = 0;
    for (int i = 1; i <= k; i++) {
        dp[i] = dp[i - 1] + a[i];
    }

    for (int i = k + 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        int sum = 0;
        for (int j = i; j > i - k; j--) {
            sum += a[j];
            dp[i] = max(dp[i], sum + dp[j - 2]);
        }
    }

    cout << dp[n] << endl;
}
