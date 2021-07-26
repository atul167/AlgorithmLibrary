// https://cses.fi/problemset/task/1202/
// https://usaco.guide/problems/cses-1202-investigation/solution

/*
You are going to travel from city 1 to city n by plane. You would like to find answers to the following questions:
a) what is the minimum price of such a route?
b) how many minimum-price routes are there? (modulo 10^9+7)
c) what is the minimum number of flights in a minimum-price route?
d) what is the maximum number of flights in a minimum-price route?

Input:
The first input line contains two integers n and m: the number of cities and the number of flights. The cities are numbered 1,2,…,n. 
After this, there are m lines describing the flights. 
Each line has three integers a, b, and c: there is a flight from city a to city b with price c. 
All flights are one-way flights.
You may assume that there is a route from city 1 to city n.

Output:
Print four integers according to the problem statement.
*/


/*
Time Complexity: 0(E log V) 

We can run dijkstra keeping track of the ->
distance: dis[], 
number of ways with the minimum distance: numOfWays[] 
minimum no of flights with the minimum distance: minFlights[]
maximum no of flights with the minimum distance: maxFlights[]

For every node u, we take into consideration all of its neighbors v. 
If we can reach v in a shorter distance than its current minimum, we update the dis[v] and reset numOfWays[v], minFlights[v], and maxFlights[v]. 
We also have to take into consideration if we can reach v in an equivalent distance. 
If so, we update: 
numOfWays[v] = numOfWays[v] + numOfWays[u]
minFlights[v] = min(minFlights[v], minFlights[u] + 1)
maxFlights[v] = max(maxFlights[v], maxFlights[u] + 1)
*/


// Method 1 (vis array is not required in method 2 [using set])
const int N = 2e5+5;
int n, m;

vector<pair<int, int>> g[N];
int dis[N]; 
int numOfWays[N];
int minFlights[N];
int maxFlights[N];
bool vis[N];

void djikstra(int src) {
    loop(i, 1, n) {
        dis[i] = INF;
        numOfWays[i] = 0;
        minFlights[i] = 0;
        maxFlights[i] = 0;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    pq.push({0, src});
    numOfWays[src] = 1; dis[src] = 0;

    while(!pq.empty()) {
        auto it = pq.top();
        pq.pop();

        int u = it.second;

        if(!vis[u]) {
            vis[u] = true;
            for(auto it: g[u]) {
                int v = it.first, w = it.second;
                if(dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    pq.push({dis[v], v});
                    numOfWays[v] = numOfWays[u];
                    minFlights[v] = minFlights[u] + 1;
                    maxFlights[v] = maxFlights[u] + 1;
                }
                else if(dis[u] + w == dis[v]) {
                    pq.push({dis[v], v});
                    numOfWays[v] = (numOfWays[v] + numOfWays[u]) % MOD;
                    minFlights[v] = min(minFlights[v], minFlights[u] + 1);
                    maxFlights[v] = max(maxFlights[v], maxFlights[u] + 1);
                }
            }
        }
    }
}

void solve() {
    int u, v, w;
    cin >> n >> m;
    f(i, m) {
        cin >> u >> v >> w;
        g[u].pb({v, w});
    }

    djikstra(1);
    cout << dis[n] << " " << numOfWays[n] << " " << minFlights[n] << " " << maxFlights[n] << endl;
}

























// Method 2
const int N = 2e5+5;
int n, m;

vector<pair<int, int>> g[N];
int dis[N]; 
int numOfWays[N];
int minFlights[N];
int maxFlights[N];

void djikstra(int src) {
    loop(i, 1, n) {
        dis[i] = INF;
        numOfWays[i] = 0;
        minFlights[i] = 0;
        maxFlights[i] = 0;
    }

    set<pair<int, int>> st;
    
    st.insert({0, src});
    numOfWays[src] = 1; dis[src] = 0;

    while(!st.empty()) {
        auto it = *st.begin();
        st.erase(it);

        int u = it.second;

        for(auto it: g[u]) {
            int v = it.first, w = it.second;
            if(dis[v] > dis[u] + w) {
                st.erase({dis[v], v});
                dis[v] = dis[u] + w;
                st.insert({dis[v], v});
                numOfWays[v] = numOfWays[u];
                minFlights[v] = minFlights[u] + 1;
                maxFlights[v] = maxFlights[u] + 1;
            }
            else if(dis[u] + w == dis[v]) {
                st.erase({dis[v], v});
                st.insert({dis[v], v});
                numOfWays[v] = (numOfWays[v] + numOfWays[u]) % MOD;
                minFlights[v] = min(minFlights[v], minFlights[u] + 1);
                maxFlights[v] = max(maxFlights[v], maxFlights[u] + 1);
            }
        }
    }
}

void solve() {
    int u, v, w;
    cin >> n >> m;
    f(i, m) {
        cin >> u >> v >> w;
        g[u].pb({v, w});
    }

    djikstra(1);
    cout << dis[n] << " " << numOfWays[n] << " " << minFlights[n] << " " << maxFlights[n] << endl;
}
