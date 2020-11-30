#include <stdio.h>
#include <stdlib.h>
#define max 50

int top=-1, A[max];

void push(int x)
{
    if (top == max-1)
    {
        printf("\nStack overflow");
    }
    else
    {
        top = top + 1;
        A[top]=x;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("\nNo element to pop");
    }
    else
    {
        top = top - 1;
    }
}

void peep()
{
    if (top == -1)
    {
        printf("\nStack is empty");
    }
    else
    {
        printf("%d", A[top]);
    }
}

void display()
{
    int i;
    if (top == -1)
    {
        printf("\nStack is empty");
    }
    else
    {
        printf("\nStack:");
        for(i=top; i>=0; i--)
        {
            printf("\n%d", A[i]);
        }
    }
}

void destroy()
{
    top == -1;
    printf("The stack is destroyed");
    exit(0);
}

int main()
{
    int option, x;
    do
    {
        printf("\n 1. Push");
        printf("\n 2. Pop");
        printf("\n 3. Peep");
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
            peep();
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
