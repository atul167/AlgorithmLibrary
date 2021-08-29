// https://leetcode.com/discuss/interview-question/353830/google-phone-screen-parallel-job-scheduling

/*
There are N processes with some processes having dependencies on other processes 
(meaning if a process P1 is dependent on process P2, then P1 can only be started after P2 is complete). 
Assume that there won't be a cyclic dependency in the inputs.

Each process has a time duration (in sec) given by Duration array.
Processes can be run in parallel. We need to find the minimum time such that all processes are completed.

TestCase:
There are 4 processes -
A (Duration: 2 sec), B (Duration: 3 sec), C (Duration: 4 sec) and D (Duration: 5 sec)

B is dependent on A
C is dependent on A
D is dependent on B & C

In this case, min time would be 11 sec.
*/



const int N = 3e5+5;
int n, m;

vi g[N];
int indegree[N], taskTime[N];


void kahn() {
    queue<int> q;
    loop(i, 1, n) {
        if(indegree[i] == 0) q.push(i);
    }

    int res = 0;
    while(!q.empty()) {
        int sz = q.size();
        int mxTime = 0;
        f(i, sz) {
            int u = q.front();
            q.pop();
            mxTime = max(mxTime, taskTime[u]);

            for(int v: g[u]) {
                indegree[v]--;
                if(indegree[v] == 0) q.push(v);
            }
        }
        res += mxTime;
    }
    cout << res << endl;
}

void solve() {
    int u, v;
    cin >> n >> m;
    f(i, m) {
        cin >> u >> v;
        g[u].pb(v);
        indegree[v]++;
    }

    loop(i, 1, n) cin >> taskTime[i];
    kahn();
}



/*
Output:
4 4
1 2
1 3
2 4
3 4
2 3 4 5

Output:
11
*/
