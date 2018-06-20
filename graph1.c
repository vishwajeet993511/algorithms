#include <stdio.h>
#include <stdlib.h>


struct AdjListNode
{
   int dest;
   struct AdjListNode * next;

};

struct AdjList
{
  struct AdjListNode *head;

};

struct Graph
{
  int V;
  struct AdjList * array;

};

struct AdjListNode *createNode ( int dest)
{
   struct AdjListNode * newnode;
   newnode = (struct AdjListNode *) malloc (sizeof(struct AdjListNode));
   newnode ->dest = dest;
   newnode -> next = NULL;
   
   return newnode;

}

struct Graph *createGraph(int V)
{
   int n,i;
   struct Graph *graph = (struct Graph *) malloc(sizeof(struct Graph *));
   graph->V = V;
   
   graph->array = (struct AdjList *) malloc(V * sizeof(struct AdjList));
   
   
   for( i=0;i<V;i++)
   {
       graph->array[i].head = NULL;
      
   }
   return graph;
   
}

void printGraph(struct Graph * graph)
{
   int V = graph->V;
   int i;
   for(i=0;i<V;i++)
   {
      struct AdjListNode *p;
      p = graph->array[i].head;
      printf("head ->");
      while( p!=NULL)
      {
         
         printf(" %d -> ",p->dest);
         p = p->next;
      }
      printf("\n");
   
   }


}

void addEdge(struct Graph *graph,int src,int dest)
{
    int V = graph->V;
    int i;
    
    struct AdjListNode * newnode = createNode(dest);
    newnode->next = graph->array[src].head;
    graph->array[src].head = newnode;
    
    
    newnode = createNode(src);
    newnode->next = graph->array[dest].head;
    graph->array[dest].head = newnode;
    
    

}


int main()
{

   int V;
   printf("enter n\n");
   scanf("%d",&V);
   int i;
   
   struct Graph * graph = createGraph(V);
   
   addEdge(graph, 0,1);
   addEdge(graph, 0,4);
   addEdge(graph, 1,4);
   addEdge(graph, 1,2);
   addEdge(graph, 1,3);
   addEdge(graph, 2,3);
   addEdge(graph, 3,4);
   
   printGraph(graph);
   
   


   return 0;
}
