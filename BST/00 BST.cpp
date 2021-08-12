struct BstNode{
    int data;
    BstNode *left;
    BstNode *right;
};

BstNode* GetNewNode(int data) {
    BstNode *newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void Insert(BstNode*& root, int data) {
    if(root == NULL) {
        root = GetNewNode(data);
    }else if(data <= root->data) {
        Insert(root->left, data);
    }else {
        Insert(root->right,data);
    }
}

bool Search(BstNode* root, int data) {
    if(root == NULL) {
        return false;
    }else if(root->data == data) {
        return true;
    }else if(data <= root->data) {
        return Search(root->left,data);
    }else{
        return Search(root->right,data);
    }
}

int maximum_number(BstNode* root) {
    BstNode *tempRoot = root, *tempRoot_value = NULL;
    while(tempRoot != NULL){
        tempRoot_value = tempRoot;
        tempRoot = tempRoot->right;
    }
    return tempRoot_value->data;
}

int minimum_number(BstNode* root) {
    BstNode *tempRoot = root, *tempRoot_value = NULL;
    while(tempRoot!=NULL){
        tempRoot_value = tempRoot;
        tempRoot = tempRoot->left;
    }
    return tempRoot_value->data;
}

void BFS_traversal(BstNode* root) {
    //check if root is empty or not
    if(root == NULL) return;

    queue<BstNode*> q;
    q.push(root);

    BstNode* tempRoot;

    while(!q.empty()) {
        tempRoot = q.front();
        q.pop();

        cout << tempRoot->data << "\t";
        if(tempRoot->left != NULL) q.push(tempRoot->left);
        if(tempRoot->right != NULL) q.push(tempRoot->right);
    }
    cout << endl;
}

void DFS_traversal_preorder(BstNode* root) {
    //check if root is empty or not
    if(root == NULL) return;

    stack<BstNode*> s;
    s.push(root);

    while(!s.empty()) {
        BstNode *tempRoot = s.top();
        s.pop();
        cout << tempRoot->data << "\t";
        if(tempRoot->right != NULL) s.push(tempRoot->right);
        if(tempRoot->left != NULL) s.push(tempRoot->left);
    }
    cout << endl;
}

void DFS_traversal_inorder(BstNode* root) {
    //check if root is empty or not
    if(root == NULL) return;

    stack<BstNode*> s;
    BstNode* tempRoot = root;

    while(tempRoot != NULL || !s.empty()) {
        while(tempRoot != NULL) {
            s.push(tempRoot);
            tempRoot = tempRoot->left;
        }
        tempRoot = s.top();
        s.pop();
        cout << tempRoot->data << "\t";
        tempRoot = tempRoot->right;
    }
    cout << endl;
}

void DFS_traversal_postorder_using_1Stack(BstNode* root) {
    
}

void DFS_traversal_postorder_using_2Stacks(BstNode* root) {
    stack<BstNode*> s1;
    s1.push(root);

    stack<BstNode*> s2;

    BstNode *tempRoot;

    while(!s1.empty()){
        tempRoot = s1.top();
        s1.pop();
        s2.push(tempRoot);
        if(tempRoot->left!=NULL) s1.push(tempRoot->left);
        if(tempRoot->right!=NULL) s1.push(tempRoot->right);
    }
    while(!s2.empty()){
        tempRoot = s2.top();
        s2.pop();
        cout << tempRoot->data << "\t";
    }
    cout << endl;
}

bool IsBST(BstNode* root) {
    if(root == NULL) return false;

    // 1. do inorder traversal
    vector<int> result;
    stack<BstNode*> s;
    BstNode* tempRoot = root;

    while(tempRoot != NULL || !s.empty()) {
        while(tempRoot != NULL) {
            s.push(tempRoot);
            tempRoot = tempRoot->left;
        }
        tempRoot = s.top();
        s.pop();
        result.pb(tempRoot->data);
        tempRoot = tempRoot->right;
    }

    // 2. if arr is sorted then it is a binary tree  else not 
    for(int i=0; i < result.size() - 1; i++){
        if(result[i] > result[i+1]) return false;
    }
    return true;
}


void solve() {
    ll t, k, d, x, y, z;
    BstNode* root = NULL;
    Insert(root, 15);
    Insert(root, 10);
    Insert(root, 20);
    Insert(root, 25);
    Insert(root, 8);
    Insert(root, 12);

    if(Search(root, 8)) cout << "Found\n";
    else cout << "Not Found\n";

    cout << maximum_number(root) << endl;

    cout << minimum_number(root) << endl;

    BFS_traversal(root);

    DFS_traversal_preorder(root);

    DFS_traversal_inorder(root);

    DFS_traversal_postorder_using_1Stack(root);

    DFS_traversal_postorder_using_2Stacks(root);

    cout << IsBST(root) << endl;
    
}
