#include <stdio.h>
#include <stdlib.h>

int hash(int key){
  return key%20;
}

typedef struct node{
  char name[30];
  int age;
  int key;
}node;
node* table[20]={NULL};

void insert(){
  int i, iter=1;
  node* new;
  new=(node*)malloc(sizeof(node));
  printf("Enter name, age, key: ");
  scanf("%s %d %d", new->name,&new->age, &new->key);
  i=hash(new->key);
  while(table[i]!=NULL && iter<=20){
      i=(i+1)%20;
      iter++;
    }
    if(iter>=20)
      printf("Cannot enter more data.");
    else
      table[i]=new;
}

/* int search(int key){
 *   int i;
 *   int search_hash=hash(key);
 *   int iter=0;
 *   while((table[search_hash]==NULL || table[search_hash]->key!=key) && iter<=20){
 *     search_hash=(search_hash+1)%20;
 *     iter++;
 *   }
 *   if(iter>=20)
 *     return -1;
 *   else
 *     return search_hash;
 *   iter=1;
 * }
 */

void display(){
  printf("Index\tKey\tName\tAge\n");
  for(int i=0;i<20;i++){
    if(table[i]==NULL)
      continue;
    else{
      printf("%d\t%d\t%s\t%d\n",i, table[i]->key, table[i]->name, table[i]->age);
    }
  }
}

void main(){
  int choice, key;
  do{
    printf("1. Insert\n2. Display\n3. Exit\nEnter a choice: ");
    scanf("%d", &choice);
    switch(choice){
      case 1:
      insert();
      break;
/*       case 2:
 *       printf("Enter key to delete: ");
 *       scanf("%d", &key);
 *       int val=search(key);
 *       if(val!=-1){
 *       printf("Person found at index: %d", val);
 *       table[val]=NULL;
 *       printf("\nDeleted data.");
 *       }
 *       else
 *         printf("Person not found");
 *       break;
 *       case 3:
 *       printf("Enter key of person to search: ");
 *       scanf("%d", &key);
 *       int value=search(key);
 *       if(value!=-1)
 *       printf("Person found at index: %d\nKey: %d \tName: %s \tAge: %d", value,table[value]->key,table[value]->name, table[value]->age);
 *       else
 *         printf("Person not found");
 *       break;
 */
      case 2:
      display();
      break;
      case 3: exit(1);
    }
  }while(choice!=3);
}
