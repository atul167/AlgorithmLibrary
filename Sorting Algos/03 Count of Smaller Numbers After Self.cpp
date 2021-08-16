// https://leetcode.com/problems/count-of-smaller-numbers-after-self/
// https://www.geeksforgeeks.org/count-of-smaller-elements-on-right-side-of-each-element-in-an-array-using-merge-sort/

/*
You are given an integer array nums and you have to return a new counts array. 
The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Input: nums = [5,2,6,1]
Output: [2,1,1,0]
*/


/*
Approach: 
Use the idea of the merge sort at the time of merging two arrays. 
When higher index element is less than the lower index element, 
it represents that the higher index element is smaller than all the elements after that lower index because the left part is already sorted. 
Hence add up to all the elements after the lower index element for the required count. 
*/

class Solution {
public:
    vector<int> res;
    
    void merge(vector<pair<int, int>>& a, int start, int mid, int end) {
        pair<int, int> temp[end - start + 1];
        int i = start, j = mid + 1, k = 0;
        
        int cnt = 0;
        while (i <= mid && j <= end) {
            if (a[i].first <= a[j].first) {
                res[a[i].second] += cnt;
                temp[k++] = a[i++];
            } else {
                cnt++;
                temp[k++] = a[j++];
            }
        }
        while (i <= mid) {
            res[a[i].second] += cnt;
            temp[k++] = a[i++];
        }
        while (j <= end) {
            temp[k++] = a[j++];
        }

        for (int i = 0; i < k; i++) {
            a[start++] = temp[i];
        }
    }

    void mergesort(vector<pair<int, int>>& a, int l, int r) {
        if (l >= r) return;

        int mid = (l + r) / 2;
        mergesort(a, l, mid);
        mergesort(a, mid + 1, r);
        
        merge(a, l, mid, r);
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> a(n);
        for(int i = 0; i < n; i++) {
            a[i] = {nums[i], i};
        }
        
        res = vector<int>(n, 0);
        mergesort(a, 0, n - 1);
        return res;
    }
};
