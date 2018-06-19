#include <stdio.h>
#include <stdlib.h>

struct point{

    int x;
    int y;
};



void dfsmat( int **mat , int m , int n, int ** visited, int i1,int j1, int i2, int j2, int l, int k,struct point *path,int *path_index)
{
     visited[l][k] = 1;
     int i;
     path[ (*path_index) ].x = l;
     path[ (*path_index) ].y = k;
     (*path_index)++;
     if( l == i2-1 && k == j2-1 )
     {
        for( i=0;i<(*path_index);i++)
        {
            printf( " -> ( %d , %d ) ",path[i].x,path[i].y);
        }
        printf("\n");
     
     }
     
     
     
     if( mat[l][k] == 0 || l >=m || k >=n || l<0 || k < 0 )
         return;
     //printf(" -> ( i , j ) = ( %d , %d ) , path_index = %d\n",l,k,(*path_index));
     
     
     
     ///printf("before 1\n");
     if( k+1 < n && mat[l][k+1] == 1  )
     {
         if(visited[l][k+1] == 0)
         {
         //printf("here 1 (%d , %d)\n",l,k+1);
         dfsmat( mat,m,n,visited,i1,j1,i2,j2,l,k+1,path,path_index);
         }
     
     }
     //printf("before 2\n");
     if( l+1 < m && mat[l+1][k] == 1  )
     {
         //printf("here 10\n");
         if(visited[l+1][k] == 0)
         {
         //printf("here 2 (%d , %d)\n",l+1,k);
         dfsmat( mat,m,n,visited,i1,j1,i2,j2,l+1,k,path,path_index);
         }
         //printf("here 11\n");
     
     }
     //printf("before 3\n");
     if(   k-1 >=0 && mat[l][k-1] == 1)
     {
         if(visited[l][k-1] == 0)
         {
         //printf("here 3 (%d , %d)\n",l,k-1);
         dfsmat( mat,m,n,visited,i1,j1,i2,j2,l,k-1,path,path_index);
         }
     
     }
     //printf("before 4\n");
     if(  l-1 >=0 && mat[l-1][k] == 1 )
     {
         if(visited[l-1][k] == 0)
         {
         //printf("here 4 (%d , %d)\n",l-1,k);
         dfsmat( mat,m,n,visited,i1,j1,i2,j2,l-1,k,path,path_index);
         }
     
     }
     //printf("visited[%d][%d] made 0 \n",l,k);
     
     visited[l][k] = 0;
     (*path_index)--;
    

}


int main()
{
   int **mat,**visited,i,j,m,n,*path_index;
   path_index = (int *) malloc( sizeof( int));
   (*path_index) = 0;
   struct point * path;
   
   
   
   printf(" enter the value of m and n\n");
   scanf("%d %d",&m,&n);
   
   path = ( struct point *) malloc ( m * n * sizeof(struct point ));
   
   mat = (int **) malloc ( m* sizeof( int *));
   for(i=0;i<m;i++)
     mat[i] = ( int *) malloc ( n * sizeof( int ));
   
   
   visited = (int **) malloc ( m* sizeof( int *));
   for(i=0;i<m;i++)
     visited[i] = ( int *) malloc ( n * sizeof( int ));
     
   printf(" enter the values in the matrix \n");
   for(i=0;i<m;i++)
   {
       for(j=0;j<n;j++)
       {
           scanf("%d",&mat[i][j]);
       }
   
   }
   
   for(i=0;i<m;i++)
   {
       for(j=0;j<n;j++)
       {
           visited[i][j] = 0;
       }
   
   }
   
   
   
   dfsmat( mat , m,n, visited, 0,0,m-1,n-1,0,0,path,path_index);


   return 0;
}
