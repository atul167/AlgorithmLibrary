// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
// https://www.geeksforgeeks.org/print-nodes-distance-k-given-node-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> res;
    
    void kdistanceNodeDown(TreeNode *root, int k) {
        if (!root || k < 0)  return;

        if (k == 0) {
            res.push_back(root->val);
            return;
        }

        kdistanceNodeDown(root->left, k-1);
        kdistanceNodeDown(root->right, k-1);
    }

    // Prints all nodes at distance k from a given target node.
    // The k distant nodes may be upward or downward.  This function
    // Returns distance of root from target node, it returns -1 if target
    // node is not present in tree rooted with root.
    int kdistanceNode(TreeNode* root, TreeNode* target , int k) {
        // Base Case 1: If tree is empty, return -1
        if (!root) return -1;

        // If target is same as root.  Use the downward function
        // to print all nodes at distance k in subtree rooted with
        // target or root
        if (root == target) {
            kdistanceNodeDown(root, k);
            return 0;
        }

        // Recur for left subtree
        int dl = kdistanceNode(root->left, target, k);

        // Check if target node was found in left subtree
        if (dl != -1) {
             // If root is at distance k from target, print root
             // Note that dl is Distance of root's left child from target
             if (dl + 1 == k)
                res.push_back(root->val);

             // Else go to right subtree and print all k-dl-2 distant nodes
             // Note that the right child is 2 edges away from left child
             else
                kdistanceNodeDown(root->right, k-dl-2);

             // Add 1 to the distance and return value for parent calls
             return 1 + dl;
        }

        // MIRROR OF ABOVE CODE FOR RIGHT SUBTREE
        // Note that we reach here only when node was not found in left subtree
        int dr = kdistanceNode(root->right, target, k);
        if (dr != -1) {
             if (dr + 1 == k)
                res.push_back(root->val);
             else
                kdistanceNodeDown(root->left, k-dr-2);
             return 1 + dr;
        }

        // If target was neither present in left nor in right subtree
        return -1;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        res.clear();
        kdistanceNode(root, target, k);
        return res;
    }
};
