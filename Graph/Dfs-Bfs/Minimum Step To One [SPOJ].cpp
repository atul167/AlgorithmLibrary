// https://www.spoj.com/problems/MST1/

/*
Problem Statement:
Problem statement is very easy . On a positive integer, you can perform any one of the following 3 steps.
1) Subtract 1 from it. ( n = n - 1 ) 
2) If its divisible by 2, divide by 2. ( if n % 2 == 0 , then n = n / 2  )
3) If its divisible by 3, divide by 3. ( if n % 3 == 0 , then n = n / 3  )
Given a positive integer  n and you task is find the minimum number of steps that takes n to 1.

Input:
The input contains an integer T (1 ≤  T ≤  100) number of test cases. Second line input is N (0 < N ≤ 2*107 ) that indicates the positive number.

Output:
For each case, print the case number and minimum steps.

Sample Input
3
1
4
7
Sample Output
Case 1: 0
Case 2: 2
Case 3: 3
*/


const int N = 2e7+5;
int n, m;

void solve(int testcase) {
    cin >> n;
    queue<pair<int, int>> q;
    q.push({n, 0});
 
    // map is used to visit numbers so that they won't be pushed in queue again
    map<int, int> vis;
 
    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        int val = it.first, steps = it.second;
         
        // if current value is 1, return its steps from n
        if (val == 1) {
            cout << "Case " << testcase << ": " << steps << endl;
            return;
        }
 
        //  check val - 1, only if it not visited yet
        if (!vis[val - 1]) {
            q.push({val - 1, steps + 1});
            vis[val - 1] = 1;
        }

        //  check val / 2, only if it not visited yet
        if (val % 2 == 0 && !vis[val / 2]) {
            q.push({val / 2, steps + 1});
            vis[val / 2] = 1;
        }

        //  check val / 3, only if it not visited yet
        if (val % 3 == 0 && !vis[val / 3]) {
            q.push({val / 3, steps + 1});
            vis[val / 3] = 1;
        }
    }
}

signed main() {
    IOS
    clock_t begin = clock();
    PRECISION(10);
    int t = 1;
    cin >> t;
    f(i, t) {
        solve(i+1);
    }
    cerr << "Time elapsed: " << (clock() - begin) * 1000.0 / CLOCKS_PER_SEC << "ms" << '\n';
}

















const int N = 2e7+5;
int n, m;

void solve(int testcase) {
    cin >> n;
    queue<pair<int, int>> q;
    q.push({n, 0});
 
    // set is used to visit numbers so that they won't be pushed in queue again
    set<int> vis;
 
    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        int val = it.first, steps = it.second;
         
        // if current value is 1, return its steps from n
        if (val == 1) {
            cout << "Case " << testcase << ": " << steps << endl;
            return;
        }
 
        //  check val - 1, only if it not visited yet
        if (vis.find(val - 1) == vis.end()) {
            q.push({val - 1, steps + 1});
            vis.insert(val - 1);
        }

        //  check val / 2, only if it not visited yet
        if (val % 2 == 0 && vis.find(val / 2) == vis.end()) {
            q.push({val / 2, steps + 1});
            vis.insert(val / 2);
        }

        //  check val / 3, only if it not visited yet
        if (val % 3 == 0 && vis.find(val / 3) == vis.end()) {
            q.push({val / 3, steps + 1});
            vis.insert(val / 3);
        }
    }
}

signed main() {
    IOS
    clock_t begin = clock();
    PRECISION(10);
    int t = 1;
    cin >> t;
    f(i, t) {
        solve(i+1);
    }
    cerr << "Time elapsed: " << (clock() - begin) * 1000.0 / CLOCKS_PER_SEC << "ms" << '\n';
}
