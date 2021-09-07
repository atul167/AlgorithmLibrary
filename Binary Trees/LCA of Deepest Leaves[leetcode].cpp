// https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/

/*
Given the root of a binary tree, return the lowest common ancestor of its deepest leaves.
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, int> depth;
    
    int countDepth(TreeNode* root){
        if(!root) return 0;
        
        if(depth.count(root)) depth[root];
        
        return depth[root] = 1 + max(countDepth(root->left), countDepth(root->right));
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root) return NULL;
        
        int ldepth = countDepth(root->left);
        int rdepth = countDepth(root->right);
        
        if(ldepth == rdepth) return root;
        
        if(ldepth < rdepth)
            return lcaDeepestLeaves(root->right);
        else
            return lcaDeepestLeaves(root->left);
    }
};
