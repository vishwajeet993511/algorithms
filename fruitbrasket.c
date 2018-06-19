#include <stdio.h>
#include <stdlib.h>


void fb(int *arr,int n,int *count,int *data1,int *data2,int *data3,int index,int i1,int i2,int i3)
{
   int k,l,xor1=0,xor2=0;
   if( index >=n )
      return;
   if(index ==n )
   {
      xor1=0;xor2=0;
      for(k=0;k<i1;k++)
      {
         xor1 ^= data1[k];
      
      }
      for(k=0;k<i2;k++)
      {
         xor2 ^= data2[k];
      
      }
      if( xor1 == xor2)
      {
         ++(*count); 
      }  
      
      return;
   }
   
   data1[i1] = arr[index];
   fb(arr,n,count,data1,data2,data3,index+1,i1+1,i2,i3);
   
   data2[i2] = arr[index];
   fb(arr,n,count,data1,data2,data3,index+1,i1,i2+1,i3);
   
   data3[i3] = arr[index];
   fb(arr,n,count,data1,data2,data3,index+1,i1,i2,i3+1);
   

}


int main()
{
  int n;
  int i=0;
  printf("enter n\n");
  scanf("%d",&n);
  printf("enter the n elements\n");
  
  
  int *arr,*data1,*data2,*data3;
  arr = (int *) malloc ( n * sizeof(int));
  data1 = (int *) malloc ( n * sizeof(int));
  data2 = (int *) malloc ( n * sizeof(int));
  data3 = (int *) malloc ( n * sizeof(int));
  
  int k=0;
  for(k=0;k<n;k++)
  {
    scanf("%d",&arr[k]);
   
  }
  int *count;
  count = (int *)malloc (sizeof(int));
  
  
  fb(arr,n,count,data1,data2,data3,0,0,0,0);
  
  printf("%d ",(*count));
  
  




  return 0;
}
