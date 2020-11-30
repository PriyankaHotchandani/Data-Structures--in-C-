#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *pre, *next;
};

struct node *head = NULL, *tail = NULL;

struct node * createNode(int data) {
    struct node *newnode = (struct node *)malloc(sizeof (struct node));
    newnode->data = data;
    newnode->next = newnode->pre = NULL;
    return (newnode);
}


void create() {
    head = createNode(0);
    tail = createNode(0);
    head->next = tail;
    tail->pre = head;
}


void enqueueFront(int data) {
    struct node *newnode, *temp;
    newnode = createNode(data);
    temp = head->next;
    head->next = newnode;
    newnode->pre = head;
    newnode->next = temp;
    temp->pre = newnode;
}


void enqueueRear(int data) {
    struct node *newnode, *temp;
    newnode = createNode(data);
    temp = tail->pre;
    tail->pre = newnode;
    newnode->next = tail;
    newnode->pre = temp;
    temp->next = newnode;
}


void dequeueFront() {
    struct node *temp;
    if (head->next == tail) {
            printf("Queue is empty\n");
    } else {
            temp = head->next;
            head->next = temp->next;
            temp->next->pre = head;
            free(temp);
    }
    return;
}


void dequeueRear()  {
    struct node *temp;
    if (tail->pre == head) {
            printf("Queue is empty\n");
    } else {
            temp = tail->pre;
            tail->pre = temp->pre;
            temp->pre->next = tail;
            free(temp);
    }
    return;
}


void display() {
    struct node *temp;

    if (head->next == tail) {
            printf("Queue is empty\n");
            return;
    }

    temp = head->next;
    while (temp != tail) {
            printf("%-3d", temp->data);
            temp = temp->next;
    }
    printf("\n");
}

int main() {
    int data, ch;
    create();
    while (1)
    {
        printf("1. Create\n");
        printf("2. Insert at front\n");
        printf("3. Insert at rear\n");
        printf("4. Delete at front\n");
        printf("5. Delete at rear\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                create();
                break;

            case 2:
                printf("Enter data to insert:");
                scanf("%d", &data);
                enqueueFront(data);
                break;

            case 3:
                printf("Enter data to insert:");
                scanf("%d", &data);
                enqueueRear(data);
                break;

            case 4:
                dequeueFront();
                break;

            case 5:
                dequeueRear();
                break;

            case 6:
                display();
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid option\n");
                break;
                }
        }
        return 0;
  }

