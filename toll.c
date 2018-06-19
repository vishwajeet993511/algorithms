#include <stdio.h>
#include <stdlib.h>



void dfs(int *tmen, int *tc,int n, int i1,int bp3, int bp2, int bp1,int currcost, int *res)
{
    if( currcost > (*res) )
      return;
    //printf("bp3+bp2+bp1 = %d  tmen[i1] = %d currcost = %d  i1 = %d\n",bp3+bp2+bp1,tmen[i1],currcost,i1);
    if( i1 >= n-1 )
    {
       if( bp3 + bp2 + bp1 < tmen[i1] )
         currcost += tc[i1];
       if( currcost < (*res) )
         (*res) = currcost;
       return;   
    }
    
    if( (*res) > currcost + tc[i1])
    dfs(tmen,tc,n,i1+1,bp3,bp2,bp1,currcost + tc[i1] , res);
    
    if( (*res) > currcost + 2* tc[i1])
    dfs(tmen,tc,n,i1+1,bp3+tmen[i1] ,bp2,bp1,currcost + 2* tc[i1],res);
    
    if( bp3 + bp2 + bp1 >= tmen[i1] )
    {
         if( bp2 + bp1 < tmen[i1] && i1+1 < n)
         {
             dfs(tmen,tc,n,i1+1,0, bp3 - (tmen[i1] - bp1 - bp2) , 0,currcost,res);
         
         }
         
         else if( bp1 < tmen[i1] && i1+1 < n)
         { 
           
            dfs(tmen,tc,n,i1+1,0,bp3,bp2-(tmen[i1]-bp1),currcost,res);
         
         }
         
         else
         {
            if( i1+1 < n)
            dfs(tmen,tc,n,i1+1,0, bp3,bp2,currcost,res);
         }
         
        
         //if( tmen[i1] > bp2+bp1 ) bp3 = (bp3+bp2+bp1 -tmen[i1]);
         //if(tmen[i1] > bp1 ) bp2 = tmen[i1]- bp1 >= bp2 ? 0 : bp2-tmen[i1]+bp1;
    
         //dfs(tmen,tc,n,i1+1,0,bp3,bp2,currcost,res);
    }



}

int main()
{
     int *tmen,*tc,n,i,j,*res,currcost=0;
     printf("enter n\n");
     scanf("%d",&n);
     
     res = ( int *) malloc ( sizeof( int));
     (*res) = 9999999;
     tmen = ( int *) malloc ( n * sizeof( int));
     tc = ( int *)  malloc ( n* sizeof( int));
     
     for(i=0;i<n;i++)
     scanf("%d", &tmen[i]);
     
     for(i=0;i<n;i++)
     scanf("%d", &tc[i]);
     
     dfs(tmen,tc,n,0,0,0,0,0,res);
     
     printf("%d \n",(*res));


    return 0;
}
