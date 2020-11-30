#include <stdio.h>
#include <conio.h>

typedef struct node{
int info;
struct node *link;
}NODE;

NODE* create(NODE *start)//for creating a list
{
 NODE *temp,*t;
 int n,i;
 printf("Enter no of nodes you want to insert:");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  temp=(NODE*) malloc(sizeof(NODE));
  printf("Enter data for node %d:",i+1);
  scanf("%d",&temp->info);
  temp->link=NULL;
  if(start==NULL)
   start=temp;
  else
  {
   t=start;
   while(t->link!=NULL)
    t=t->link;
   t->link=temp;
  }
 }
 return start;
}

void disp(NODE *start)//for printing a list
{
 NODE *t;
 printf("\nElements of the list:");
 for(t=start;t!=NULL;t=t->link)
 {
  if(t->link!=NULL)
   printf("%d->",t->info);
  else
   printf("%d",t->info);
 }
 printf("\n");
}

NODE* concat(NODE *s1,NODE *s2)//concatenate 2 lists
{
 NODE *t;
 t=s1;
 while(t->link!=NULL)
  t=t->link;
 t->link=s2;
 return s1;
}

NODE* rev(NODE *start)//to reverse a list
{
 NODE *t1,*t2,*s;
 for(t1=start;t1->link!=NULL;t1=t1->link);
 s=t1;
 while(t1!=start)
 {
  for(t2=start;t2->link!=t1;t2=t2->link);
  t1->link=t2;
  t1=t2;
 }
 t1->link=NULL;
 return s;
}

NODE* inter(NODE *s1,NODE *s2)//to find the intersection of 2 lists
{
 NODE *s3,*t1,*t2,*t3,*temp;
 s3=(NODE*) malloc(sizeof(NODE));
 s3=NULL;
 t1=s1;
 while(t1!=NULL)
 {
  t2=s2;
  while(t2!=NULL)
  {
   if(t1->info==t2->info)
   {
    temp=(NODE*) malloc(sizeof(NODE));
    temp->info=t1->info;
    temp->link=NULL;
    if(s3==NULL)
     s3=temp;
    else
    {
     for(t3=s3;t3->link!=NULL;t3=t3->link);
     t3->link=temp;
    }
    break;
   }
   t2=t2->link;
  }
  t1=t1->link;
 }
 return s3;
}

void main()
{
    NODE *s1, *s2;
    int choice;
    s1=NULL;
    s2=NULL;
    do
    {
        printf("\n 1. Concatenation of two lists");
        printf("\n 2. Intersection of two lists");
        printf("\n 3. Reversal of list");
        printf("\n Enter choice of operation to be performed:");
        scanf("%d", &choice);
        if (choice==1 && choice<=3)
            s1=create(s1);
            disp(s1);
        switch(choice)
        {
        case 1:
            s2=create(s2);
            disp(s2);
            s1=concat(s1,s2);
            break;
        case 2:
            s2=create(s2);
            disp(s2);
            s1=inter(s1,s2);
            break;
        case 3:
            s1=rev(s1);
            break;
        default:
            printf("Error: Invalid option");
            break;
        }
    }
    while (1);

    return 0;
}
