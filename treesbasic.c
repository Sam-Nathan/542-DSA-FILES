#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure for a BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new BST node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// Function to delete a node from the BST
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct Node* temp = root->right;
        while (temp && temp->left != NULL)
            temp = temp->left;

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to print the BST (inorder traversal)
void printBST(struct Node* root, FILE* file) {
    if (root != NULL) {
        printBST(root->left, file);
        fprintf(file, "%d ", root->data);
        printBST(root->right, file);
    }
}

int main() {
    struct Node* root = NULL;
    srand(time(NULL));
for (int i = 0; i < 10; i++) {
        int randomNum = rand() % 100;
        root = insert(root, randomNum);

    }

    // Print the input to a file
    FILE* input_file = fopen("input.txt", "w");
    if (input_file == NULL) {
        printf("Failed to create input file.\n");
        return 1;
    }
    printBST(root, input_file);
    fclose(input_file);


    // Delete a node from the BST
    int nodeToDelete;
    printf("Enter the node you want to delete: ");
    scanf("%d", &nodeToDelete);
    root = deleteNode(root, nodeToDelete);

    // Print the output to a file
    FILE* output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Failed to create output file.\n");
        return 1;
    }
    printBST(root, output_file);
    fclose(output_file);
    printf("Node has been deleted\n");

    return 0;
}
