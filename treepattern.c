#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the binary tree
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data <= root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to write the tree structure in a pattern to a file
void writeTreeToFile(struct Node* root, FILE* file, int space) {
    if (root == NULL) {
        return;
    }

    space += 5;

    // Write right child first
    writeTreeToFile(root->right, file, space);

    // Print current node with indentation
    fprintf(file, "\n");
    for (int i = 5; i < space; i++) {
        fprintf(file, " ");
    }
    fprintf(file, "%d\n", root->data);

    // Write left child
    writeTreeToFile(root->left, file, space);
}

int main() {
    struct Node* root = NULL;
    FILE* outputFile;

    // Insert nodes into the binary tree
    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(root, 15);
    root = insertNode(root, 3);
    root = insertNode(root, 7);
    root = insertNode(root, 12);
    root = insertNode(root, 20);

    // Open the output file
    outputFile = fopen("tree_output.txt", "w");

    // Write the tree structure to the file
    writeTreeToFile(root, outputFile, 0);

    // Close the file
    fclose(outputFile);

    printf("Binary tree structure written to 'tree_output.txt' file.\n");

    return 0;
}
