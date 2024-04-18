/*Kaguchia Kago - SCT221-0522/2022
Katra Noor Soyan - sct221-0397/2022
Brian Kyalo Kimanzi - SCT221-0181/2023*/
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to construct a binary search tree from in-order and post-order arrays
struct Node* bst_construct(int* inOrder, int* postOrder, int inStart, int inEnd, int* postIndex) {
    if (inStart > inEnd)
        return NULL;

    // Create a new node with the last element from post-order array
    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->data = postOrder[*postIndex];
    root->left = root->right = NULL;

    (*postIndex)--;

    // Find the index of root in in-order arra
    int inIndex;
    for (inIndex = inStart; inIndex <= inEnd; inIndex++) {
        if (inOrder[inIndex] == root->data)
            break;
    }

    // Recursively construct the right subtree first (since post-order is left-right-root)
    root->right = bst_construct(inOrder, postOrder, inIndex + 1, inEnd, postIndex);
    root->left = bst_construct(inOrder, postOrder, inStart, inIndex - 1, postIndex);

    return root;
}

// Function to print BST elements in BFS order
void bfs_traversal(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct Node* current = queue[front++];
        printf("%d ", current->data);

        if (current->left)
            queue[rear++] = current->left;
        if (current->right)
            queue[rear++] = current->right;
    }
}

int main() {
    int inOrder[] = {5, 10, 15, 20, 25, 30, 45};
    int postOrder[] = {5, 15, 10, 25, 45, 30, 20};
    int n = sizeof(inOrder) / sizeof(inOrder[0]);
    int postIndex = n - 1;

    struct Node* root = bst_construct(inOrder, postOrder, 0, n - 1, &postIndex);

    printf("BFS Traversal of the constructed BST:\n");
    bfs_traversal(root);
   

    return 0;
}
