#include <stdio.h>
#include <stdlib.h>

// Define the structure for a BST node
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

// Function to insert a value into the BST
TreeNode* insert(TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to find the node with the maximum value in the BST
TreeNode* findMax(TreeNode* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

// Function to delete a node with a given value from the BST
TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        TreeNode* temp = findMax(root->left);
        root->data = temp->data;
        root->left = deleteNode(root->left, temp->data);
    }

    return root;
}

// Function to perform in-order traversal of the BST
void inorderTraversal(TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    TreeNode* root = NULL;
    int choice, num;

    do {
        printf("\n----- Menu -----\n");
        printf("1. Insert into BST\n");
        printf("2. Delete from BST\n");
        printf("3. In-order Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number to insert: ");
                scanf("%d", &num);
                root = insert(root, num);
                break;
            case 2:
                printf("Enter the number to delete: ");
                scanf("%d", &num);
                root = deleteNode(root, num);
                break;
            case 3:
                printf("In-order Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    // Free the allocated memory before exiting
    // (Note: In a real-world scenario, you should free the entire tree)
    return 0;
}