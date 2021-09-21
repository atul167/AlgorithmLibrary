// https://cses.fi/problemset/task/1673/
// https://youtu.be/WMTIoCkVFw4

/*
Problem:
You play a game consisting of n rooms and m tunnels. 
Your initial score is 0, and each tunnel increases your score by x where x may be both positive or negative. 
You may go through a tunnel several times.
Your task is to walk from room 1 to room n. What is the maximum score you can get?

Input:
The first input line has two integers n and m: the number of rooms and tunnels. The rooms are numbered 1,2,…,n.
Then, there are m lines describing the tunnels. 
Each line has three integers a, b and x: the tunnel starts at room a, ends at room b, and it increases your score by x. 
All tunnels are one-way tunnels.
You can assume that it is possible to get from room 1 to room n.

Output:
Print one integer: the maximum score you can get. However, if you can get an arbitrarily large score, print −1.

Constraints:
1 ≤ 2500 ≤ n
1 ≤ 5000 ≤ m
1 ≤ a, b ≤ n
−10^9 ≤ x ≤ 10^9
*/



/*
Note:
Bellman ford works when there is no negative weight cycle.
But in this problem even if there is a cycle in graph but not a part of path between vertex 1 and n is tolerable.
So we have to vis, revVis, g, revG to handle this case.

Approach:
We will calculate shortest path by negating the weights to find the longest weight path.
But in this problem even if there is a cycle in graph but not a part of path between vertex 1 and n is tolerable.
So we use g and revG.
vis[u] is used to check if there exists path from 1 to u.
revVis[v] is used to check if there exists path from v to n.
This majorly helps in eliminating relaxation of loops which are not part of 1 to n path.
*/

void dfs(int u, vector<int>& vis, vector<vector<int>>& g) {
    vis[u] = 1;
    for(int v: g[u]) {
        if (!vis[v]) {
            dfs(v, vis, g);
        }
    }
} 
 
void solve() {
    int u, v, w;
    cin >> n >> m;
    vector<vector<int>> g(n+1);
    vector<vector<int>> revG(n+1);
    vector<tuple<int, int, int>> edges;
    f(i, m) {
        cin >> u >> v >> w;
        edges.pb({u, v, -w});
        g[u].pb(v);
        revG[v].pb(u);
    }

    vector<int>vis(n+1), revVis(n+1);
    dfs(1, vis, g);
    dfs(n, revVis, revG);

    vector<int> dis(n+1, INF);
    dis[1] = 0;
    bool flag = 0;
    // loop from 1 to n to keep track of negative weight cycle on n'th iteration
    for (int i = 1; i <= n; i++) {
        flag = 0;
        for(auto it: edges) {
            tie(u, v, w) = it;
            // vis[u] and revVis[v] check is used to check if there exists path from 1 to u and from v to n 
            // this majorly helps in eliminating relaxation of loops which are not part of 1 to n path
            if(vis[u] and revVis[v] and dis[v] > dis[u] + w) {
                flag = 1;
                dis[v] = dis[u] + w;
            }
        }
    }

    if(flag) cout << -1 << endl;
    else cout << -dis[n] << endl;
}
