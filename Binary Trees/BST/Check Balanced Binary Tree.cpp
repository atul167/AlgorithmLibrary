// https://leetcode.com/problems/balanced-binary-tree/

/*
Given a binary tree, determine if it is height-balanced.

To check if a tree is height-balanced, get the height of left and right subtrees of every node. 
Return true if difference between heights is not more than 1 and left and right subtrees are balanced, otherwise return false. 
*/

class Solution {
public:
    bool res;
    
    int check(TreeNode* root) {
        if(!root) return 0;
        
        int l = check(root->left);
        int r = check(root->right);
        
        if(abs(l - r) > 1) res = false;
        
        return 1 + max(l, r);
    }
    
    bool isBalanced(TreeNode* root) {
        res = true;
        check(root);
        return res;
    }
};
