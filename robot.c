#include <stdio.h>
#include <stdlib.h>

int max_steps = 100000;
int count = 0;
void cost( int *arr, int * visited ,int n, int remfl1, int remfl2, int i1, int *res, int gcars, int dcars,int steps)
{
      
       int j;
       if( count < 10 ){ count++;
       printf("(*res) = %d i1 = %d  gcars = %d dcars = %d steps = %d\n",    (*res),i1,gcars,dcars,steps);
       }
       if( i1 > n+1 || i1 < 0)
       {
         return;
       }
        
        //printf("here 2\n");
        
       if( gcars == 0 && dcars == 0)
       {
           if( steps < max_steps )
             max_steps = steps;
           
           if( steps < ( *res))
           {
              printf("here in the end\n");
              (*res) = steps;
              
              printf("%d ",(*res));
           }
           return;
       
       }
       //printf("here 3\n");
       
       ///////////////////////////////////////////////////////////////////////////////////////
       if( i1 == 0 )
       { 
           if( gcars == 0)
           {
              
              remfl1 = 0;
              cost( arr,visited,n,remfl1,remfl2,n+1,res,gcars,dcars,steps+n+1-i1);
              return;
           }
           //printf("here 3.5\n");
           remfl1 = 2;
           remfl2 = 0;
           
           for(j=1;j<=n;j++)
           {
               if( arr[j] == 1 && visited[j] == 0)
               {
               visited[j] = 1;
               //if( gcars -1 == 0 )
               //printf("fuelled %d  steps = %d  gcars = %d\n",j,steps+j,gcars-1);
               cost(arr,visited,n,remfl1-1,remfl2,j,res,gcars-1,dcars,steps+j);
               visited[j] = 0;
               }   
           
           }       
       
       }
       
       else if( i1 == n+1)
       {
           if( dcars == 0)
           {
              remfl2 = 0;
              cost( arr,visited,n,remfl1,remfl2,n+1,res,gcars,dcars,steps+n+1-i1);
              return;
           }
           remfl1 = 0;
           remfl2 = 2;
           
           for(j=n;j>=1;j--)
           {
               //printf("here 4\n");
               if( arr[j] == 2 && visited[j] == 0)
               {
               visited[j] = 1;
               //if( dcars-1 ==0 )
               //printf("fuelled %d  steps = %d  dcars = %d\n",j,steps+n-j+1,dcars-1);
               cost(arr,visited,n,remfl1,remfl2-1,j,res,gcars,dcars-1,steps+n-j+1);
               visited[j] = 0;
               }   
           
           }    
       
       }
       
       else if( remfl1 <= 0 && remfl2 <= 0)
       {
           if( dcars > 0 )
             cost( arr,visited,n,remfl1,remfl2,n+1,res,gcars,dcars,steps+n+1-i1);
             
             
           if( gcars > 0 )
             cost( arr,visited,n,remfl1,remfl2,0,res,gcars,dcars,steps+i1);
       
       }
       
       ////////////////////////////////////////////////////////////////////////////////////////////////////
       
       else
       {
       
       if( arr[i1] == 1 && remfl1)
       {
               for( j = i1+1;j<=n;j++)
               {
		       if( arr[j] == 1 && visited[j] == 0)
		       {
		         visited[j] = 1;
		         //printf("fuelled %d\n",j);
		         cost(arr,visited,n,remfl1-1,remfl2,j,res,gcars-1,dcars,steps+j-i1);
		         visited[j] = 0;
		       }
               }
               
               
               if( dcars > 0 )
                 cost( arr,visited,n,remfl1,remfl2-1,n+1,res,gcars,dcars,steps+n+1-i1);
               
               
               if( gcars > 0 )
                 cost( arr,visited,n,remfl1-1,remfl2,0,res,gcars,dcars,steps+i1);
               
       
       }
       
       /*
       if( arr[i1] == 2 && remfl1)
       {
               cost( arr,visited,n,remfl1,remfl2,i1+1,res,gcars,dcars,steps+1);
       
       }
       */
       
       if( arr[i1] == 2 && remfl2)
       {
             for( j = i1-1;j>0;j--)
               {
		       if( arr[j] == 2 && visited[j] == 0)
		       {
		         visited[j] = 1;
		         //printf("fuelled %d\n",j);
		         cost(arr,visited,n,remfl1,remfl2-1,j,res,gcars,dcars-1,steps+i1-j);
		         visited[j] = 0;
		       }
               }
               
               
               if( dcars > 0 )
                 cost( arr,visited,n,remfl1,remfl2-1,n+1,res,gcars,dcars,steps+n+1-i1);
               
               
               if( gcars > 0 )
                 cost( arr,visited,n,remfl1-1,remfl2,0,res,gcars,dcars,steps+i1);
       
       }
       
       }
       
       /*
       if( arr[i1] == 1 && remfl2)
       {
         
               cost( arr,visited,n,remfl1,remfl2,i1-1,res,gcars,dcars,steps+1);
          
       
       }
       */
          
       //printf("here 5\n");

}


int main()
{
  int *arr,*visited,i,j,n,*res,gcars,dcars,t;
  scanf("%d",&t);
  
  while(t--)
  {
      gcars = 0;
      dcars = 0;
      
      arr = ( int *) malloc ( (n+2) * sizeof ( int));
      visited = ( int *) malloc ( (n+2)* sizeof( int));
      res = ( int * ) malloc ( sizeof( int));
      (*res) = 99999;
      printf("%d \n",(*res));
      scanf("%d",&n);
      arr[0] = -1;
      arr[n+1] = -1;
      ///printf("%d \n",(*res));
      for(i=1;i<=n;i++)
      {
         scanf("%d",&arr[i]);
         
         visited[i] = 0;
         if( arr[i] == 1)
           gcars++;
         if( arr[i] == 2)
           dcars++;
          //printf("%d \n",(*res));
          
      }
      //return 0;
      printf("%d \n",(*res));
      printf("%d %d\n",gcars,dcars);
      printf("%d \n",(*res));
      cost( arr,visited,n,0,0,0,res,gcars,dcars,0);
      
      //printf("%d\n", (* res));
      printf("%d\n", max_steps);
      
      
  }
  return 0;
}
