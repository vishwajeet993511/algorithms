#include<stdio.h>
#include<stdlib.h>

int temp = 30000;

int swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(int *a,int l,int r,int n,int **mat)
{
    //int n = sizeof(a)/sizeof(int);
    int i,temp1;
    if( l == r)
    {
        temp1 = 0;
        for(i=0;i<n-1;i++)
        {
           printf("%d -> ",a[i]);
           temp1 += mat[a[i]][a[i+1]];    
        
        }
        printf("%d -> 0",a[n-1]);
        temp1 += mat[a[n-1]][a[0]];
        
        if( temp > temp1 )
          temp = temp1;
          
        printf("  tmep1 = %d\n",temp1);
        printf("\n");
    }
    for( i=l;i<=r;i++)
    {
    
        swap(&a[l],&a[i]);
        permute(a,l+1,r,n,mat);
        swap(&a[l],&a[i]);   
    
    }

}

int main()
{
  
  int n,i,j;
  printf("enter n \n");
  scanf("%d",&n);
  int arr[n];
  int **mat =  (int **) malloc(sizeof(int *) * n);
  for( i = 0;i <n;i++)
  {
     mat[i] = (int *) malloc (sizeof(int) * n);
  }
  
  for(i=0;i<n;i++)
    arr[i] = i;
    
  printf("enter the matrix \n ");
  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
       scanf("%d",&mat[i][j]);
   
  permute(arr,0,n-1,n,mat);
  
  printf("cost = %d\n",temp);

  return 0;
}
