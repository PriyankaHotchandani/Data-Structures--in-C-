#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *ptr;
};
struct node* top = NULL;


void display()
{
    struct node* temp = top;

    if (temp == NULL)
    {
        printf("\nThe stack is empty");
    }
    else
    {
        printf("\nThe stack is:\n");
        while (temp != NULL)
        {
            printf("%d ", temp->info);
            temp = temp->ptr;
        }
    }
    free(temp);
}


void sort()
{
    int s, i;
    struct node* q_1;
    struct node* last = NULL;

    if (top == NULL)
        return;

    do
    {
        s = 0;
        q_1 = top;

        while (q_1->ptr != last)
        {
            if (q_1->info > q_1->ptr->info)
            {
                int temp = q_1->info;
                q_1->info = q_1->ptr->info;
                q_1->ptr->info = temp;
                s = 1;
            }
            q_1 = q_1->ptr;
        }
        last = q_1;
    }
    while (s);
}


void create()
{
    int data,n,i;
    struct node* temp;
    printf("Number of elements to be entered: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("Enter element at position %d: ",i);
        scanf("%d",&data);
        if (top == NULL)
        {
            top =(struct node *)malloc(1*sizeof(struct node));
            top->ptr = NULL;
            top->info = data;
        }
        else
        {
            temp =(struct node *)malloc(1*sizeof(struct node));
            temp->ptr = top;
            temp->info = data;
            top = temp;
        }
    }
    sort();
}


void insert()
{
    struct node* temp;
    struct node* q= top;
    int data;
    if(top==NULL)
    {
        printf("Create the list first");
        return;
    }
    printf("Enter the element to be inserted:");
    scanf("%d",&data);
    while(q->ptr!= NULL)
    {
        if(data > (q->info) && data < (q->ptr->info))
        {
            temp =(struct node *)malloc(1*sizeof(struct node));
            temp->ptr = q->ptr;
            temp->info = data;
            q->ptr = temp;
        }
        q=q->ptr;
    }
}


void delete_n()
{
    int count=0,i;
    struct node* temp = top;
    if(temp == NULL)
    {
        printf("The stack is empty");
    }
    else
    {
        printf("The elements of the stack are:\n");
        display();
        printf("\nEnter the position of element to be deleted: ");
        scanf("%d",&i);
        if(i==1)
        {
            top= top->ptr;
            free(temp);
            printf("\nElement deleted successfully. The stack is: \n");
            display();
            return;
        }
        while(count<i)
        {
            temp = temp->ptr;
            count++;
            if(count == i)
            {
                struct node* next = temp->ptr->ptr;
                temp->ptr = next;
            }
        }
        free(temp->ptr);
        printf("\nElement deleted successfully. The stack is: \n");
        display();
    }
}


void search()
{
    int i,pos=1;
    printf("Enter element to be searched: ");
    scanf("%d",&i);
    struct node* temp= top;
    while(temp)
    {
        if(temp->info == i)
        {
            printf("Element is found at position %d",pos);
        }
        temp=temp->ptr;
        pos++;
    }
}


void destroy()
{
    struct node* top1 = top;

    while (top1 != NULL)
    {
        top1 = top->ptr;
        free(top);
        top = top1;
        top1 = top1->ptr;
    }
    free(top1);
    top = NULL;

    printf("\nThe stack is destroyed");
}


void main()
{
    int option;
    top = NULL;
    do
    {
        printf("\nEnter your choice:");
        printf("\n1.Create");
        printf("\n2.Insert");
        printf("\n3.Search");
        printf("\n4.Display");
        printf("\n5.Delete");
        printf("\n6.Destroy");
        printf("\n7.Exit\n");
        scanf("%d",&option);
        switch (option)
        {
        case 1:
                create();
                break;
        case 2:
                insert();
                break;
        case 3:
                search();
                break;
        case 4:
                display();
                break;
        case 5:
                delete_n();
                break;
        case 6:
                destroy();
                break;
        default:
            printf("\nINVALID OPTION");

        }
    } while(option!=7);
}
