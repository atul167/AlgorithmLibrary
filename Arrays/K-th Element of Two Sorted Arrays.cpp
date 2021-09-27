// https://www.geeksforgeeks.org/k-th-element-two-sorted-arrays/
// https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1
// https://youtu.be/nv7F4PiLUzo


class Solution {
public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k) {
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>> > pq;

        pq.push({ arr1[0], 1, 0 });
        pq.push({ arr2[0], 2, 0 });
        int res;

        while (!pq.empty() && k--) {
            auto cur = pq.top();
            pq.pop();

            res = cur[0];
            // i = arr1 or arr2
            // j = idx in that arr
            int i = cur[1];
            int j = cur[2];

            if (i == 1) {
                if (j + 1 < n) {
                    pq.push({ arr1[j + 1], i, j + 1 });
                }
            }
            if (i == 2) {
                if (j + 1 < m) {
                    pq.push({ arr2[j + 1], i, j + 1 });
                }
            }
        }

        return res;
    }
};








class Solution {
public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k) {
        int lo = min(arr1[0], arr2[0]), hi = max(arr1[n - 1], arr2[m - 1]);

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            int cnt = upper_bound(arr1, arr1 + n, mid) - arr1;
            cnt += upper_bound(arr2, arr2 + m, mid) - arr2;

            if (cnt >= k)
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};
