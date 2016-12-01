#include<bits/stdc++.h>
using namespace std;


void insertionsort(int *a,int n)
{
   int temp,i,j;
   for(i=1;i<n;i++)
   {
     temp = a[i];
     j= i-1;
     while(temp < a[j] && j >=0)
     {
      a[j+1]= a[j];
      j--;
     }
     a[j+1]= temp;
   }

}

int main()
{
  int i,j,temp,n;
  printf("enter n\n");
  scanf("%d",&n);

  int *a;
  a = new int[n];

  for(i=0;i<n;i++)
  scanf("%d",&a[i]);
  printf("\n");
  for(i=0;i<n;i++)
  printf("%d    ",a[i]);
  printf("\n");
  printf("\n");
  insertionsort(a,n);

  for(i=0;i<n;i++)
  printf("%d   ",a[i]);



}
