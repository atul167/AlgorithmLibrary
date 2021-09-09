// Print all permutaions of string


// Method 1: My own nextPermutation
bool nextPermutation(string& str) {
    int n = str.size();
    if(n == 0) return false;
    // Find longest non-increasing suffix
    int i = n - 1;
    while (i > 0 && str[i - 1] >= str[i]) {
        i--;
    }
    // Now i is the head index of the suffix
    
    // Are we at the last permutation already?
    if (i == 0)
        return false;
    
    // Let str[i - 1] be the pivot
    // Find rightmost element greater than the pivot
    int j = n - 1;
    while (str[j] <= str[i - 1]) {
        j--;
    }
    // Now the value str[j] will become the new pivot
    // Assertion: j >= i
    
    // Swap the pivot with j
    swap(str[i - 1], str[j]);
    
    // Reverse the suffix
    reverse(str.begin() + i, str.end());
    // Successfully computed the next permutation
    return true;
}

void solve() {
    string s;
    cin >> s;

    // sorting is required
    sort(s.begin(), s.end());
    do {
        cout << s << endl;
    } while (nextPermutation(s));
}





// Method 2: Inbuilt next_permutation
void solve() {
    string s;
    cin >> s;
    // sorting is required
    sort(s.begin(), s.end());
    do {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));
}



















// https://leetcode.com/problems/next-greater-element-iii/
// Next Greater Element III

/*
Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. 
If no such positive integer exists, return -1.
Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.

Example 1:
Input: n = 12
Output: 21

Example 2:
Input: n = 21
Output: -1

Constraints:
1 <= n <= 2^31 - 1


NOTE: stoi  = for int
      stoll = for long long 
*/

// Method 1
class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);
        next_permutation(str.begin(), str.end());
        auto res = stoll(str);
        
        /*
        if n = 554321 (non increasing type)
        in this case next_permutation will return false and not modify str
        and res will be equal to str
        */ 
        return (res > INT_MAX || res <= n) ? -1 : res;
    }
};


// Method 2
class Solution {
public:
    bool nextPermutation(string& str) {
        int n = str.size();
        if(n == 0) return false;
        // Find longest non-increasing suffix
        int i = n - 1;
        while (i > 0 && str[i - 1] >= str[i]) {
            i--;
        }
        // Now i is the head index of the suffix

        // Are we at the last permutation already?
        if (i == 0)
            return false;

        // Let str[i - 1] be the pivot
        // Find rightmost element greater than the pivot
        int j = n - 1;
        while (str[j] <= str[i - 1]) {
            j--;
        }
        // Now the value str[j] will become the new pivot
        // Assertion: j >= i

        // Swap the pivot with j
        swap(str[i - 1], str[j]);

        // Reverse the suffix
        reverse(str.begin() + i, str.end());
        // Successfully computed the next permutation
        return true;
    }
    int nextGreaterElement(int n) {
        string str = to_string(n);
        nextPermutation(str);
        auto res = stoll(str);
        
        /*
        if n = 554321 (non increasing type)
        in this case next_permutation will return false and not modify str
        and res will be equal to str
        */ 
        return (res > INT_MAX || res <= n) ? -1 : res;
    }
};
