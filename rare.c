#include <stdio.h>
#include <stdlib.h>


struct point 
{
   int x;
   int y;
   int dist;

};

struct Qnode
{
   struct point pt;
   struct Qnode * next;

};

struct Queue 
{
   struct Qnode *front, *rear;
};

struct Qnode * createnode( int x, int y,int dist )
{
    struct Qnode *qn = ( struct Qnode * ) malloc ( sizeof(struct Qnode));
    qn->pt.x = x;
    qn->pt.y = y;
    qn->pt.dist = dist;
    qn->next = NULL;

}


void push( struct Queue ** q, int x, int y,int dist )
{
    struct Qnode * qn = createnode(x,y,dist);
  
    if( (*q)->front == NULL)
    {
      (*q)->front = (*q)->rear = qn;
      return;
    }
     
    (*q)->rear->next = qn;
    (*q)->rear = qn;
    
}

struct Qnode *pop(struct Queue **q )
{
     struct Qnode *qn;
     
     if( (*q)->front == NULL)
       return NULL;
     qn = (*q)->front ;
     
     (*q)->front = (*q)->front->next;
     
     if( (*q)->front == NULL)
       (*q)->rear = NULL;
       
     return qn;     


} 

struct Queue * createqueue()
{
     struct Queue * q = (struct Queue *) malloc ( sizeof( struct Queue ));
     q->front = NULL;
     q->rear = NULL;
     
     return q;

}

int isempty(struct Queue *q)
{
      return !(q->front);

}

int isok( int x, int y, int m, int n)
{
      return ( x >=0 && x <m && y>0 && y <n );
}

int min_dist( int ** mat, int **visited, int is,int js,int id,int jd, int i1,int j1,int m,int n)
{
      
      if( (mat[is][js] == 0) || ( mat[id][jd] == 0) )
         return 1;
      
      struct Queue * q = createqueue();
      push(&q, i1,j1,0);
      
      
      
      visited[i1][j1] = 1;
      
      while( !isempty( q) )
      {
            struct Qnode *qn = pop(&q);
            i1 = qn->pt.x;
            j1 = qn->pt.y;
            //printf( " popped  (%d,%d,%d) \n",qn->pt.x,qn->pt.y,qn->pt.dist);
            
            if( qn->pt.x == id && qn->pt.y  == jd)
                return qn->pt.dist;
            
            if( isok(i1,j1+1,m,n) && visited[i1][j1+1] == 0 && mat[i1][j1+1] == 1)
            {
                 //printf("here 1\n");
                 visited[i1][j1+1] = 1;
                 push( &q, i1, j1+1, (qn->pt.dist)+1);
            
            }
            
            if( isok(i1+1,j1,m,n) )
            {
                 //printf("here 2\n");
                 if(visited[i1+1][j1] == 0 && mat[i1+1][j1] == 1)
                 {
                 visited[i1+1][j1] = 1;
                 push( &q, i1+1, j1, (qn->pt.dist)+1);
                 }
            
            }
            
            if( isok(i1,j1-1,m,n) && visited[i1][j1-1] == 0 && mat[i1][j1-1] == 1 )
            {
                 //printf("here 3\n");
                 visited[i1][j1-1] = 1;
                 push( &q, i1, j1-1, (qn->pt.dist)+1);
            
            }
            
            if( isok(i1-1,j1,m,n) && visited[i1-1][j1] == 0 && mat[i1-1][j1] == 1 )
            {
                 //printf("here 4\n");
                 visited[i1-1][j1] = 1;
                 push( &q, i1-1, j1, (qn->pt.dist)+1);
            
            }
          
      
      }
      
      //printf("end\n");
      return -1;
      
      
    

}

int max( int a , int b,int c)
{
    if( a >= b  && a >=c  )
    {
         return a;
    
    }
    if( b >=c && b >= a)
     return b;
    return c;

}


int minofmax( int ** mat, int **visited,int id1,int jd1,int id2,int jd2,int id3, int jd3,int m,int n)
{
    int i,j,k,l,temp1,temp2,temp3,temp4,temp_min = 999999;
    
    for( i=0;i<m;i++)
     {
      for(j=0;j<n;j++)
        {
           if( mat[i][j] == 1)
           {
           for(k=0;k<m;k++)
            for(l=0;l<n;l++)
              visited[k][l] = 0;
              
           temp1 = min_dist(mat,visited,i,j,id1,jd1,i,j,m,n);
           
           
           for(k=0;k<m;k++)
            for(l=0;l<n;l++)
              visited[k][l] = 0;
              
           temp2 = min_dist(mat,visited,i,j,id2,jd2,i,j,m,n);
           
           
           for(k=0;k<m;k++)
            for(l=0;l<n;l++)
              visited[k][l] = 0;
              
           temp3 = min_dist(mat,visited,i,j,id3,jd3,i,j,m,n);
           
           
           if(temp1 != -1 && temp2 != -1 && temp3 != -1)
           {
           temp4 = max(temp1,temp2,temp3);
           //printf("i = %d j = %d  id1 = %d jd1 = %d temp1=%d  temp2=%d temp3 = %d temp4 = %d\n",i,j,id1,jd1,temp1,temp2,temp3,temp4);
           }
           if( temp4 < temp_min )
             temp_min = temp4;
           
             }
           
        }
     }
     
     
    return temp_min;

}


void printq( struct Queue * q)
{
    struct Qnode * temp = q->front;
    while( temp != NULL )
     {
        printf("%d ",temp->pt.x);
        temp = temp->next;
     }
}

int main()
{
   
     int **mat,i,j,**visited,m,n;
     
     scanf("%d %d",&m,&n);
     
     mat = ( int **) malloc( m * sizeof( int *));
     
     for(i=0;i<m;i++)
       mat[i] = ( int *) malloc ( n * sizeof( int));
       
     visited = ( int **) malloc( m * sizeof( int *));
     
     for(i=0;i<m;i++)
       visited[i] = ( int *) malloc ( n * sizeof( int));
       
       
     for(i=0;i<m;i++)
     {
        for(j=0;j<n;j++)
        {
           scanf("%d",&mat[i][j]);
           visited[i][j] = 0;
        }
     
     }
       
     
     
     int temp = minofmax(mat,visited,1,1,1,7,6,7,m,n);
     //int temp2 = min_dist(mat,visited,0,0,6,7,0,0,m,n);
     
     printf("%d\n",temp);
     //printf("%d\n",temp2);
     
     
      
      /*
      struct Queue * q = createqueue();
      push(&q,1,2,3);
      
      
      printq(q);
      pop(&q);
      
      printq(q);
      push(&q,7,8,2);
      
      printq(q);
      
     */
     

     return 0;
  
}
