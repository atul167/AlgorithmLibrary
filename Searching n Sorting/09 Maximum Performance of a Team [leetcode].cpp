// https://leetcode.com/problems/maximum-performance-of-a-team/

/*
You are given two integers n and k and two integer arrays speed and efficiency both of length n. 
There are n engineers numbered from 1 to n. speed[i] and efficiency[i] represent the speed and efficiency of the ith engineer respectively.

Choose at most k different engineers out of the n engineers to form a team with the maximum performance.
The performance of a team is the sum of their engineers' speeds multiplied by the minimum efficiency among their engineers.

Return the maximum performance of this team. Since the answer can be a huge number, return it modulo 109 + 7.

 

Example 1:

Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 2
Output: 60
Explanation: 
We have the maximum performance of the team by selecting engineer 2 (with speed=10 and efficiency=4) and engineer 5 (with speed=5 and efficiency=7). That is, performance = (10 + 5) * min(4, 7) = 60.

Example 2:

Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 3
Output: 68
Explanation:
This is the same example as the first but k = 3. We can select engineer 1, engineer 2 and engineer 5 to get the maximum performance of the team. That is, performance = (2 + 10 + 5) * min(5, 4, 7) = 68.

Example 3:

Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 4
Output: 72
*/




/*
It is tough to maintain both sum of speed and minimum of efficiency and to find optimal answer
In this type of questions we have to fix a parameter, here we can fix minimum efficiency
If we sort {efficiency,speed} in decreasing efficiency, we know for ith efficiency, since everything from 1 to i-1
is more than it, ith is the minimum. So from 1 to i-1 if we have the sum of best k-1 speeds we can team them
with ith and we do this for every i and keep taking its maximum.
Note that to find topk sum we can use a heap and maintain its size as less than equal to k and also
keep track of sum of the elements present in heap
*/


class Solution {
public:
    #define ll long long
    #define MOD 1000000007
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<ll, ll>> a;
        for(ll i = 0; i < n; i++) {
            a.push_back({efficiency[i], speed[i]});
        }
        
        // sort in desc order on basis of efficiency
        sort(a.rbegin(), a.rend());
        
        // stores sum of k maximum speeds upto current index whose minimum efficiency is current element
        // we can use minHeap as well
        multiset<int> st;
        
        ll res = 0, speedSum = 0;
        
        for(ll i = 0; i < n; i++) {
            ll minEff = a[i].first, spd = a[i].second;
            speedSum += spd;
            res = max(res, speedSum * minEff);
            
            st.insert(spd);
            // track sum of (k-1) maximum speeds
            if(st.size() >= k) {
                speedSum -= (*st.begin());
                st.erase(st.begin());
            }
        }
        return (int)(res % MOD);
    }
};
