#include<stdio.h>
#include<conio.h>

struct poly
{
       int c,pow;
       struct poly *next;
};

struct poly * create_poly(struct poly *header)
{
       struct poly *p_1,*temp;
       char ch;
       printf("\nDo you want to enter a term (y/n) : ");
       getchar();
       scanf("%c",&ch);
       header->c=NULL;
       header->pow=NULL;
       header->next=NULL;
       printf("%c",ch);
       while(ch!='n')
       {
           p_1=(struct poly *)malloc(sizeof(struct poly));
           printf("\nEnter the coefficient value : ");
           scanf("%d",&p_1->c);
           printf("\nEnter the power : ");
           scanf("%d",&p_1->pow);
           p_1->next=NULL;
           if(header->next==NULL)
           {
                header->next=p_1;
                temp=p_1;
           }
           else
           {
               temp->next=p_1;
               temp=p_1;
           }
           printf("\nDo you want to enter a term (y/n) : ");
           getchar();
           scanf("%c",&ch);
       }
       return header;
}
struct poly * poly_add(struct poly *p_1,struct poly *p_2,struct poly *r_1)
{
       p_1=p_1->next;
       p_2=p_2->next;
       struct poly *newnode,*temp;
       r_1->next=NULL;
       while((p_1!=NULL)&&(p_2!=NULL))
       {
            newnode=(struct poly *)malloc(sizeof(struct poly));
            newnode->next=NULL;
            if(p_1->pow==p_2->pow)
            {
                newnode->c=p_1->c+p_2->c;
                newnode->pow=p_1->pow;
                p_1=p_1->next;
                p_2=p_2->next;
            }
            else if(p_1->pow>p_2->pow)
            {
                newnode->c=p_1->c;
                newnode->pow=p_1->pow;
                p_1=p_1->next;
            }
            else
            {
                newnode->c=p_2->c;
                newnode->pow=p_2->pow;
                p_2=p_2->next;
            }
            if(r_1->next==NULL)
            {
                r_1->next=newnode;
                temp=newnode;
            }
            else
            {
                temp->next=newnode;
                temp=newnode;
            }
       }
       if(p_1!=NULL)
       {
             while(p_1!=NULL)
             {
                   newnode=(struct poly *)malloc(sizeof(struct poly));
                   newnode->next=NULL;
                   newnode->c=p_1->c;
                   newnode->pow=p_1->pow;
                   temp->next=newnode;
                   temp=newnode;
                   p_1=p_1->next;
             }
       }
       if(p_2!=NULL)
       {
             while(p_2!=NULL)
             {
                   newnode=(struct poly *)malloc(sizeof(struct poly));
                   newnode->next=NULL;
                   newnode->c=p_2->c;
                   newnode->pow=p_2->pow;
                   temp->next=newnode;
                   temp=newnode;
                   p_2=p_2->next;
             }
       }
}

struct poly * poly_sub(struct poly *p_1,struct poly *p_2,struct poly *r_2)
{
       p_1=p_1->next;
       p_2=p_2->next;
       struct poly *newnode,*temp;
       r_2->next=NULL;
       while((p_1!=NULL)&&(p_2!=NULL))
       {
            newnode=(struct poly *)malloc(sizeof(struct poly));
            newnode->next=NULL;
            if(p_1->pow==p_2->pow)
            {
                  newnode->c=p_1->c-p_2->c;
                  newnode->pow=p_1->pow;
                  p_1=p_1->next;
                  p_2=p_2->next;
            }
            else if(p_1->pow>p_2->pow)
            {
                 newnode->c=p_1->c;
                 newnode->pow=p_1->pow;
                 p_1=p_1->next;
            }
            else
            {
                newnode->c=p_2->c;
                newnode->pow=p_2->pow;
                p_2=p_2->next;
            }
            if(r_2->next==NULL)
            {
                r_2->next=newnode;
                temp=newnode;
            }
            else
            {
                temp->next=newnode;
                temp=newnode;
            }
       }
       if(p_1!=NULL)
       {
             while(p_1!=NULL)
             {
                   newnode=(struct poly *)malloc(sizeof(struct poly));
                   newnode->next=NULL;
                   newnode->c=p_1->c;
                   newnode->pow=p_1->pow;
                   temp->next=newnode;
                   temp=newnode;
                   p_1=p_1->next;
             }
       }
       if(p_2!=NULL)
       {
             while(p_2!=NULL)
             {
                   newnode=(struct poly *)malloc(sizeof(struct poly));
                   newnode->next=NULL;
                   newnode->c=p_2->c;
                   newnode->pow=p_2->pow;
                   temp->next=newnode;
                   temp=newnode;
                   p_2=p_2->next;
             }
       }
}

void display(struct poly *header)
{
     struct poly *ptr=header->next;
     while(ptr!=NULL)
     {
          printf("(%dx^%d)",ptr->c,ptr->pow);
          ptr=ptr->next;
          if(ptr!=NULL)
            printf("+");
     }
}

int main()
{
    struct poly *p_1,*p_2,*r_1, *r_2;
    p_1=(struct poly *)malloc(sizeof(struct poly));
    p_2=(struct poly *)malloc(sizeof(struct poly));
    r_1=(struct poly *)malloc(sizeof(struct poly));
    r_2=(struct poly *)malloc(sizeof(struct poly));

    printf("\nEnter polynomial P1 : ");
    p_1=create_poly(p_1);
    display(p_1);
    printf("\nEnter polynomial P2 : ");
    getchar();
    p_2=create_poly(p_2);
    display(p_2);
    printf("\nPolynomial Addition (Output 1) : ");
    poly_add(p_1,p_2,r_1);
    display(r_1);
    printf("\nPolynomial Subtraction (Output 2) : ");
    poly_sub(p_1,p_2,r_2);
    display(r_2);
    exit(0);
}
