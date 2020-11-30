#include <stdio.h>
#include <conio.h>

typedef struct node{
int info;
struct node *link;
}NODE;

NODE* create(NODE *start)
{
 NODE *temp,*t;
 int n,i;
 printf("Enter number of nodes to insert:");
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

void display(NODE *start)
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


NODE* concatenate(NODE *s1,NODE *s2)
{
 NODE *t;
 t=s1;
 while(t->link!=NULL)
  t=t->link;
 t->link=s2;
 return s1;
}

NODE* reverse(NODE *start)
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

NODE* intersect(NODE *s1,NODE *s2)
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
 NODE *s1,*s2;
 int ch;
 s1=NULL;
 s2=NULL;
 while(1)
 {
  printf("Enter choice:\n");
  printf(" 1. Concatenate two lists\n");
  printf(" 2. Reverse a list\n");
  printf(" 3. Intersection of two lists\n");
  printf(" 4. Exit\n");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:
       s1=create(s1);
       display(s1);
       s2=create(s2);
       display(s2);
       s1=concatenate(s1,s2);
       printf("\nResult:");
       display(s1);
       break;
   case 2:
       s1=create(s1);
       display(s1);
       s1=reverse(s1);
       printf("\nResult:");
       display(s1);
       break;
   case 3:
       s1=create(s1);
       display(s1);
       s2=create(s2);
       display(s2);
       s1=intersect(s1,s2);
       printf("\nResult:");
       display(s1);
       break;
   case 4:
       exit(0);
   default:
       printf("Invalid choice");
       break;
  }
//  if(ch>0&&ch<=3)
//  {
//   printf("\nResult:");
//   display(s1);
//  }
 }
}
