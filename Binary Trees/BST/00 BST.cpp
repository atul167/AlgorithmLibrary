/*
             7
            / \
           5   8
          / \   \
         4   6   9
*/

struct BstNode {
    int data;
    BstNode *left;
    BstNode *right;
    BstNode(int d) {
        data = d;
        left = right = NULL;
    }
};

BstNode* Insert(BstNode* root, int data) {
    if (root == NULL) {
        root = new BstNode(data);
    } else if (data <= root->data) {
        root->left = Insert(root->left, data);
    } else {
        root->right = Insert(root->right, data);
    }
    return root;
}

bool Search(BstNode* root, int data) {
    if (root == NULL) {
        return false;
    } else if (root->data == data) {
        return true;
    } else if (data <= root->data) {
        return Search(root->left, data);
    } else {
        return Search(root->right, data);
    }
}

int maximum_number(BstNode* root) {
    BstNode *temp = root, *temp_value = NULL;
    while (temp != NULL) {
        temp_value = temp;
        temp = temp->right;
    }
    return temp_value->data;
}

int minimum_number(BstNode* root) {
    BstNode *temp = root, *temp_value = NULL;
    while (temp != NULL) {
        temp_value = temp;
        temp = temp->left;
    }
    return temp_value->data;
}

void BFS_traversal(BstNode* root) {
    if (root == NULL) return;

    queue<BstNode*> q;
    q.push(root);

    BstNode* temp;

    while (!q.empty()) {
        temp = q.front();
        q.pop();

        cout << temp->data << "\t";
        if (temp->left != NULL) q.push(temp->left);
        if (temp->right != NULL) q.push(temp->right);
    }
    cout << endl;
}

void DFS_traversal_preorder(BstNode* root) {
    if (root == NULL) return;

    stack<BstNode*> st;
    st.push(root);

    while (!st.empty()) {
        BstNode *temp = st.top();
        st.pop();
        cout << temp->data << "\t";
        if (temp->right != NULL) st.push(temp->right);
        if (temp->left != NULL) st.push(temp->left);
    }
    cout << endl;
}

void DFS_traversal_inorder(BstNode* root) {
    if (root == NULL) return;

    stack<BstNode*> st;
    BstNode* temp = root;

    while (temp != NULL || !st.empty()) {
        while (temp != NULL) {
            st.push(temp);
            temp = temp->left;
        }
        temp = st.top();
        st.pop();
        cout << temp->data << "\t";
        temp = temp->right;
    }
    cout << endl;
}

void DFS_traversal_postorder_using_1Stack(BstNode* root) {
    if(root == NULL) return;

    BstNode* temp = root, *temp2 = NULL;
    stack<BstNode*> st;

    while(temp != NULL || !st.empty()) {
        while(temp != NULL) {
            st.push(temp);
            temp = temp->left;
        }
        temp = st.top();
        if(temp->right == NULL || temp->right == temp2){
            cout << temp->data << "\t";
            st.pop();
            temp2 = temp;
            temp = NULL;
        } else {
            temp = temp->right;
        }
    }
    cout << endl;
}

void DFS_traversal_postorder_using_2Stacks(BstNode* root) {
    stack<BstNode*> st1, st2;
    st1.push(root);

    BstNode *temp;

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
        cout << temp->data << "\t";
    }
    cout << endl;
}

bool isValidBST(BstNode* root, long min, long max) {
    if(!root) return true;
    if(root->data > min && root->data < max) {
         return isValidBST(root->left, min, root->data) && isValidBST(root->right, root->data, max);
    }
    return false;
}

bool isValidBST2(BstNode* root) {
    if (root == NULL) return false;

    // 1. do inorder traversal
    vector<int> result;
    stack<BstNode*> s;
    BstNode* temp = root;

    while (temp != NULL || !s.empty()) {
        while (temp != NULL) {
            s.push(temp);
            temp = temp->left;
        }
        temp = s.top();
        s.pop();
        result.pb(temp->data);
        temp = temp->right;
    }

    // 2. if arr is sorted then it is a binary tree  else not
    for (int i = 0; i < result.size() - 1; i++) {
        if (result[i] > result[i + 1]) return false;
    }
    return true;
}

void solve() {
    ll t, k, d, x, y, z;
    BstNode* root = NULL;
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

    cout << "Is valid BST = " << isValidBST(root, INT_MIN, INT_MAX) << endl;
    cout << "Is valid BST = " << isValidBST2(root) << endl;
}
