/*
There is a corridor in a Jail which is N units long. Given an array A of size N. 
The ith index of this array is 0 if the light at ith position is faulty otherwise it is 1.
All the lights are of specific power B which if is placed at position X, it can light the corridor from [ X-B+1, X+B-1].
Initially all lights are off.
Return the minimum number of lights to be turned ON to light the whole corridor or -1 if the whole corridor cannot be lighted.

Problem Constraints
1 <= N <= 1000
1 <= B <= 1000

Input Format:
First argument is an integer array A where A[i] is either 0 or 1.
Second argument is an integer B.

Output Format:
Return the minimum number of lights to be turned ON to light the whole corridor or -1 if the whole corridor cannot be lighted.

Input 1:
A = [ 0, 0, 1, 1, 1, 0, 0, 1].
B = 3
Outout 1:
2

Input 2:
A = [ 0, 0, 0, 1, 0].
B = 3
Outout 2:
-1
*/


// Method 1
int Solution::solve(vector<int>& A, int B) {
    int n = A.size();
    int i = 0, res = 0;
    
    while(i < n) {
        bool flag = false;
        int a = max(0, i - B + 1);
        int b = min(n - 1, i + B - 1);
        for(int j = b; j >= a; j--) {
            if(A[j] == 1) {
                res++;
                flag = true;
                i = j + B;
                break;
            }
        }
        if(flag == false) return -1;
    }
    return res;
}








// Method 2: Street bulb lighting concept
int Solution::solve(vector<int>& A, int B) {
    int n = A.size();
    vector<pair<int,int>> range;
    for(int i = 0; i < n; i++) {
        if(A[i] == 1) {
            range.push_back({i - (B - 1), i + (B - 1)});
        }
    }
    
    sort(range.begin(), range.end());
    int m = range.size();
    
    int i = 0, target = 0, res = 0;
    while(target <= n-1) {
        if(i == m || range[i].first > target) {
            return -1;
        }
        
        int max_range = range[i].second;
        while( i < m && range[i].first <= target ) {
            max_range = max(max_range,  range[i].second);
            i++;
        }

        if(max_range < target) {
            return -1;
        }
        
        res++;
        target = max_range + 1;
    }
    
    return res;
}
