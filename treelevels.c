#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;


Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

int findLevels(Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftDepth = findLevels(root->left);
        int rightDepth = findLevels(root->right);

        if (leftDepth > rightDepth) {
            return (leftDepth + 1);
        } else {
            return (rightDepth + 1);
        }
    }
}

void countNodesPerLevel(Node* root, int level, int* count, FILE* outputFile) {
    if (root == NULL) {
        return;
    }

    if (level == 1) {
        (*count)++;
    } else if (level > 1) {
        countNodesPerLevel(root->left, level - 1, count, outputFile);
        countNodesPerLevel(root->right, level - 1, count, outputFile);
    }
}

Node* generateRandomTree(int n) {
    Node* root = NULL;
    int i, num;
    printf("Enter the no.of nodes in the tree:");
    scanf("%d",&n);
    FILE* inputFile = fopen("input.txt", "w");
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        num = rand() % 100;
        fprintf(inputFile,"%d  ", num);
        root = insertNode(root, num);
    }

    fclose(inputFile);
    return root;
}
void writeTreeToFile(struct Node* root, FILE* file, int space) {
    if (root == NULL) {
        return;
    }

    space += 5;

    writeTreeToFile(root->right, file, space);

    fprintf(file, "\n");
    for (int i = 5; i < space; i++) {
        fprintf(file, "-");
    }
    fprintf(file, "%d\n", root->data);


    writeTreeToFile(root->left, file, space);
}

int main() {
    int n, i;
    FILE* inputFile = fopen("input.txt", "r");
    FILE* outputFile = fopen("output.txt", "w");
    FILE* outputFile1 = fopen("tree_output.txt", "w");;

    fscanf(inputFile, "%d", &n);
    Node* root = generateRandomTree(n);
    fclose(inputFile);

    int levels = findLevels(root);
    fprintf(outputFile, "Total no.of levels: %d\n", levels);

    for (i = 1; i <= levels; i++) {
        int count = 0;
        countNodesPerLevel(root, i, &count, outputFile);
        fprintf(outputFile, "Level %d: %d nodes\n", i, count);
    }
    fclose(outputFile);
      writeTreeToFile(root, outputFile1, 0);

    fclose(outputFile1);
    return 0;
}
