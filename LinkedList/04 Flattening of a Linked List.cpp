// https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1


/* Node structure  used in the program
struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

// Method 1

Node* mergeTwoLists(Node* l1, Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    if (!l1 && !l2) return NULL;

    if (l1->data > l2->data) std::swap(l1, l2);

    Node *res = l1;

    while (l1 && l2) {
        Node *temp = NULL;
        while (l1 && l1->data <= l2->data) {
            temp = l1;
            l1 = l1->bottom;
        }
        temp->bottom = l2;
        swap(l1, l2);
    }

    return res;
}

// Main function which returns the  root of the flattened linked list.
Node *flatten(Node *root) {
    if (!root || !root->next) return root;

    // recur for list on right
    root->next = flatten(root->next);

    // merge the current node and the right part
    root = mergeTwoLists(root, root->next);

    return root;
}




















// Method 2

Node *mergeTwoLists(Node *a, Node *b) {
    Node *temp = new Node(0);
    Node *res = temp;
    
    while(a && b) {
        if(a->data < b->data) {
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        } else {
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }
    
    if(a) temp->bottom = a;
    else temp->bottom = b;
    
    return res->bottom;
}

// Main function which returns the  root of the flattened linked list.
Node *flatten(Node *root) {
    if(!root || !root->next) return root;
    
    // recur for list on right
    root->next = flatten(root->next);
    
    // merge the current node and the right part
    root = mergeTwoLists(root, root->next);
    
    return root;
}
