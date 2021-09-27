// https://leetcode.com/problems/median-of-two-sorted-arrays/

/*
Given two sorted arrays nums1 and nums2 of size n and m respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log(n + m)).
*/


/*
Using median of row-wise sorted matrix concept.
*/

class Solution {
public:
    int bs(vector<int>& a, vector<int>& b, int target) {
        int n = a.size(), m = b.size();
        int lo = min(a[0], b[0]), hi = max(a[n - 1], b[m - 1]);

        while (lo < hi) {
            int mid = (lo + hi) >> 1;

            int cnt = upper_bound(a.begin(), a.end(), mid) - a.begin();
            cnt += upper_bound(b.begin(), b.end(), mid) - b.begin();

            if (cnt >= target) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if (n == 0 && m == 0) return 0;
        if (m == 0) {
            if (n % 2) {
                return nums1[n / 2];
            } else {
                return (double)(nums1[n / 2 - 1] + nums1[n / 2]) / 2.0;
            }
        }
        if (n == 0) {
            if (m % 2) {
                return nums2[m / 2];
            } else {
                return (double)(nums2[m / 2 - 1] + nums2[m / 2]) / 2.0;
            }
        }

        int target = (n + m + 1) / 2;
        if ((n + m) % 2) {
            return (double)bs(nums1, nums2, target);
        } else {
            double x = (double)bs(nums1, nums2, target);
            double y = (double)bs(nums1, nums2, target + 1);
            return (x + y) / 2.0;
        }
    }
};
