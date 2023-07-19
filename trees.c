#include<stdio.h>
#include<stdlib.h>
#define max_size 1000

// Structure for a tree node
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

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Inorder traversal
void inorderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Preorder traversal
void preorderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Postorder traversal
void postorderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}
// Driver code
int main() {
    struct Node *root;
    int num, i;
    time_t t1;
    srand ( (unsigned) time (&t1));
    FILE *fp,*fp1,*fp2,*fp3;
    int arr[max_size],j,temp,size=0;
    fp = fopen("input.txt","w");
     for (i = 0; i <10; i++)
    {
        fprintf( fp,"%d \n", rand() % 50);

    }

    fp = fopen("input.txt","r");

    while(fscanf(fp,"%d",&arr[size])!=EOF)
    {
      size++;
    }

   fclose(fp);

    fp1 = fopen("inorder.txt","w");
    for(i=0;i<size;i++)
    {
         inorderTraversal(root);
    }
    fclose(fp1);
    fp2 = fopen("preorder.txt","w");
    for(i=0;i<size;i++)
    {
    preorderTraversal(root);
    }
    fclose(fp2);
    fp3 = fopen("postorder.txt","w");
    for(i=0;i<size;i++)
    {

        postorderTraversal(root);
    }
    fclose(fp3);



    return 0;
}
