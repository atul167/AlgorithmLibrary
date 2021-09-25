// https://leetcode.com/problems/majority-element/
// https://www.techiedelight.com/find-majority-element-in-an-array-boyer-moore-majority-vote-algorithm/
// https://www.geeksforgeeks.org/majority-element/


/*
Given an integer array containing duplicates, return the majority element if present. 
A majority element appears more than ⌊n / 2⌋ times (rounded down), where n is the array size.
*/



// Time = O(n), Space = O(n)
#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {2, 2, 2, 2, 5, 5, 2, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[arr[i]]++;
        if (mp[arr[i]] > n / 2) {
            cout << "Majority found :- " << arr[i] << endl;
            return 0;
        }
    }
    cout << "No Majority element" << endl;

    return 0;
}





// Assumption: Frequency of majority element > n / 2
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n / 2];
    }
};




// Boyer–Moore majority vote algorithm
// Assumption: Frequency of majority element > n / 2
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority, count = 0;
        for (int x : nums) {
            if (count == 0) {
                majority = x;
            }

            if (majority == x) count++;
            else count--;
        }
        return majority;
    }
};
