#include <stdio.h>
#include <stdlib.h>


struct st
{
   int data;
   struct st * next;

};

struct st *createnode( int data )
{
    struct st *newnode = ( struct st *) malloc ( sizeof( struct st));
    newnode ->data = data;
    newnode ->next = NULL;
    
    return newnode;  
   
}

int isempty( struct st *root)
{
   if( root == NULL )
    return 1;
   else return 0;

}


void push( struct st ** root,int data)
{

    struct st *newnode = createnode(data);
    newnode->next = *root;
    (*root) = newnode;
    printf("%d pushed to stack\n", data);

}

int pop( struct st ** root)
{
    if( isempty( *root) )
      return -1;
    int temp ; 
    
    struct st * temp1;
    temp1 = *root;
    *root =  (*root)->next;
    temp = temp1->data;
    free(temp1);
    
    printf("%d was popped from stack\n",temp);
    return temp;


}

void print(struct st * stack )
{
  printf("head ->");
  while( stack != NULL )
  {
    printf(" %d -> ", stack->data);
    stack = stack -> next;
  }
  printf("\n");

}


int main()
{
   int temp;
   struct st * stack= NULL;
   //stack = (struct st *) malloc ( sizeof( struct st));
   push(&stack,10);
   push(&stack,20);
   push(&stack,30);
   print(stack);
   temp = pop(&stack);
   
   printf("%d\n",temp);
   
   
   
   
   print(stack);
  

   return 0;
}
