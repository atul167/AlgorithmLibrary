// https://www.geeksforgeeks.org/find-maximum-path-sum-two-leaves-binary-tree/
// https://practice.geeksforgeeks.org/problems/maximum-path-sum/1

/*
Given a binary tree in which each node element contains a number. Find the maximum possible sum from one leaf node to another leaf node.
NOTE: Here Leaf node is a node which is connected to exactly one different node.
*/

// Method 1
class Solution {
public:
    int res;
    
    int maxPathSumUtil(struct Node *root) {
        // Base cases
        if (!root) return 0;
        if (!root->left && !root->right) return root->data;
     
        // Find maximum sum in left and right subtree. 
        // i.e. maximum root to leaf sums in left and right subtrees
        int ls = maxPathSumUtil(root->left);
        int rs = maxPathSumUtil(root->right);
     
     
        // If both left and right children exist
        if (root->left && root->right) {
            // Update result if needed
            res = max(res, ls + rs + root->data);
     
            // Return maximum possible value for root being on one side
            return max(ls, rs) + root->data;
        }
     
        // If any of the two children is empty, return root sum for root being on one side
        if(!root->left) return rs + root->data;
        if(!root->right) return ls + root->data;
    }
    
    int maxPathSum(Node *root) {
        res = INT_MIN;
       
        int val = maxPathSumUtil(root);
               
        //--- for test case ---
        //          7                
        //         /  \              
        //      Null  -3 
        // value of res will be INT_MIN but the answer is 4 , which is returned by the function maxPathSumUtil().
        
        if(res == INT_MIN) {
            return val;
        }
       
        return res;
    }
};


















// Method 2
class Solution {
public:
    int maxPathSumUtil(struct Node *root, int &res) {
        // Base cases
        if (!root) return 0;
        if (!root->left && !root->right) return root->data;
     
        // Find maximum sum in left and right subtree. 
        // i.e. maximum root to leaf sums in left and right subtrees
        int ls = maxPathSumUtil(root->left, res);
        int rs = maxPathSumUtil(root->right, res);
     
     
        // If both left and right children exist
        if (root->left && root->right) {
            // Update result if needed
            res = max(res, ls + rs + root->data);
     
            // Return maximum possible value for root being on one side
            return max(ls, rs) + root->data;
        }
     
        // If any of the two children is empty, return root sum for root being on one side
        if(!root->left) return rs + root->data;
        if(!root->right) return ls + root->data;
    }
    
    int maxPathSum(Node *root) {
        int res = INT_MIN;
       
        int val = maxPathSumUtil(root, res);
               
        //--- for test case ---
        //          7                
        //         /  \              
        //      Null  -3 
        // value of res will be INT_MIN but the answer is 4 , which is returned by the function maxPathSumUtil().
        
        if(res == INT_MIN) {
            return val;
        }
       
        return res;
    }
};
