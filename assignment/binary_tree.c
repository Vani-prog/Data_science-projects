#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to find the Lowest Common Ancestor (LCA)
struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;
    
    if (root->data == n1 || root->data == n2)
        return root;
    
    struct Node* leftLCA = findLCA(root->left, n1, n2);
    struct Node* rightLCA = findLCA(root->right, n1, n2);
    
    if (leftLCA && rightLCA) return root;
    
    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

// Function to find the distance from root to a given node
int findLevel(struct Node* root, int key, int level) {
    if (root == NULL) return -1;
    if (root->data == key) return level;
    
    int left = findLevel(root->left, key, level + 1);
    if (left != -1) return left;
    
    return findLevel(root->right, key, level + 1);
}

// Function to find the distance between two nodes
int findDistance(struct Node* root, int n1, int n2) {
    struct Node* lca = findLCA(root, n1, n2);
    if (lca == NULL) return -1;
    
    int d1 = findLevel(lca, n1, 0);
    int d2 = findLevel(lca, n2, 0);
    
    return d1 + d2;
}

// Main function
int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    
    int n1, n2;
    printf("Enter two node values to find the distance: ");
    scanf("%d %d", &n1, &n2);
    
    int distance = findDistance(root, n1, n2);
    if (distance != -1)
        printf("Distance between %d and %d is: %d\n", n1, n2, distance);
    else
        printf("One or both nodes not found in the tree.\n");
    
    return 0;
}

