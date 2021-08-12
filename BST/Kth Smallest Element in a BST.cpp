// iterative

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode *cur = root;
        while(cur || !st.empty()) {
            while(cur) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top(); st.pop();
            k--;
            if(k == 0) {
                return cur->val;
            }
            cur = cur->right;
        }
        return -1;
    }
};








class Solution {
public:
    int res, cnt;
    
    void find(TreeNode* node) {
        if(!node) return;
        
        find(node->left);
        
        cnt--;
        if(cnt == 0) {
            res = node->val;
            return;
        }
        
        find(node->right);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        cnt = k;
        find(root);
        return res;
    }
};








class Solution {
public:
    int res = 0;
    
    void find(TreeNode* node, int& k) {
        if(!node) return;
        
        find(node->left, k);
        
        k--;
        if(k == 0) {
            res = node->val;
            return;
        }
        
        find(node->right, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        find(root, k);
        return res;
    }
};
