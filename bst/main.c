#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* right;
    struct node* left;
} node;
node *root=NULL;
node* deleteNode(node*, int);

node* create(int data){
    node* temp;
    temp=(node*)malloc(sizeof(node));
    int key=data;
    temp->data=key;
    temp->left=temp->right=NULL;
    return temp;
}

void insert(node *r, int data){
    node* temp=create(data);
    if(r==NULL){
        root=temp;
    }
    else{
        if(data < r->data){
            if(r->left==NULL){
                r->left=temp;
            }
        else
            insert(r->left, data);
        }
    else if(data>r->data){
        if(r->right==NULL){
            r->right=temp;
        }
        else
        insert(r->right, data);
        }
    }
}

void inorder(node *parent){
    if(parent==NULL)
    return;
    else if(parent!=NULL){
        inorder(parent->left);
        printf("%d ", parent->data);
        inorder(parent->right);
    }
    else
        return;
}

void preorder(node *parent){
    if(parent==NULL)
        return;
    else if(parent!=NULL){
        printf(" %d", parent->data);
        preorder(parent->left);
        preorder(parent->right);
    }
}

void postorder(node* parent){
    if (parent==NULL)
        return;
    else if(parent!=NULL){
        postorder(parent->left);
        postorder(parent->right);
        printf(" %d", parent->data);
    }
}

node* search(node* root, int key){
    if(root==NULL){
        printf("No such element.");
        return root;
    }
    else if(root->data==key){
        printf("Element found!");
    }
    else if(root->data>key){
        return search(root->left, key);
    }
    else{
        return search(root->right, key);
    }
}

node* minimum(node* parent){
    if(parent->left==NULL)
        return parent;
    else
        return minimum(parent->left);
}

node* deleteNode(node* parent, int key){
    if(parent==NULL)
        return NULL;
    else if(key<parent->data)
        parent->left=deleteNode(parent->left,key);
    else if(key>parent->data)
        parent->right=deleteNode(parent->right, key);
    else{
        if(parent->left==NULL && parent->right==NULL)
            parent=NULL;
        else if(parent->right==NULL)
            parent=parent->left;
        else if(parent->left==NULL)
            parent=parent->right;
        else{
            node* temp=minimum(parent->right);
            parent->data=temp->data;
            parent->right=deleteNode(parent->right, temp->data);
        }
    }
    return parent;
}

void main(){
    int choice=0;
    int data, key, element;
    while(choice!=7){
        printf("\n1. Insert");
        printf("\n2. Inorder traversal");
        printf("\n3. Postorder Traversal");
        printf("\n4. Preorder Traversal");
        printf("\n5. Search");
        printf("\n6. Delete");
        printf("\n7. Exit");
        printf("\nEnter a choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the data node: ");
                scanf("%d", &data);
                insert(root, data);
                break;
            case 2:
                printf("Inorder traversal: ");
                inorder(root);
                break;
            case 3:
                printf("Postorder Traversal: ");
                postorder(root);
                break;
            case 4:
                printf("Preorder Traversal: ");
                preorder(root);
                break;
            case 5:
                printf("Enter a number to search for: ");
                scanf("%d", &key);
                search(root,key);
                break;
            case 6:
                printf("Enter the number to delete: ");
                scanf("%d", &element);
                root=deleteNode(root,element);
                break;
            case 7:
                exit(1);
            default:
                printf("Invalid choice.");
        }
    }
}
