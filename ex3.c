#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function to create a new node
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to check if a key exists in the binary tree
int isKeyPresent(TreeNode* root, int key) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == key) {
        return 1;
    }
    return isKeyPresent(root->left, key) || isKeyPresent(root->right, key);
}

// Function to print ancestors of a key in a binary tree
int printAncestors(TreeNode* root, int key) {
    // Base case: if the tree is empty or the key is not present
    if (root == NULL || !isKeyPresent(root, key)) {
        return 0;
    }

    // If the key is found, return 1 to indicate that the key is present
    if (root->data == key) {
        return 1;
    }

    // If the key is present in the left subtree
    if (printAncestors(root->left, key) || printAncestors(root->right, key)) {
        // Print the current ancestor
        printf("%d ", root->data);
        return 1;
    }

    // If the key is not present in the current subtree
    return 0;
}

int main() {
    // Example binary tree
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    int key;

    printf("Enter the key: ");
    scanf("%d", &key);

    if (printAncestors(root, key)) {
        printf("\nThe ancestors of %d are: ", key);
    } else {
        printf("\nThe key %d is not present in the tree.\n", key);
    }

    return 0;
}