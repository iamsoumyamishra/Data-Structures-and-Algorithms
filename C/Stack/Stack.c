#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int * stack;
    int top;
    int capacity;
} Stack;

Stack * createStack(int capacity) {

    Stack * newStack = (Stack*) malloc(sizeof(Stack));
    newStack -> stack = (int*) malloc(sizeof(int) * capacity);
    newStack -> top = -1;
    newStack -> capacity = capacity;

    return newStack;
}

void push(Stack * stack, int val) {

    if (stack -> top == stack -> capacity - 1) {
        printf("The Stack is Full!\n");
        return;
    }
    stack -> stack[++stack->top] = val;
}

int pop(Stack * stack) {

    if (stack -> top == -1) {
        printf("\nThe Stack is Empty!\n");
        return -1;
    }

    return stack -> stack[stack -> top--];
}

int peek(Stack * stack) {

    if (stack -> top == -1) {
        printf("\nThe Stack is Empty\n");
        return -1;
    }

    return stack -> stack[stack -> top];
}

int isEmpty(Stack * stack) {

    return stack -> top == -1;
}

int size(Stack * stack) {

    return stack -> top + 1;
}

int main() {

    while(true) {

        int option;
        Stack * stack;

        printf("\nMenu: \n1. Create a new Stack\n2. Push an element\n3. Pop an element\n4. Get the top most element\n5. Check if the satck is Empty\n6. Get the size of the stack\n7. Exit\n\n");

        printf("Select an Option: ");
        scanf("%d", &option);

        switch(option) {

            case(1):

                int capacity;

                printf("\nEnter the capacity of the Stack: ");
                scanf("%d", &capacity);

                stack = createStack(capacity);

                break;

            case(2):

                int element;

                printf("\nEnter the element to be pushed: ");
                scanf("%d", &element);

                push(stack, element);
                break;

            case(3):

                printf("\nPopped Element: %d\n", pop(stack));
                break;

            case(4):
                
                printf("\nThe top most element of the stack is: %d\n", peek(stack));
                break;

            case(5):
                
                printf("\nIs the Stack Empty: %s\n", isEmpty(stack) ? "true":"false");
                break;
            
            case(6):

                printf("\nThe size of the Stack is: %d\n", size(stack));
                break;

            case(7):

                exit(0);
                break;

            default:
                printf("\nInvalid Option\n");
                break;
            
        }
    }

    return 0;
}