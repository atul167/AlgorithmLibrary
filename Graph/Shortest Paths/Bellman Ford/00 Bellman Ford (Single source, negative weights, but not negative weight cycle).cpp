/*
It's a dynamic programming solution.

Inference:
a) Given the premise that, the longest path in any single source shortest path is |V| - 1 edges long.
b) If we perform |V| - 1 propagations along all E edges, propagation is complete. We have SSSPs.
c) Exceptions exists (Negative weight cycle).
*/

/*
Single source shortest path (includes negative edges)
This is directed version
For questions related to visiting atleast K edges only consider relaxation from 0 to K only instead of (n-1)  

Drawback: If there is a cycle with negative weight, it fails
It will work fine for cycles of positive weight
Therefore after relaxing >= n times, then also path weights are changing that means there is a negative weight cycle in the graph

https://leetcode.com/problems/cheapest-flights-within-k-stops/
*/




/*
Note: 
g.pb({u, v, w});
// ignore below line if directed graph
g.pb({v, u, w});
*/

void solve() {
    int u, v, w;
    cin >> n >> m;
    vector<vector<int>> g;
    f(i, m) {
        cin >> u >> v >> w;
        g.pb({u, v, w});
        // ignore below line if directed graph
        g.pb({v, u, w});
    }


    vector<int> dis(n+1, INF);
    dis[1] = 0;
    for(int i = 1; i < n; i++) {
        for(auto x: g) {
            int u = x[0];
            int v = x[1];
            int d = x[2];
            if(dis[u] < INF) {
                dis[v] = min(dis[v], dis[u] + d);
            }
        }
    }
    loop(i, 1, n) cout << (dis[i] == INF ? -1 : dis[i]) << endl;
}













class Solution {
public:
    vector <int> bellmanFord(int n, vector <vector<int>> edges) {
        vector <int> dis(n, INT_MAX);
        int src = 0;
        dis[src] = 0;
        for (int i = 1; i <= n - 1; i++) {
            for (auto x: edges) {
                int u = x[0];
                int v = x[1];
                int d = x[2];
                if (dis[u] < INT_MAX) {
                    dis[v] = min(dis[v], dis[u] + d);
                }
            }
        }
        return dis;
    }
};


class Solution {
public:
    vector <int> bellmanFord(int n, vector <vector<int>> edges) {
        vector <int> dis(n, INT_MAX);
        int src = 0;
        dis[src] = 0;
        for (int i = 1; i <= n - 1; i++) {
            vector < int > tempDis(dis);
            for (auto x: edges) {
                int u = x[0];
                int v = x[1];
                int d = x[2];
                if (dis[u] < INT_MAX) {
                    tempDis[v] = min(tempDis[v], dis[u] + d);
                }
            }
            dis = tempDis;
        }
        return dis;
    }
};








// https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/0/
class Solution {
public:
    /*  Function to implement Dijkstra
     *   adj: vector of vectors which represents the graph
     *   S: source vertex to start traversing graph with
     *   V: number of vertices
     */
    #define INF 100000000
    vector < int > bellman_ford(int V, vector < vector < int >> adj, int S) {
        vector < int > dis(V, INF);
        dis[S] = 0;

        for (int i = 0; i < V - 1; i++) {
            bool notUpdate = true;
            for (auto edge: adj) {
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                if (dis[u] < INF && dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    notUpdate = false;
                }
            }

            if (notUpdate) {
                break;
            }
        }

        return dis;
    }
};




class Solution{
	public:
	/*  Function to implement Dijkstra
    *   adj: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    #define INF 100000000
    vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        vector<int> dis(V, INF);
        dis[S] = 0;
        
        for(int i = 0; i < V-1; i++) {
            bool notUpdate = true;
            vector < int > tempDis(dis);
            for (auto edge : adj) {
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                if(dis[u] < INF && tempDis[v] > dis[u] + w) {
                    tempDis[v] = dis[u] + w;
                    notUpdate = false; 
                }
            }
            dis = tempDis;
            
            if(notUpdate) {
                break;
            }
        }
        
        return dis;
    }
};
