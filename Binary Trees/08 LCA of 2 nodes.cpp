// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// https://youtu.be/_-QHfMDde90


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base case
        if (!root || root == p || root == q) {
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (!left) {
            return right;
        }
        if (!right) {
            return left;
        }
        // both left and right are not null, we found our result
        return root;
    }
};
