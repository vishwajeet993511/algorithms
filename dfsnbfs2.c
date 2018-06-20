#include <stdio.h>
#include <stdlib.h>


struct AdjListNode
{
  int dest;
  int *next;

};

struct AdjList
{
  struct AdjListNode * head;

};

struct Graph
{
   int V;
   struct AdjList * array;

};


struct AdjListNode * createnode(int dest)
{
   struct AdjListNode* newnode = (struct AdjListNode *) malloc ( sizeof(struct AdjListNode));
   newnode->dest = dest;
   newnode->next = NULL;
   return newnode;

}

struct Graph *creategraph(int V)
{
   int i;
   struct Graph * g = (struct Graph *) malloc ( sizeof( struct Graph));
   g->V = V;
   g->array = (struct AdjList *) malloc ( V* sizeof(struct AdjList));
   
   for(i=0;i<V;i++)
    g->array[i].head = NULL;
    
    
    return g;

}

void addEdge(struct Graph *g ,int src,int dest)
{
   struct AdjListNode * newnode = createnode(dest);
   newnode ->next = g->array[src].head;
   g->array[src].head = newnode;
   
   newnode = createnode(src);
   newnode ->next = g->array[dest].head;
   g->array[dest].head = newnode;
   
   
}


void printg(struct Graph *g)
{
   int i,V = g->V;
   struct AdjListNode * temp;
   
   for(i=0;i<V;i++)
   {
      temp = g->array[i].head;
      printf("head -> ");
      while( temp != NULL)
      {
         printf("%d -> ",temp->dest);
         temp = temp->next;
      }
      printf("\n");
   
   }

}



void dfs(struct Graph * g, int node,int *visited)
{
   int i,V = g->V;
   struct AdjListNode *temp = g->array[node].head;
   printf("%d -> ",node);
   visited[node] = 1;
   
   while( temp != NULL)
   {
      if( visited[temp->dest] == 0)
      {
        visited[temp->dest] = 1;
        dfs(g,temp->dest,visited);
        
      }
      temp = temp->next;
   }
   

}



int main()
{
  struct Graph *g = creategraph(5);
  int i,*visited;
  visited = ( int *) malloc( 5 * sizeof( int));
  
  addEdge(g,0,1);
  addEdge(g,0,4);
  addEdge(g,1,2);
  addEdge(g,1,3);
  addEdge(g,1,4);
  addEdge(g,2,3);
  addEdge(g,3,4);
  
   printg(g);
   printf("\n\n");
   for(i=0;i<5;i++)
   {
      visited[i] = 0;
   }
   dfs(g,0,visited);

   printf("\n");
  return 0;
}
