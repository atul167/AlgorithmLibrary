/*
When we delete a node, three possibilities arise:

1) Node to be deleted is the leaf: Simply remove from the tree. 

              50                            50
           /     \         delete(20)      /   \
          30      70       --------->    30     70 
         /  \    /  \                     \    /  \ 
       20   40  60   80                   40  60   80
       
2) Node to be deleted has only one child: Copy the child to the node and delete the child 

              50                            50
           /     \         delete(30)      /   \
          30      70       --------->    40     70 
            \    /  \                          /  \ 
            40  60   80                       60   80
            
3) Node to be deleted has two children: 
Find inorder successor of the node. Copy contents of the inorder successor to the node and delete the inorder successor. 
Note that inorder predecessor can also be used. 

              50                            60
           /     \         delete(50)      /   \
          40      70       --------->    40    70 
                 /  \                            \ 
                60   80                           80
The important thing to note is, inorder successor is needed only when the right child is not empty. 
In this particular case, inorder successor can be obtained by finding the minimum value in the right child of the node.
*/




#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int data;
	TreeNode *left, *right;
	TreeNode(int k) {
		data = k;
		left = right = NULL;
	}
};

void inorder(TreeNode* root) {
	if (!root) return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

TreeNode* insert(TreeNode *root, int data){
    if(!root) {
        root = new TreeNode(data);
        return root;
    }
    if(data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}


TreeNode* minValueNode(TreeNode *root) {
	TreeNode* temp = root;

	while (temp && temp->left) {
		temp = temp->left;
	}

	return temp;
}

/* Given a binary search tree root and a data, 
this function deletes the data and returns the new root */
TreeNode* deleteNode(TreeNode *root, int data) {
	// base case
	if (!root) return root;

	// If the data to be deleted is smaller than the root's data
	if (data < root->data)
		root->left = deleteNode(root->left, data);

	// If the data to be deleted is greater than the root's data
	else if (data > root->data)
		root->right = deleteNode(root->right, data);

	// if data is same as root's data, then this is the node to be deleted
	else {
		// Case 1: node has no child
		if (!root->left and !root->right) {
			delete root;
			return NULL;
		}
		// Case 2: node with only one child
		else if (!root->left) {
			TreeNode* temp = root->right;
			delete root;
			return temp;
		} else if (!root->right) {
			TreeNode* temp = root->left;
			delete root;
			return temp;
		}

		// Case 3: node with two children: 
		// Get the inorder successor (smallest in the right subtree)
		TreeNode* temp = minValueNode(root->right);

		// Copy the inorder successor's content to this node
		root->data = temp->data;

		// Delete the inorder successor
		root->right = deleteNode(root->right, temp->data);
	}

	return root;
}

// Driver Code
int main() {
	/* 
	Let us create following BST
		  50
		 /	\
		30	 70
	   / \   / \
	  20 40 60  80 
	*/
	TreeNode* root = NULL;
	root = insert(root, 50);
	root = insert(root, 30);
	root = insert(root, 20);
	root = insert(root, 40);
	root = insert(root, 70);
	root = insert(root, 60);
	root = insert(root, 80);

	cout << "Inorder traversal:\n";
	inorder(root);
	cout << endl;

	cout << "\nDelete 20\n";
	root = deleteNode(root, 20);
	
	cout << "Inorder traversal:\n";
	inorder(root);
	cout << endl;

	cout << "\nDelete 30\n";
	root = deleteNode(root, 30);
	
	cout << "Inorder traversal:\n";
	inorder(root);
	cout << endl;

	cout << "\nDelete 50\n";
	root = deleteNode(root, 50);

	cout << "Inorder traversal:\n";
	inorder(root);
}

/*
Inorder traversal:
20 30 40 50 60 70 80 

Delete 20
Inorder traversal:
30 40 50 60 70 80 

Delete 30
Inorder traversal:
40 50 60 70 80 

Delete 50
Inorder traversal:
40 60 70 80 
*/
