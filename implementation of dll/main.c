#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int n;
    struct node *next;
}*head,*temp,*temp1,*temp2;

int count = 0;

void main()
{
    int ch;

    head = NULL;
    temp = temp1 = NULL;

    printf("\n 1 - Insert at beginning");
    printf("\n 2 - Insert at end");
    printf("\n 3 - Insert at position i");
    printf("\n 4 - Delete at any position");
    printf("\n 5 - Display from beginning");
    printf("\n 6 - Display from end");
    printf("\n 7 - Search for element");
    printf("\n 8 - Destroy");
    printf("\n 9 - Exit");

    while (1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert_beg();
            break;
        case 2:
            insert_end();
            break;
        case 3:
            insert_i();
            break;
        case 4:
            delete_i();
            break;
        case 5:
            display_beg();
            break;
        case 6:
            temp2 = head;
            if (temp2 == NULL)
                printf("\n Error: List is empty");
            else
            {
                printf("\n Linked list in reverse order: ");
                display_end(temp2->n);
            }
            break;
        case 7:
            search();
            break;
        case 8:
            destroy();
            break;
        case 9:
            exit(0);
        default:
            printf("\n Invalid Choice!");
        }
    }
}

void create()
{
    int data;

    temp =(struct node *)malloc(1*sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;
    printf("\n Enter value: ");
    scanf("%d", &data);
    temp->n = data;
    count++;
}

void insert_beg()
{
    if (head == NULL)
    {
        create();
        head = temp;
        temp1 = head;
    }
    else
    {
        create();
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insert_end()
{
    if (head == NULL)
    {
        create();
        head = temp;
        temp1 = head;
    }
    else
    {
        create();
        temp1->next = temp;
        temp->prev = temp1;
        temp1 = temp;
    }
}

void insert_i()
{
    int pos, i = 2;

    printf("\n Enter position to be inserted: ");
    scanf("%d", &pos);
    temp2 = head;

    if ((pos < 1) || (pos >= count + 1))
    {
        printf("\n Position out of range");
        return;
    }
    if ((head == NULL) && (pos != 1))
    {
        printf("\n Empty list, cannot insert other than at 1st position");
        return;
    }
    if ((head == NULL) && (pos == 1))
    {
        create();
        head = temp;
        temp1 = head;
        return;
    }
    else
    {
        while (i < pos)
        {
            temp2 = temp2->next;
            i++;
        }
        create();
        temp->prev = temp2;
        temp->next = temp2->next;
        temp2->next->prev = temp;
        temp2->next = temp;
    }
}

void delete_i()
{
    int i = 1, pos;

    printf("\n Enter position of node to be deleted: ");
    scanf("%d", &pos);
    temp2 = head;

    if ((pos < 1) || (pos >= count + 1))
    {
        printf("\n Error: Position out of range");
        return;
    }
    if (head == NULL)
    {
        printf("\n Error: Empty list");
        return;
    }
    else
    {
        while (i < pos)
        {
            temp2 = temp2->next;
            i++;
        }
        if (i == 1)
        {
            if (temp2->next == NULL)
            {
                printf("Node deleted from list");
                free(temp2);
                temp2 = head = NULL;
                return;
            }
        }
        if (temp2->next == NULL)
        {
            temp2->prev->next = NULL;
            free(temp2);
            printf("Node deleted from list");
            return;
        }
        temp2->next->prev = temp2->prev;
        if (i != 1)
            temp2->prev->next = temp2->next;
        if (i == 1)
            head = temp2->next;
        printf("\n Node deleted");
        free(temp2);
    }
    count--;
}

void destroy()
{
    while (head!=NULL)
    {
        temp1=head;
        head=head->next;
        free(temp1);
    }
    printf("List destroyed");
}

void display_beg()
{
    temp2 = head;

    if (temp2 == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("\n Linked list elements from begining: ");

    while (temp2->next != NULL)
    {
        printf(" %d ", temp2->n);
        temp2 = temp2->next;
    }
    printf(" %d ", temp2->n);
}

void display_end(int i)
{
    if (temp2 != NULL)
    {
        i = temp2->n;
        temp2 = temp2->next;
        display_end(i);
        printf(" %d ", i);
    }
}

void search()
{
    int data, count = 0;
    temp2 = head;

    if (temp2 == NULL)
    {
        printf("\n Error: List is empty");
        return;
    }
    printf("\n Enter value to search: ");
    scanf("%d", &data);
    while (temp2 != NULL)
    {
        if (temp2->n == data)
        {
            printf("\n Data found in %d position",count + 1);
            return;
        }
        else
             temp2 = temp2->next;
            count++;
    }
    printf("\n Error: %d not found in list", data);
}
