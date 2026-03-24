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

TreeNode createTree(int arr[], int size) {

    TreeNode head = createNode(arr[0]);
    
    for (int i = 1; i < size; i++) {

        TreeNode temp = head;

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
        }


    }

    return head;
}


int main() {

    int arr[] = {7,2, 6, 8, 3, 9};

    TreeNode tree1 = createTree(arr, sizeof(arr) / sizeof(int));
    traversePreOrderTree(tree1);


    return 0;
}