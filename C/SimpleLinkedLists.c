#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;

Node * createNode(int val) {
    
    Node * newNode = (Node *) malloc(sizeof(Node));

    newNode -> val = val;
    newNode -> next = NULL;

    return newNode;
}

void printNodes(Node * node) {

    while (node -> next != NULL) {
        printf("%d -> ", node -> val);
        node = node -> next;
    }
    printf("%d\n", node -> val);
}

int main() {

    int n = 1;
    Node * lastNode;

    do {
        scanf("%d", &n);
        Node * newNode = createNode(n);
        newNode -> next = lastNode;
        lastNode = newNode;
    } while (n != 0);

    printNodes(lastNode);
    
    return 0;
}