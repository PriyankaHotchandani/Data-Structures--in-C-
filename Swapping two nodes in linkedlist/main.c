/* This program swaps the nodes of linked list rather
   than swapping the field from the nodes.*/

#include<stdio.h>
#include<stdlib.h>

/* A linked list node */
struct Node
{
    int data;
    struct Node *next;
};

/* Function to swap nodes x and y in linked list by
   changing links */
void swap_nodes(struct Node **headRef, int x, int y)
{
   // Nothing to do if x and y are same
   if (x == y) return;

   // Search for x (keep track of prev_x and current_x
   struct Node *prev_x = NULL, *current_x = *headRef;
   while (current_x && current_x->data != x)
   {
       prev_x = current_x;
       current_x = current_x->next;
   }

   // Search for y (keep track of prev_y and current_y
   struct Node *prev_y = NULL, *current_y = *headRef;
   while (current_y && current_y->data != y)
   {
       prev_y = current_y;
       current_y = current_y->next;
   }

   // If either x or y is not present, nothing to do
   if (current_x == NULL || current_y == NULL)
       return;

   // If x is not head of linked list
   if (prev_x != NULL)
       prev_x->next = current_y;
   else // Else make y as new head
       *headRef = current_y;

   // If y is not head of linked list
   if (prev_y != NULL)
       prev_y->next = current_x;
   else  // Else make x as new head
       *headRef = current_x;

   // Swap next pointers
   struct Node *temp = current_y->next;
   current_y->next = current_x->next;
   current_x->next  = temp;
}

/* Function to add a node at the beginning of List */
void push(struct Node** headRef, int new_data)
{
    /* allocate node */
    struct Node* new_node =
        (struct Node*) malloc(sizeof(struct Node));

    /* put in the data  */
    new_node->data  = new_data;

    /* link the old list off the new node */
    new_node->next = (*headRef);

    /* move the head to point to the new node */
    (*headRef)    = new_node;
}

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

/* Driver program to test above function */
int main()
{
    struct Node *start = NULL;

    /* The constructed linked list is:
     1->2->3->4->5->6->7 */
    push(&start, 7);
    push(&start, 6);
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);

    printf("Linked list before swapping nodes: ");
    printList(start);

    swap_nodes(&start, 5, 1);

    printf("\nLinked list after swapping nodes: ");
    printList(start);

    return 0;
}
