#include<stdio.h>
#include<conio.h>
#define max 20

typedef struct Queue
{
    int rear,front;
    int data[max];
}
queue;

void main()
{
    queue q;
    int op,x;

    do
    {
        printf("\n Enter your choice");
        printf("\n 1. Create");
        printf("\n 2. Insert");
        printf("\n 3. Delete");
        printf("\n 4. Destroy");
        printf("\n 5. Display");
        printf("\n 6. Exit\n");

        scanf("%d",&op);

        switch(op)
        {
            case 1 :
            create(&q);
            break;

            case 2 : printf("\n Enter a number\n");
            scanf("%d",&x);
            if(!full(&q))
            {
                enqueue(&q,x);
            }
            else
            {
                printf("\n QUEUE IS FULL");
            }
            break;

            case 3 : if(!empty(&q))
            {
                x=dequeue(&q);
                printf("\n Deleted element is %d",x);
            }
            else
            {
                printf("\n QUEUE IS EMPTY");
            }
            break;

            case 4 : if(!empty(&q))
            {
                destroy(&q);
            }
            else
            {
                printf("\n QUEUE IS EMPTY");
            }
            break;

            case 5 : if(!empty(&q))
            {
                display(&q);
            }
            else
            {
                printf("\n QUEUE IS EMPTY");
            }
            break;

            default :
            if (op>6)
            {
                printf("\n INVALID OPTION ");

            }
        }

    }
    while(op!=6);
}

void create(queue *p)
{
    p->rear=-1;
    p->front=-1;
}

int empty(queue *p)
{
    if(p->rear==-1)
    {
        return (1);
    }
    else
    {
         return(0);
    }
}

int full(queue *p)
{
    if(p->rear==max-1)
    {
        return(1);
    }
    else
    {
        return(0);
    }
}

void enqueue(queue *p,int x)
{
    if(p->rear==-1)
    {
        p->rear=p->front=0;
        p->data[p->rear]=x;
    }
    else
    {
        p->rear=p->rear+1;
        p->data[p->rear]=x ;
    }
}

int dequeue(queue *p)
{
    int t;
    t=p->data[p->front];
    if(p->front==p->rear)
    {
        p->front=-1;
        p->rear=-1;
    }
    else
    {
        p->front=p->front=+1;
    }
    return(t);
}

void display(queue *p)
{
    int i;
    printf("Queue: ");
    for(i=p->front;i<=p->rear;i++)
    {
        printf(" %d ",p->data[i]);
    }
}

void destroy()
{
    int front, rear;
    front=0;
    rear=-1;
    printf("\nQUEUE IS DESTROYED");
}

