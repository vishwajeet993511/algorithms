#include <stdio.h>
#include <stdlib.h>

int check( int i1,int j1,int m,int n)
{
    return ( i1 >=0 && i1 < m && j1>=0 && j1 < n);

}


void dfs4( int ** mat, int m, int n, int ist,int jst,int i1,int j1,int **visited , int *res1,int *pntr,int *path )
{
    int i,sum=0;
    //printf("here 0\n");
    visited[i1][j1] = 1;
    path[(*pntr)++] = mat[i1][j1];
    
    if( (*pntr) > 3 )
    {
      sum = 0;
      //printf("here 1 \n");
       for( i = 0; i< (*pntr);i++)
      // printf("%d ",path[i]);
       //printf("\n");
       sum += path[i];
       if( (*res1) < sum *sum)
       (*res1) = sum*sum;
       
     
    }
    
    
    
    if( j1 % 2 != 0)
    {
        
        if(check( i1-1,j1,m,n) && visited[i1-1][j1] ==0 && (*pntr) <=3 )
        {
         dfs4( mat,m, n,ist,jst, i1-1,j1,visited , res1,pntr,path );
        }
        
        if(check( i1,j1-1,m,n) && visited[i1][j1-1] ==0  && (*pntr) <=3)
        {
        dfs4( mat,m, n,ist,jst, i1,j1-1,visited , res1,pntr,path );
        }
        
        if(check( i1,j1+1,m,n) && visited[i1][j1+1] ==0  && (*pntr) <=3)
        {
        dfs4( mat,m, n,ist,jst, i1,j1+1,visited , res1,pntr,path );
        }
        
        if(check( i1+1,j1-1,m,n) && visited[i1+1][j1-1] ==0  && (*pntr) <=3)
        {
        dfs4( mat,m, n,ist,jst, i1+1,j1-1,visited , res1,pntr,path );
        }
        
        if(check( i1+1,j1,m,n) && visited[i1+1][j1] ==0  && (*pntr) <=3)
        {
        dfs4( mat,m, n,ist,jst, i1+1,j1,visited , res1,pntr,path );
        }
        
        if(check( i1+1,j1+1,m,n) && visited[i1+1][j1+1] ==0 && (*pntr) <=3 )
        {
        dfs4( mat,m, n,ist,jst, i1+1,j1+1,visited , res1,pntr,path );
        }
        
    }
    else
    {
        //printf( " i1  = %d , j1 = %d ,mat = %d pntr= %d\n",i1,j1,mat[i1][j1],(*pntr));
        if(check( i1-1,j1-1,m,n) && visited[i1-1][j1-1] ==0  && (*pntr) <=3)
        {
        dfs4( mat,m, n,ist,jst, i1-1,j1-1,visited , res1,pntr,path );
        }
        if(check( i1-1,j1,m,n) && visited[i1-1][j1] ==0 && (*pntr) <=3 )
        {
        dfs4( mat,m, n,ist,jst, i1-1,j1,visited , res1,pntr,path );
        }
        
        if(check( i1-1,j1+1,m,n) && visited[i1-1][j1+1] ==0  && (*pntr) <=3)
        {
        dfs4( mat,m, n,ist,jst, i1-1,j1+1,visited , res1,pntr,path);
        }
        
        if(check( i1,j1-1,m,n) && visited[i1][j1-1] ==0 && (*pntr) <=3 )
        {
        dfs4( mat,m, n,ist,jst, i1,j1-1,visited , res1,pntr ,path);
        }
        
        if(check( i1,j1+1,m,n) && visited[i1][j1+1] ==0 && (*pntr) <=3 )
        {
        dfs4( mat,m, n,ist,jst, i1,j1+1,visited , res1,pntr,path );
        }
        
        if(check( i1+1,j1,m,n) && visited[i1+1][j1] ==0 && (*pntr) <=3 )
        {
        dfs4( mat,m, n,ist,jst, i1+1,j1,visited , res1,pntr ,path);
        }
    }
     
    visited[i1][j1] = 0;
    (*pntr)--;


}


void costy( int ** mat, int m, int n,int i1,int j1, int *res2)
{

     int sum1=mat[i1][j1],sum2 =mat[i1][j1] ;
     if( j1 % 2 != 0)
     {
        
        if(check( i1-1,j1,m,n) )
        {
            sum1 += mat[ i1-1][j1];
        }
        
        
        if(check( i1+1,j1-1,m,n))
        {
        sum1 += mat[ i1+1][j1-1];
        }
        
       
        
        if(check( i1+1,j1+1,m,n)  )
        {
        sum1 += mat[ i1+1][j1+1];
        }
        
        
        
        
        if(check( i1,j1-1,m,n) )
        {
            sum2 += mat[ i1][j1-1];
        }
        
        
        if(check( i1,j1+1,m,n))
        {
        sum2 += mat[ i1][j1+1];
        }
        
       
        
        if(check( i1+1,j1,m,n)  )
        {
        sum2 += mat[ i1+1][j1];
        }
        
        if( sum1 > sum2 )
          (*res2) = sum1;
        else (*res2) = sum2;
        
    }
    else
    {
        if(check( i1-1,j1-1,m,n) )
        {
            sum1 += mat[ i1-1][j1-1];
        }
        
        
        if(check( i1-1,j1+1,m,n))
        {
        sum1 += mat[ i1-1][j1+1];
        }
        
       
        
        if(check( i1+1,j1,m,n)  )
        {
        sum1 += mat[ i1+1][j1];
        }
        
        
        
        
        if(check( i1,j1-1,m,n) )
        {
            sum2 += mat[ i1][j1-1];
        }
        
        
        if(check( i1,j1+1,m,n))
        {
        sum2 += mat[ i1][j1+1];
        }
        
       
        
        if(check( i1-1,j1,m,n)  )
        {
        sum2 += mat[ i1-1][j1];
        }
        
        if( sum1 > sum2 )
          (*res2) = sum1*sum1;
        else (*res2) = sum2*sum2;
    }

}

int cost( int ** mat, int m, int n,int **visited)
{
     int i,j;
     int *path,*pntr;
     int *res1,*res2;
     res1 = ( int *) malloc ( sizeof( int ));
     res2 = ( int *) malloc ( sizeof ( int ));
     int cost  = 0;
     pntr = ( int *) malloc ( sizeof( int ));
     
     for( i=0;i<m;i++)
     {
       for(j=0;j<n;j++)
       {
           (*pntr) = 0;
           (*res1) = 0;
           (*res2) = 0;
           path = ( int * ) malloc ( 4 * sizeof ( int ));
           dfs4(mat,m,n,0,0,i,j,visited,res1,pntr,path);
           
           costy(mat,m,n,i,j,res2);
           
           if( cost < (*res1))
            cost = (*res1);
           if(cost < (*res2))
            cost = (*res2);
       
       }
     
     }
     
     
      return cost;
   

}



int main()
{
  int m,n,i,j;
  printf(" enter m and n\n");
  scanf("%d %d",&m,&n);
  int **mat,**visited;
  mat = ( int ** ) malloc ( m * sizeof( int *));
  for(i=0;i<m;i++)
    mat[i] = ( int *) malloc ( n * sizeof( int));
    
  
  visited = ( int ** ) malloc ( m * sizeof( int *));
  for(i=0;i<m;i++)
    visited[i] = ( int *) malloc ( n * sizeof( int));
  printf(" enter elements\n");
  for(i=0;i<m;i++)
  {
     for(j=0;j<n;j++)
     {
        scanf("%d",&mat[i][j]);
        visited[i][j] = 0;
        
     }
  
  }
  printf("\n\n");
  int cost1 = cost(mat,m,n,visited);
  printf("%d \n",cost1);
  //costy();

  return 0;
 
}
