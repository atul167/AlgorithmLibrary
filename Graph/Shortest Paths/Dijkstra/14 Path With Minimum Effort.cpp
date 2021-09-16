// https://leetcode.com/problems/path-with-minimum-effort/
// https://leetcode.com/problems/path-with-minimum-effort/discuss/909017/JavaPython-Dijikstra-Binary-search-Clean-and-Concise


/*
Note: Open link to see diagrams.

You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, 
where heights[row][col] represents the height of cell (row, col). 
You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1).
You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.
Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

 
Example 1:
Input: heights = [[1,2,2],
                  [3,8,2],
                  [5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.

Example 2:
Input: heights = [[1,2,3],
                  [3,8,4],
                  [5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].

Example 3:
Input: heights = [[1,2,1,1,1],
                  [1,2,1,2,1],
                  [1,2,1,2,1],
                  [1,2,1,2,1],
                  [1,1,1,2,1]]
Output: 0
Explanation: This route does not require any effort.
*/



// Method 1
class Solution {
public:
    #define INF 1e9
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = { -1, 0, 1, 0};
    int n, m;

    bool isSafe(int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= m)
            return false;
        return true;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        n = heights.size(), m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INF));

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        // distance, row, col
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int d = it[0], x = it[1], y = it[2];
            if (d > dist[x][y]) continue;

            // Reach to bottom right
            if (x == n - 1 && y == m - 1) return d;

            for (int z = 0; z < 4; z++) {
                int nx = x + dx[z], ny = y + dy[z];
                if (!isSafe(nx, ny)) continue;

                int newDist = max(d, abs(heights[nx][ny] - heights[x][y]));
                if (dist[nx][ny] > newDist) {
                    dist[nx][ny] = newDist;
                    pq.push({dist[nx][ny], nx, ny});
                }
            }
        }

        // Unreachable code, C++ require to return interger value.
        return 0;
    }
};
