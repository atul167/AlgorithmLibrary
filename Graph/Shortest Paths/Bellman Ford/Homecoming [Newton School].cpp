// https://my.newtonschool.co/playground/code/lhy8675e8tpa/

/*
There are n cities in the universe and our beloved Spider-Man is in city 1. 
He doesn't like to travel by vehicles, so he shot webs forming edges between some pairs of cities. 
Eventually, there were m edges and each had some cost associated with it.

Spider-Man now defines the cost of a path p from cities p1 to pk as w1 + 2w2 + 3w3 . . . + (k-1)*wk-1, where wi is the cost of an edge from pi to pi+1.
Thus, the minimum distance between cities i and j is the smallest cost of a path starting from i and ending at j.

Find the minimum distance from city 1 to all the cities i (1 ≤ i ≤ n). If there exists no way to go from city 1 to city i, print -1.

Note:
All the edges are bidirectional. There may be multiple edges and self-loops in the input.
Input
The first line contains two space separated integers n and m - the number of nodes and edges respectively.
The next m lines contain three-space separated integers x, y, w - representing an edge between x and y with cost w.

Constraints:
1 ≤ n ≤ 3000
0 ≤ m ≤ 10000
1 ≤ x, y ≤ n
1 ≤ w ≤ 10^9

Output:
Output n lines. In the ith line, output the minimum distance from city 1 to the ith city. If there exists no such path, output -1.
*/







void solve() {
    int u, v, w;
    cin >> n >> m;
    vector<vector<int>> g;
    f(i, m) {
        cin >> u >> v >> w;
        g.pb({u, v, w});
        g.pb({v, u, w});
    }


    vector<int> dis(n+1, INF);
    dis[1] = 0;
    for(int k = 1; k < n; k++) {
        vector<int> tempDis(dis);
        for(auto x: g) {
            int u = x[0];
            int v = x[1];
            int d = x[2];
            if(dis[u] < INF) {
                tempDis[v] = min(tempDis[v], dis[u] + d * k);
            }
        }
        dis = tempDis;
    }
    loop(i, 1, n) cout << (dis[i] == INF ? -1 : dis[i]) << endl;
}
