// https://leetcode.com/problems/longest-consecutive-sequence/

/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.

Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Constraints:
0 <= nums.length <= 105
-10^9 <= nums[i] <= 10^9
*/



// O(nlogn)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;
        sort(nums.begin(), nums.end());
        
        int mx = 1, mxSoFar = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i-1] + 1) {
                mxSoFar++;
            } else if(nums[i] == nums[i-1]) {
                // do nothing
            } else {
                mxSoFar = 1;
            }
            mx = max(mx, mxSoFar);
        }
        
        return mx;
    }
};











// O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int max_len = 0;

        for (int x: nums) {
            // check if the current element `x` is a candidate for starting a sequence,
            // i.e., the previous element `x-1` doesn't exist in the set
            if (st.find(x - 1) == st.end()) {
                // stores the length of subsequence, starting with the current element
                int len = 1;

                // check for presence of elements `e+1`, `e+2`, `e+3`, … ,`e+len` in `S`
                while (st.find(x + len) != st.end()) {
                    len++;
                }

                // update result with the length of current consecutive subsequence
                max_len = max(max_len, len);
            }
        }

        // return result
        return max_len;
    }
};













// O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> dp;
        int res = 0;
        for (int x : nums) {
            if (dp[x]) continue;
            dp[x] = dp[x + dp[x + 1]] = dp[x - dp[x - 1]] = dp[x + 1] + dp[x - 1] + 1;
            res = max(res, dp[x]);
        }
        return res;
    }
};



// Explanation of above O(n) soln
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> dp;
        int res = 0;
        for(int x: nums) {

            //it is in the middle of some consecutive sequence OR we can say it is already visited earlier
            //therefore it does not contribute to a longer sequence
            if(dp[x]) continue; 

            //we cannot find adjacent sequences to x, therefore it is a single element sequence by itself
            if(dp.find(x-1) == dp.end() && dp.find(x+1) == dp.end()){ // 
                res = max(res, dp[x] = 1);
                continue;
            }

            //found a sequence at x+1, we can safely extend the length by 1
            if(dp.find(x-1) == dp.end()){ 

                //we want to maintain the TWO boundaries of the sequence
                //the new length of the sequence is the original length m[x+1] incremented by 1
                //left boundary dp[x] = dp[x+1] +1;
                //right boundary dp[x+dp[x+1]] = dp[x+1]+1;
                //why x+dp[x+1]? it is equal to dp[x+1]+(x+1)-1 
                //meaning the old left boundary x+1 plus the old length dp[x+1] minus 1
                //e.g. for sequence 3,4,5,6 dp[3] = 4, and right boundary 6 = 3+dp[3]-1 (here x+1 == 3);
                int r = dp[x] = dp[x+dp[x+1]] = dp[x+1]+1;
                res = max(res, r);
                continue;
            }

            //this is similar to the above case just extend to the right
            if(dp.find(x+1) == dp.end()){
                int r = dp[x] = dp[x-dp[x-1]] = dp[x-1]+1;
                res = max(res,r);
                continue;
            }

            //here, we found both sequences at x+1 and x-1, for reasons we explained,
            //the sequences have no overlap.
            //Now, we just need to add the length of current element x (which is 1) to both left and right boundaries
            //the new length will be :  
            //old length of left sequence (dp[x-1]) + old length of right sequence (dp[x+1]) + 1
            //We also need to mark dp[x] as visited, here we can either mark it with 1 or the new length;
            int r = dp[x] = dp[x-dp[x-1]] = dp[x+dp[x+1]] = 1 + dp[x+1]+ dp[x-1];
            res = max(res,r);
        }
        return res;
    }
};















void solve() {
	cin >> n;
	f(i,n) cin>>a[i];
	map<ll, ll>dp;
	f(i,n){
		dp[a[i]]=max(dp[a[i]], dp[a[i]-1]+1);
	}
	ll mx=0;
	ll ele;
	for(auto it: dp){
		if(it.S>mx){
			mx=it.S;
			ele=it.F;
		}
	}
	cout<<mx<<endl;
	ll pos;
	for(ll i=n-1;i>=0;i--){
		if(a[i]==ele){
			pos=i;
			break;
		}
	}
	ll end=ele-mx+1;
	list<ll> ans;
	for(ll i=pos;i>=0;i--){
		if(ele<end){
			break;
		}
		if(a[i]==ele){
			ans.push_front(i+1);
			ele--;
		}
	}
	for(ll x: ans){
		cout<<x<<" ";
	}
}
