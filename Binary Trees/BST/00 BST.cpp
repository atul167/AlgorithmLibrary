
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v) {
        val = v;
        left = right = NULL;
    }
};

TreeNode* Insert(TreeNode* root, int val) {
    if (root == NULL) {
        root = new TreeNode(val);
    } else if (val <= root->val) {
        root->left = Insert(root->left, val);
    } else {
        root->right = Insert(root->right, val);
    }
    return root;
}

bool Search(TreeNode* root, int val) {
    if (root == NULL) {
        return false;
    } else if (root->val == val) {
        return true;
    } else if (val <= root->val) {
        return Search(root->left, val);
    } else {
        return Search(root->right, val);
    }
}

int maximum_number(TreeNode* root) {
    TreeNode *temp = root, *temp_value = NULL;
    while (temp != NULL) {
        temp_value = temp;
        temp = temp->right;
    }
    return temp_value->val;
}

int minimum_number(TreeNode* root) {
    TreeNode *temp = root, *temp_value = NULL;
    while (temp != NULL) {
        temp_value = temp;
        temp = temp->left;
    }
    return temp_value->val;
}

void BFS_traversal(TreeNode* root) {
    if (root == NULL) return;

    queue<TreeNode*> q;
    q.push(root);

    TreeNode* temp;

    while (!q.empty()) {
        temp = q.front();
        q.pop();

        cout << temp->val << "\t";
        if (temp->left != NULL) q.push(temp->left);
        if (temp->right != NULL) q.push(temp->right);
    }
    cout << endl;
}

void DFS_traversal_preorder(TreeNode* root) {
    if (root == NULL) return;

    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        TreeNode *temp = st.top();
        st.pop();
        cout << temp->val << "\t";
        if (temp->right != NULL) st.push(temp->right);
        if (temp->left != NULL) st.push(temp->left);
    }
    cout << endl;
}

void DFS_traversal_inorder(TreeNode* root) {
    if (root == NULL) return;

    stack<TreeNode*> st;
    TreeNode* temp = root;

    while (temp != NULL || !st.empty()) {
        while (temp != NULL) {
            st.push(temp);
            temp = temp->left;
        }
        temp = st.top();
        st.pop();
        cout << temp->val << "\t";
        temp = temp->right;
    }
    cout << endl;
}

void DFS_traversal_postorder_using_1Stack(TreeNode* root) {
    if(root == NULL) return;

    TreeNode* temp = root, *temp2 = NULL;
    stack<TreeNode*> st;

    while(temp != NULL || !st.empty()) {
        while(temp != NULL) {
            st.push(temp);
            temp = temp->left;
        }
        temp = st.top();
        if(temp->right == NULL || temp->right == temp2){
            cout << temp->val << "\t";
            st.pop();
            temp2 = temp;
            temp = NULL;
        } else {
            temp = temp->right;
        }
    }
    cout << endl;
}

void DFS_traversal_postorder_using_2Stacks(TreeNode* root) {
    stack<TreeNode*> st1, st2;
    st1.push(root);

    TreeNode *temp;

    while (!st1.empty()) {
        temp = st1.top();
        st1.pop();
        st2.push(temp);
        if (temp->left != NULL) st1.push(temp->left);
        if (temp->right != NULL) st1.push(temp->right);
    }
    while (!st2.empty()) {
        temp = st2.top();
        st2.pop();
        cout << temp->val << "\t";
    }
    cout << endl;
}

void preInPostTraversal(TreeNode* root) {
    if(root == NULL) return;

    vector<int> pre, in, post;
    stack<pair<TreeNode*,int>> st; 
    st.push({root, 1}); 

    while(!st.empty()) {
        auto it = st.top(); 
        st.pop(); 

        // this is part of "pre"
        // increment 1 to 2 
        // push the left side of the tree
        if(it.second == 1) {
            pre.push_back(it.first->val); 
            it.second++; 
            st.push(it); 

            if(it.first->left != NULL) {
                st.push({it.first->left, 1}); 
            }
        }

        // this is a part of "in" 
        // increment 2 to 3 
        // push right 
        else if(it.second == 2) {
            in.push_back(it.first->val); 
            it.second++; 
            st.push(it); 

            if(it.first->right != NULL) {
                st.push({it.first->right, 1}); 
            }
        }
        // don't push it back again 
        else {
            post.push_back(it.first->val); 
        }
    } 

    for(int x: pre) cout << x << " ";
    cout << endl;
    for(int x: in) cout << x << " ";
    cout << endl;
    for(int x: post) cout << x << " ";
    cout << endl;
}

bool isValidBST(TreeNode* root, long min, long max) {
    if(!root) return true;
    if(root->val > min && root->val < max) {
         return isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);
    }
    return false;
}

bool isValidBST2(TreeNode* root) {
    if (root == NULL) return false;

    // 1. do inorder traversal
    vector<int> result;
    stack<TreeNode*> s;
    TreeNode* temp = root;

    while (temp != NULL || !s.empty()) {
        while (temp != NULL) {
            s.push(temp);
            temp = temp->left;
        }
        temp = s.top();
        s.pop();
        result.pb(temp->val);
        temp = temp->right;
    }

    // 2. if arr is sorted then it is a binary tree  else not
    for (int i = 0; i < result.size() - 1; i++) {
        if (result[i] > result[i + 1]) return false;
    }
    return true;
}

/*
             7
            / \
           5   8
          / \   \
         4   6   9
*/

void solve() {
    ll t, k, d, x, y, z;
    TreeNode* root = NULL;
    root = Insert(root, 7);
    root = Insert(root, 5);
    root = Insert(root, 4);
    root = Insert(root, 6);
    root = Insert(root, 8);
    root = Insert(root, 9);

    if (Search(root, 8)) cout << "Found\n";
    else cout << "Not Found\n";

    cout << "Max node = " << maximum_number(root) << endl;
    cout << "Min node = " << minimum_number(root) << endl;

    cout << "BFS Traversal:\n";
    BFS_traversal(root);

    cout << "Preorder Traversal:\n";
    DFS_traversal_preorder(root);

    cout << "Inorder Traversal:\n";
    DFS_traversal_inorder(root);

    cout << "Postorder Traversal:\n";
    DFS_traversal_postorder_using_1Stack(root);
    DFS_traversal_postorder_using_2Stacks(root);

    cout << "Pre In Post Traversal:\n";
    preInPostTraversal(root);

    cout << "Is valid BST = " << isValidBST(root, INT_MIN, INT_MAX) << endl;
    cout << "Is valid BST = " << isValidBST2(root) << endl;
}
