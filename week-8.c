Write a C program to implement a Binary tree and perform the following tree traversal operation.
(i)	Inorder Traversal
(ii)	Preorder Traversal
(iii)	Postorder Traversal









Aim:
Performing tree traversal techniques


Algorithm:

1.	Start
2.	Create a tree node
3.	In-order
Traverse the left subtree, visit the root node, and then traverse the right subtree.
4.	Pre-Order Traversal 
Visit the root node, traverse the left subtree, and then traverse the right subtree.
5.	Post-Order Traversal 
     Traverse the left subtree, traverse the right subtree, and then visit the root node.
6.	Than build a tree.
7.	Int main() function perform the tree traversal techniques.
8.	Stop
 
Program:

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}
 

void postorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

struct TreeNode* buildTree() {
    int data;
    struct TreeNode *root = NULL;
    
    printf("Enter data (Enter -1 to stop): ");
    scanf("%d", &data);
    
    if (data == -1) return NULL; 
    root = createNode(data);
    
    printf("Enter left child of %d:\n", data);
    root->left = buildTree();
    
    printf("Enter right child of %d:\n", data);
    root->right = buildTree();
    
    return root;
}

int main() {
    printf("Enter the binary tree (Enter -1 to stop):\n");
    struct TreeNode* root = buildTree();

    printf("\nIn-order traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Pre-order traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Post-order traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}















 
Output:

Enter the binary tree (Enter -1 to stop):
Enter data (Enter -1 to stop): 1
Enter left child of 1:
Enter data (Enter -1 to stop): 2
Enter left child of 2:
Enter data (Enter -1 to stop): 4
Enter left child of 4:
Enter data (Enter -1 to stop): -1
Enter right child of 4:
Enter data (Enter -1 to stop): -1
Enter right child of 2:
Enter data (Enter -1 to stop): 5
Enter left child of 5:
Enter data (Enter -1 to stop): -1
Enter right child of 5:
Enter data (Enter -1 to stop): -1
Enter right child of 1:
Enter data (Enter -1 to stop): 3
Enter left child of 3:
Enter data (Enter -1 to stop): -1
Enter right child of 3:
Enter data (Enter -1 to stop): -1


In-Order Traversal: 4 2 5 1 3 
Pre-Order Traversal: 1 2 4 5 3 
Post-Order Traversal: 4 5 2 3 1




 1 
/ \ 
2     3 
 / \ 
4   5

