// https://leetcode.com/problems/invert-binary-tree/submissions/


class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return root;
        
        swap(root->left, root->right);
        
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
};




class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return root;
        
        invertTree(root->left);
        invertTree(root->right);
        
        swap(root->left, root->right);
        
        return root;
    }
};
