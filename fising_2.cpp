#include<iostream>
using namespace std;

int *spots=new int[61];
int N;
int *gate=new int[4];
int *fisher=new int [4];
int ans;

void printt(int *arr,int start,int len){
	for(int i=start;i<len;i++){
		cout<<arr[i];
	}
	cout<<endl;
}

void swap(int *arr,int a,int b){
	int temp=arr[a];
	arr[a]=arr[b];
	arr[b]=temp;
}

int fillSpots(int gateno,int n){
	int distance=0;
	int j=0;
	
	for(int i=0;i<=N&&j<n;i++){
		if(spots[gateno+i]==0&&1<=gateno+i&&N>=gateno+i&&j<n){
			spots[gateno+i]=1;
			j++;
			distance+=i+1;
		}
		
		if(spots[gateno-i]==0&&1<=gateno-i&&N>=gateno-i&&j<n){
			spots[gateno-i]=1;
			j++;
			distance+=i+1;
		}
	}
	
	return distance;
}

void findDist(int *gate,int*arr,int n1,int n2,int n3,int* spots,int d){
	int *spotsss=new int[61];
	int distance;
	if(n1==0&&n2==0){
//		cout<<"111111"<<endl;
		distance=fillSpots(gate[arr[2]],n3);
		distance+=d;
//		cout<<"nxjsnksj"<<endl;
//		cout<<distance<<endl;
//		printt(spots,1,10);
		if(distance<ans) {
		   ans=distance;
//		   printt(arr,0,3);	
		}
		
	} else {
		if(n1==0){
//			cout<<d<<endl;
//			cout<<"22222"<<endl;
		   int X=1000;int Y=-1000;
		   int flag=0;
		   distance=fillSpots(gate[arr[1]],n2-1);
//		   cout<<distance<<endl;
		    for(int i=gate[arr[1]];i<=N;i++){
		   	    if(spots[i]==0) {
				   if(flag==0){
				   	X=i;
				    flag=1;
				   }     
			    }
		    }
		    
		    flag=0;
		    for(int j=gate[arr[1]];j>=1;j--){
		    	if(spots[j]==0){
		    		if(flag==0){
		    			Y=j;
		    		    flag=1;
					}
				}
			}
			
//			cout<<X<<"  "<<Y<<endl;
			
			if(X-gate[arr[1]]<gate[arr[1]]-Y){
				
//				cout<<"11111"<<endl;
				spots[X]=1;
				findDist(gate,arr,0,0,n3,spots,d+distance+X-gate[arr[1]]+1);
			}else{
			    if(X-gate[arr[1]]>gate[arr[1]]-Y){
//			    	cout<<"22222"<<endl;
					spots[Y]=1;
				    findDist(gate,arr,0,0,n3,spots,d+distance+gate[arr[1]]-Y+1);
			    }else{
//			    	cout<<"22222"<<endl;
			    	for(int i=0;i<61;i++) spotsss[i]=spots[i];
			    	spots[X]=1;
					findDist(gate,arr,0,0,n3,spots,d+distance+X-gate[arr[1]]+1);
					for(int i=0;i<61;i++) spots[i]=spotsss[i];
					spots[Y]=1;
				    findDist(gate,arr,0,0,n3,spots,d+distance+gate[arr[1]]-Y+1);
				}
			}
		
		}else{
//			cout<<n1<<" "<<n2<<" "<<n3<<endl;
//			cout<<"33333"<<endl;
//			cout<<gate[arr[0]]<<"     "<<n1-1<<"  "<<arr[0]<<endl;
			distance=fillSpots(gate[arr[0]],n1-1);
//			cout<<distance<<endl;
			
			int X=1000;int Y=-1000;
			int flag=0;
			
			for(int i=gate[arr[0]];i<=N;i++){
		   	    if(spots[i]==0) {
				  if(flag==0){
				   X=i;
				   flag=1;    
			    }}
		    }
		    flag=0;
		    for(int j=gate[arr[0]];j>=1;j--){
		    	if(spots[j]==0){
		    	 if(flag==0){
				   Y=j;
				   flag=1;    
				}}
			}
			
//			cout<<X<<" "<<Y<<endl;
			if(X-gate[arr[0]]<gate[arr[0]]-Y){
//				cout<<"  111"<<endl;
				spots[X]=1;
				findDist(gate,arr,0,n2,n3,spots,d+distance+X-gate[arr[0]]+1);
			}else{
			    if(X-gate[arr[0]]>gate[arr[0]]-Y){
//					cout<<"  222"<<endl;
					spots[Y]=1;
				    findDist(gate,arr,0,n2,n3,spots,d+distance+gate[arr[0]]-Y+1);
			    }else{
//			    	cout<<"  333"<<endl;
			    	for(int i=0;i<61;i++) spotsss[i]=spots[i];
			    	spots[X]=1;
					findDist(gate,arr,0,n2,n3,spots,d+distance+X-gate[arr[0]]+1);
					for(int i=0;i<61;i++) spots[i]=spotsss[i];
					spots[Y]=1;
				    findDist(gate,arr,0,n2,n3,spots,d+distance+gate[arr[0]]-Y+1);
				}
			}
		}
	}

}

void permute(int *arr,int start,int len){
	if(start==len){
//		printt(arr,0,len);
        for(int j=0;j<61;j++){
		spots[j]=0;
    	}
        findDist(gate,arr,fisher[arr[0]],fisher[arr[1]],fisher[arr[2]],spots,0);
	}else{
		for(int i=start;i<len;i++){
			swap(arr,start,i);
			permute(arr,start+1,len);
			swap(arr,start,i);
		}
	}
}

int main(){
	int testcase;
	cin>>testcase;
	int *arr=new int[3];
	
	while(testcase--){
		
		for(int j=0;j<61;j++){
		if(j<3) arr[j]=j+1;
		spots[j]=0;
    	}
    	
		cin>>N>>gate[1]>>gate[2]>>gate[3]>>fisher[1]>>fisher[2]>>fisher[3];
		
		for(int i=0;i<61;i++){
			spots[i]=0;
		}
		
		ans=3600;
//		printt(arr,0,3);
		permute(arr,0,3);
//        arr[0]=1;
//        arr[1]=3;
//        arr[2]=2;
//        findDist(gate,arr,fisher[arr[0]],fisher[arr[1]],fisher[arr[2]],spots,0);

		 cout<<ans;
	}
}

