#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct treeNode {
    int data;
    struct treeNode * left;
    struct treeNode * right;
} * TreeNode;

TreeNode createNode(int data) {

    TreeNode newNode = (TreeNode) malloc(sizeof(struct treeNode));
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;

    return newNode;
}

void traversePreOrderTree(TreeNode head) {

    if (head == NULL) {
        return;
    }

    printf("%d -> ", head -> data);
    traversePreOrderTree(head -> left);
    traversePreOrderTree(head -> right);

}
void traverseInOrderTree(TreeNode head) {

    if (head == NULL) {
        return;
    }

    traversePreOrderTree(head -> left);
    printf("%d -> ", head -> data);
    traversePreOrderTree(head -> right);

}
void traversePostOrderTree(TreeNode head) {

    if (head == NULL) {
        return;
    }

    traversePreOrderTree(head -> left);
    traversePreOrderTree(head -> right);
    printf("%d -> ", head -> data);

}

void freeTree(TreeNode root) {

    if (root == NULL) return ;

    freeTree(root -> left);
    freeTree(root -> right);
    free(root);
}

void printTrees() {

}

TreeNode createTree(int * arr, int size) {

    TreeNode root = createNode(arr[0]);
    
    for (int i = 1; i < size; i++) {

        TreeNode temp = root;

        while (true) {

            if (temp -> data > arr[i]) {
                if (temp -> left == NULL) {
                    temp -> left = createNode(arr[i]);
                    break;
                } else {
                    temp = temp -> left;
                    continue;
                }
            } else if (temp -> data < arr[i]) {
                if (temp -> right == NULL) {
                    temp -> right = createNode(arr[i]);
                    break;
                } else {
                    temp = temp -> right;
                    continue;
                }
            }
            break;
        }


    }

    return root;
}

int * createArray(int sizeOfArray) {
    int * arr = (int*) malloc(sizeOfArray * sizeof(int));

    for (int i = 0; i < sizeOfArray; i++) {
        scanf("%d", &arr[i]);
    }

    return arr;
}

int main() {

    int numOfElement;
    printf("No. of Elements: ");
    scanf("%d", &numOfElement);
    
    printf("Enter elements sperated by space: ");
    int * arr = createArray(numOfElement);

    TreeNode tree1 = createTree(arr, numOfElement);
    printf("PreOrder: ");
    traversePreOrderTree(tree1);
    printf("NULL\n");
    printf("InOrder: ");
    traverseInOrderTree(tree1);
    printf("NULL\n");
    printf("PostOrder: ");
    traversePostOrderTree(tree1);
    printf("NULL\n");

    freeTree(tree1);
    free(arr);
    
    arr = NULL;
    tree1 = NULL;

    return 0;
}