// https://leetcode.com/problems/cheapest-flights-within-k-stops/

/*
There are n cities connected by some number of flights. 
You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.
You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. 
If there is no such route, return -1.
*/

/*
https://leetcode.com/problems/cheapest-flights-within-k-stops/discuss/662812/C%2B%2B-BFS-or-Bellman-Ford-Algo-or-Dijkstra-Algo

In bellman ford there are possibities of getting our answer for node X distance away before Xth iteration.
That is why temp is used to eliminate the possibility of getting our ans for node X distance away before Xth iteration.
That means at Kth iteration only node K distance away can fill.

tempDis will store the changes made in dis vector, cause we don't want to use the immediate changes in the dist
Lets take second example:
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
if we don't use tmp vector than
[0, 1, 100] will update dist of dist[1] = 100
[1, 2, 100] will update dist[2] as 200 but (this is wrong cause we can use at most k i.e 0 here stops but here 0->1->2 will be 1 stops)
*/


// Method 1: Bellman Ford
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<int> dis(n, 1e9);
        dis[src] = 0;
        // Run only K+1 times since we want shortest distance in K hops
        for(int i = 0; i <= K; i++) {
            vector<int> tempDis(dis);
            for(auto x: flights) {
                int u = x[0];
                int v = x[1];
                int d = x[2];
                tempDis[v] = min(tempDis[v], dis[u] + d);
            }
            dis = tempDis;
        }
        return dis[dst] == 1e9 ? -1 : dis[dst];
    }
};











// Method 2: TLE
class Solution {
public:
    static const int N = 1e2+5;
    int n;
    vector<int> g[N];
    int vis[N];
    map<pair<int, int>, int> costs;
    int fareCost = 1e9;
    
    void dfs(int u, int dst, int k, int cost) {
        if(u == dst) {
            fareCost = min(fareCost, cost);
            return;
        }
        
        if(k == 0) return;
        
        vis[u] = 1;
        
        for(int v: g[u]) {
            if(!vis[v] && cost + costs[{u, v}] < fareCost) {
                dfs(v, dst, k - 1, cost + costs[{u, v}]);
            }
        }
        // backtrack
        vis[u] = 0;
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        n = flights.size();
        
        for(vector<int> i: flights) {
            g[i[0]].push_back(i[1]);
            costs[{i[0], i[1]}] = i[2];
        }
        dfs(src, dst, K+1, 0);
        
        if(fareCost == 1e9) return -1;
        return fareCost;
    }
};




// Method 3: TLE
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<pair<int, int>> g[n+1];
        for(auto it: flights) {
            g[it[0]].push_back({it[1], it[2]});
        }
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, K+1}); // cost, vertex, hops
        
        while(!pq.empty() ) {
            auto it = pq.top(); 
            pq.pop();
            int cost = it[0];
            int u = it[1];
            int stops = it[2];
            
            if(u == dst) return cost;
            if(stops == 0)  continue;

            for(auto [v, w]: g[u]) {
                pq.push({cost + w, v, stops - 1});
            }
        }
        return -1;
    }
};
