// https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/

/*
Given the root of a binary tree, return the lowest common ancestor of its deepest leaves.
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
        int lcount = countDepth(root->left);
        int rcount = countDepth(root->right);
        if(lcount == rcount)
            return root;
        else if(lcount < rcount)
            return lcaDeepestLeaves(root->right);
        else
            return lcaDeepestLeaves(root->left);
    }
};
