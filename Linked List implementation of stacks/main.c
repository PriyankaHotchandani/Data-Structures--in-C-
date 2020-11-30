#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* link;
};
struct Node* top = NULL;

void push(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    temp->data = x;
    temp->link = top;
    top = temp;
}

void pop()
{
    struct Node *temp;
    if(top==NULL)
        return;
    temp = top;
    top = top->link;
    free(temp);
}

void peek()
{
    if (top != NULL)
    {
        printf("\nElement on top: %d", top->data);
    }
    else
    {
        printf("\nThe stack is empty.");
    }
}

void display()
{
    int i;
    if (top == NULL)
    {
        printf("\nStack is empty.");
    }
    else
    {
        struct Node *temp = top;
        while (temp->link != NULL)
        {
            printf("%d--->", temp->data);
            temp = temp->link;
        }
        printf("%d--->NULL", temp->data);
    }
}

void destroy()
{
    top == NULL;
    printf("The stack is destroyed.");
    exit(0);
}

int main()
{
    int option, x;
    do
    {
        printf("\n 1. Push");
        printf("\n 2. Pop");
        printf("\n 3. Peek");
        printf("\n 4. Display");
        printf("\n 5. Destroy");
        printf("\n Enter choice of operation to be performed:");
        scanf("%d", &option);
        switch(option)
        {
        case 1:
            printf("Enter element to push: ");
            scanf("%d", &x);
            push(x);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            destroy();
            break;
        default:
            printf("Error: Invalid option");
            break;
        }
    }
    while (1);

    return 0;
}
