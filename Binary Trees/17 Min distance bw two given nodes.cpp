// https://www.geeksforgeeks.org/find-distance-between-two-nodes-of-a-binary-tree/
// https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1

class Solution {
public:
    unordered_map<Node*, Node*> parent;
    unordered_map<Node*, bool> vis;

    Node *src, *dest;

    void findParent(Node* node, int start, int end) {
        if (!node ) return;

        if (node->data == start) src = node;
        if (node->data == end) dest = node;

        if (node->left) {
            parent[node->left] = node;
            findParent(node->left, start, end);
        }
        if (node->right) {
            parent[node->right] = node;
            findParent(node->right, start, end);
        }
    }

    int bfs() {
        queue<pair<Node*, int>> q;
        q.push({src, 0});
        vis[src] = 1;

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            Node *temp = it.first;
            int dis = it.second;

            if (temp == dest) return dis;

            if (temp->left && !vis[temp->left]) {
                vis[temp->left] = 1;
                q.push({temp->left, dis + 1});
            }
            if (temp->right && !vis[temp->right]) {
                vis[temp->right] = 1;
                q.push({temp->right, dis + 1});
            }

            Node* par = parent[temp];
            if (par && !vis[par]) {
                vis[par] = 1;
                q.push({par, dis + 1});
            }
        }
    }

    int findDist(Node* root, int a, int b) {
        if ( !root ) return 0;
        findParent(root, a, b);
        return bfs();
    }
};
