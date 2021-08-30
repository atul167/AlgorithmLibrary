// https://www.geeksforgeeks.org/clone-binary-tree-random-pointers/


/*
class TreeNode {
public:
    int val;
    TreeNode *left, *right, *random;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = this->random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> vis;
    
    TreeNode* copyLeftRightNode(TreeNode* root) {
        if(!root) return root;
        
        if(vis[root]) return vis[root];
        
        TreeNode* cloned = new TreeNode(root->val);
        vis[root] = cloned;
        
        if(root->left) {
            cloned->left = copyLeftRightNode(root->left);
        }
        if(root->right) {
            cloned->right = copyLeftRightNode(root->right);
        }
        
        return cloned;
    }

    void copyRandomNode(TreeNode* root, TreeNode* clonedRoot) {
        if(!root) return;
        
        if(root->random) {
            clonedRoot->random =  vis[root->random];
        }
        
        copyRandomNode(root->left, clonedRoot->left);
        copyRandomNode(root->right, clonedRoot->right);
    }

    TreeNode * cloneTree(TreeNode * root) {
        TreeNode* clonedRoot = copyLeftRightNode(root);
        copyRandomNode(root, clonedRoot);
        return clonedRoot;
    }
};
