#include <stdio.h>
#include <stdlib.h>

int count_ip = 0;
void swap(int *a,int *b)
{
   int temp = *a;
   *a = *b;
   *b = temp;

}

// - - - . - - - . - - - .- - -   ,,,,,,  -.-.-.-

char *substr(char temp[],int start, int end,int n)
{
   //printf("enter4 \n");
   int i,c=0;
   //printf(" 4 here1\n");
   char *sub1 = (char *) malloc( ( end  - start + 1) * sizeof(char));
   //printf(" 4 here2\n");
   for(i=start ; i <= end ; i++)
   {
      //printf(" 4 here3 i = %d   start = %d  end = %d\n",i,start,end);
      sub1[c++] = temp[i];
   }
   
   //printf("exit4 \n");
   return sub1;

  
}


int validate( char temp[],int n)
{
  
  //printf("enter3 \n");
  //printf("in 3 string = %s\n",temp);
  int x=0,i;
  
  if( n >1)
  {
    //printf(" 3 here1\n");
    if( temp[0] == '0')
      return 0;
  
  }
  //sscanf(temp,"%d", &x);
  for(i=0; i<n; i++)
   {
	x = x * 10 + ( temp[i] - '0' );
   }
  //printf("3 here 2 \n");
  //printf("x=  %d \n", x);
  if( x > 255 )
  {
    //printf(" 3 here3\n");
    return 0;
  
  }
  
  //printf("exit3 \n");
  return 1;

  
}

void validate_ip(char *temp,int n)
{
  //printf("enter2 \n");
  //printf("1 in temp   = %s , n = %d \n",temp,n);
  int i,dots[3],c=0,v1,v2,v3,v4;
  char *char1,*char2,*char3,*char4;
  for(i=0;i<n;i++)
  {
     //printf("dot[i] = %d  n= %d\n",i,n);
     if( temp[i] == '.')
     {
       //printf("dot[i] = %d\n",i);
       dots[c++] = i;
     
     }
     
  }
     //printf("dots -1 = %d  n = %d\n",dots[0]-1,n);
     char1 = substr(temp,0,dots[0]-1,n);
     //printf("in 2 char1  = %s\n",char1);
     v1 = validate( char1 , dots[0]  );
     
     char2 = substr(temp,dots[0]+1,dots[1]-1,n);
     //printf("in 2 char2  = %s\n",char2);
     v2 = validate( char2 , dots[1] - dots[0] - 1);
     
     char3 = substr(temp,dots[1]+1,dots[2]-1,n);
     //printf("in 2 char3  = %s\n",char3);
     v3 = validate( char3 , dots[2] - dots[1] -1 );
     
     char4 = substr(temp,dots[2]+1,n-1,n);
     //printf("in 2 char4  = %s\n",char4);
     v4 = validate( char4 , n - dots[2] - 1);
     
     //printf(" at the last stage \n");
     //printf("%d %d %d %d\n",v1,v2,v3,v4);
     if( v1 && v2 && v3 && v4)
      {
       //printf("%s\n",temp);
       count_ip++;
       printf("%d  ",count_ip);
      }
  
  
    //printf("exit2 \n");
  
  } 
  


void calculate_ip(char *temp,int n)
{
   //printf("enter1 \n");
   int i,j,k,c1=0,c2=0,i1;
   char *temp2;
   temp2 = (char *) malloc( (n+3) * sizeof(char));
   
   for(i=1;i<=3,i<n-2;i++)
    {
        //printf("here 1\n");
        for(j=i+2;j<8,j<n;j++)
        {
            //printf("here 2 i= %d  j = %d \n",i,j);
            for(k = j+2;k <12,k<n+2;k++)
            {
               for(i1=0;i1<n+3;i1++)
	       {
		      temp2[i1] = '0';
	       }
	       c2=0;
               //printf("here 3 i=%d j=%d k=%d\n",i,j,k);
               temp2[i] = '.';
               temp2[j] = '.';
               temp2[k] = '.';
               for( c1=0;c1<n+3;c1++)
               {
                  if( c1 != i && c1 != j && c1 != k)
                     temp2[c1] = temp[c2++];
               
               
               }
               
               
               //printf("hello\n");
               //printf("%s\n",temp2);
               validate_ip(temp2, n+3);
               
               
            
            
            }
        
        
        }
    
    
    }
   

     //printf("exit1 \n");
}

void permute(int arr[],int start,int end,int n,int k)
{

   int i,j,noval;
   char *temp;
   char *temp2;
   //char temp[ 2* n ];
   //data = (int *) malloc( n * sizeof(int));
   if(k==0)
   {
	   temp = (char *) malloc( 2*n * sizeof(char));
	   //printf(" n = %d \n",n);
	   if( start == end)
	   {
	      for(i=0;i<n;i++)
	      {
		//printf("%d  ",arr[i]);
		temp[i] = arr[i] + '0';
		temp[2*n - i -1] = arr[i] + '0';
		
	       }
		//printf("%s\n",temp);
		//printf("%s\n", substr(temp,0,1,2*n) );
		calculate_ip( temp,2*n);
		//*ip_count += noval;
		printf("\n");
	   
	   }
	   
	   for(i=start;i<=end;i++)
	   {
	     swap(&arr[i],&arr[start]);
	     permute(arr,start+1,end,n,k);
	     swap(&arr[i],&arr[start]);
	   }
  }
  else
  {
           temp2 = (char *) malloc( (2*n -1) * sizeof(char));
	   //printf(" n = %d \n",n);
	   if( start == end)
	   {
	      for(i=0;i<n-1;i++)
	      {
		//printf("%d  i= %d 2n-1-i-1 = %d\n",arr[i],i,2*n-i-2);
		temp2[i] = arr[i] + '0';
		temp2[n-1] = arr[n-1] + '0' ;
		temp2[2*n-1 - i -1] = arr[i] + '0';
		
	       }
		//printf("%s\n",temp2);
		//printf("%s\n", substr(temp,0,1,2*n) );
		calculate_ip( temp2,2*n - 1);
		//*ip_count += noval;
		printf("\n");
	   
	   }
	   
	   for(i=start;i<=end;i++)
	   {
	     swap(&arr[i],&arr[start]);
	     permute(arr,start+1,end,n,k);
	     swap(&arr[i],&arr[start]);
	   }
  
       
  }


}

int main()
{
  int n,i,j,k;
  int *arr;
  int *temp1;
  int *count;
  printf("enter n\n");
  scanf("%d",&n);
  int *data = (int *) malloc( n * sizeof(int));
  temp1 = (int *) malloc( n * sizeof(int));
  printf("enter the n elements \n");
  arr = (int *) malloc( n * sizeof(int));
  for(i=0;i<n;i++)
  {
  
     scanf("%d",&arr[i]);
  
  }
  
  permute(arr,0,n-1,n,0);

  for(i=0;i<n;i++)
  {
     for(j=0;j<n;j++)
     {
     temp1[j] = arr[j];
    
     }
     swap( &temp1[i],&temp1[n-1]);
     permute(temp1,0,n-2,n,1);
  
  }
  
  


  return 0;
}
