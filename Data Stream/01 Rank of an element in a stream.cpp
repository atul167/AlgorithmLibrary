// https://www.geeksforgeeks.org/rank-element-stream/

/*
DS design for getRank(x) of elements x in a stream.
Note: Rank is 0 based
*/

/*
Given a stream of integers, lookup the rank of a given integer x. 
Rank of an integer in-stream is “Total number of elements less than or equal to x (not including x)”.
If an element is not found in the stream or is smallest in stream, return -1. 
*/


/*
Method 1: Use BIT if elements range is <= 1e6

Method 2:
A relatively easy way to implement this is to use an array that holds all the elements in sorted order. 
When a new element is inserted we would shift the elements. 
Then we perform binary search on the array to get the right-most index of x and return that index. 
getRank(x) would work in O(log n) but insertion would be costly.

Method 3:
An efficient way is to use a Binary Search Tree. Each Node will hold the data value and size of its left subtree.
We traverse the tree from root and compare the root values to x. 
 

If root->data == x, return size of left subtree of root.
If x < root->data, return getRank(root->left)
If x > root->data, return getRank(root->right) + size of leftSubtree + 1.
*/


#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data, leftSize;
    Node *left, *right;
    Node(int d) {
        data = d;
        leftSize = 0;
        left = right = NULL;
    }
};

Node* insert(Node* root, int data) {
    if (!root)
        return new Node(data);

    if (data <= root->data) {
        root->left = insert(root->left, data);
        // Updating size of left subtree.
        root->leftSize++;
    } else {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to get Rank of a Node x.
int getRank(Node* root, int x) {
    if(!root) return -1;

    if (root->data == x) return root->leftSize;

    if (x < root->data) {
        return getRank(root->left, x);
    } else {
        int rightSize = getRank(root->right, x);
        if(rightSize == -1 ) return -1;
        return (root->leftSize + 1 + rightSize);
    }
}

// Driver code
int main() {
    int arr[] = { 1, 3, 4, 4, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }

    int x = 4;
    cout << "Rank of " << x << " in stream is: " << getRank(root, x) << endl;

    x = 13;
    cout << "Rank of " << x << " in stream is: " << getRank(root, x) << endl;

    x = 13;
    root = insert(root, x);
    cout << "Rank of " << x << " in stream is: " << getRank(root, x) << endl;

    x = 3;
    root = insert(root, x);
    cout << "Rank of " << x << " in stream is: " << getRank(root, x) << endl;

    root = insert(root, 15);
    x = 15;
    cout << "Rank of " << x << " in stream is: " << getRank(root, x) << endl;
}

/*
Rank of 4 in stream is: 4
Rank of 13 in stream is: -1
Rank of 13 in stream is: 6
Rank of 3 in stream is: 2
Rank of 15 in stream is: 8
*/
























#include <bits/stdc++.h>
using namespace std;

class Node {
private:
    int data, leftSize;
    Node *left, *right;
public:
    Node(int d) {
        data = d;
        leftSize = 0;
        left = right = NULL;
    }

    Node* insert(Node* root, int data) {
        if (!root)
            return new Node(data);

        if (data <= root->data) {
            root->left = insert(root->left, data);
            // Updating size of left subtree.
            root->leftSize++;
        } else {
            root->right = insert(root->right, data);
        }

        return root;
    }

    // Function to get Rank of a Node x.
    int getRank(Node* root, int x) {
        if(!root) return -1;

        if (root->data == x) return root->leftSize;

        if (x < root->data) {
            return getRank(root->left, x);
        } else {
            int rightSize = getRank(root->right, x);
            if(rightSize == -1 ) return -1;
            return (root->leftSize + 1 + rightSize);
        }
    }
};

// Driver code
int main() {
    int arr[] = { 1, 3, 4, 4, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        root = root->insert(root, arr[i]);
    }

    int x = 4;
    cout << "Rank of " << x << " in stream is: " << root->getRank(root, x) << endl;

    x = 13;
    cout << "Rank of " << x << " in stream is: " << root->getRank(root, x) << endl;

    x = 13;
    root = root->insert(root, x);
    cout << "Rank of " << x << " in stream is: " << root->getRank(root, x) << endl;

    x = 3;
    root = root->insert(root, x);
    cout << "Rank of " << x << " in stream is: " << root->getRank(root, x) << endl;

    root = root->insert(root, 15);
    x = 15;
    cout << "Rank of " << x << " in stream is: " << root->getRank(root, x) << endl;
}

























#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data, leftSize;
    Node *left, *right;
    Node(int d) {
        data = d;
        leftSize = 0;
        left = right = NULL;
    }
};

void insert(Node*& root, int data) {
    if (!root) {
        root = new Node(data);
        return;
    }

    if (data <= root->data) {
        insert(root->left, data);
        // Updating size of left subtree.
        root->leftSize++;
    } else {
        insert(root->right, data);
    }
}

// Function to get Rank of a Node x.
int getRank(Node* root, int x) {
    if(!root) return -1;

    if (root->data == x) return root->leftSize;

    if (x < root->data) {
        return getRank(root->left, x);
    } else {
        int rightSize = getRank(root->right, x);
        if(rightSize == -1 ) return -1;
        return (root->leftSize + 1 + rightSize);
    }
}

// Driver code
int main() {
    int arr[] = { 1, 3, 4, 4, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        insert(root, arr[i]);
    }

    int x = 4;
    cout << "Rank of " << x << " in stream is: " << getRank(root, x) << endl;

    x = 13;
    cout << "Rank of " << x << " in stream is: " << getRank(root, x) << endl;

    x = 13;
    insert(root, x);
    cout << "Rank of " << x << " in stream is: " << getRank(root, x) << endl;

    x = 3;
    insert(root, x);
    cout << "Rank of " << x << " in stream is: " << getRank(root, x) << endl;

    insert(root, 15);
    x = 15;
    cout << "Rank of " << x << " in stream is: " << getRank(root, x) << endl;
}
