#include <stdio.h>
#include <stdlib.h>


void nstars(int **mat, int n, int * c1,int i1,int j1,int **visited)
{
   int i,j;
   if( i1 >=n || j1 >=n )
    return;
    
   
	if( visited[i1][j1] == 0 )
	{

		visited[i1][j1] = 1;
	        printf(" index = ( %d , %d ),  mat = %d\n",i1,j1 , mat[i1][j1]);
		if(mat[i1][j1] == 1)
		{
		   (*c1) +=1;
		   //printf("c1 in function %d \n", (*c1));
		   if( i1+1 < n && mat[i1+1][j1] == 1 && visited[i1+1][j1] == 0)
		    nstars(mat,n,c1,i1+1,j1,visited);
		   if( j1+1 < n  && mat[i1][j1+1] == 1 && visited[i1][j1+1] == 0)
		    nstars(mat,n,c1,i1,j1+1,visited);
		   if( i1-1 > 0 && mat[i1-1][j1] == 1 && visited[i1-1][j1] == 0)
		    nstars(mat,n,c1,i1-1,j1,visited);
		   if( j1 - 1 > 0 && mat[i1][j1-1] == 1 && visited[i1][j1-1] == 0)
		    nstars(mat,n,c1,i1,j1-1,visited);
		}
		else return;

	}
	else return;
       
      


}

int nconstel(int **mat,int n,int *c1,int *c2,int **visited)
{
   int i,j,temp =0;
   for(i=0;i<n;i++)
   {
     for(j=0;j<n;j++)
     {
        if( mat[i][j] == 1 && visited[i][j] ==0)
        {
           (*c2) += 1;
           //printf(" index = ( %d , %d )\n",i,j);
           (*c1) = 0;
           nstars(mat,n,c1,i,j,visited);
           if( temp < (*c1) )
              temp = (*c1);
        
        }
     }
   
   }
   
   return temp;
  

}

int main()
{
   int **mat,i,n,j,*c1,*c2,**visited,temp;
   c1 = (int *) malloc(sizeof(int));
   c2 = (int *) malloc(sizeof(int));
   
   
   
   printf("enter n\n");
   scanf("%d",&n);
   
   mat = (int **) malloc( n * sizeof(int *));
   for(i=0;i<n;i++)
    mat[i] = (int *) malloc (n * sizeof (int ));
    
   visited = (int **) malloc( n * sizeof(int *));
   for(i=0;i<n;i++)
     visited[i] = (int *) malloc (n * sizeof (int ));
   
   printf("enter the values of matrix\n");
   for(i=0;i<n;i++)
   {
      for(j=0;j<n;j++)
      {
         scanf("%d",&mat[i][j]);
        
      }
   }
   for(i=0;i<n;i++)
   {
      for(j=0;j<n;j++)
      {
         visited[i][j] = 0;
        
      }
   }
   (*c1) = 0;
   (*c2) = 0;
   temp = nconstel(mat,n,c1,c2,visited);
   
   printf("count = %d, max = %d\n", *c2,temp);

   return 0;
}
