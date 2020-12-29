#include<iostream>
#include<algorithm>
using namespace std;

void moveBack(int *arr,int m,int n){
	for(int i=n;i>=m;--i){
		arr[i+1]=arr[i];
	}
}

void halfInsertSort(int *arr,int n,int data){
	if(data<=arr[0]){
		moveBack(arr,0,n-1);
		arr[0]=data;
		return;
	}else if(data>=arr[n-1]){
		arr[n]=data;
		return;
	}
	int begin=0,end=n-1,mid=(begin+end)/2;
	while(arr[mid]!=data){
		if(data>arr[mid]){
			begin=mid;
		}else{
			end=mid;
		}
		mid=(begin+end)/2;
		if((mid-begin)==1)
			break;
	}
	moveBack(arr,mid,n-1);
	arr[mid]=data;
}
void binaryInsert(int arr[],int len){
    int i,j,low,high,mid,temp;
    for(i=1;i<len;++i){
        low=0;
        high=i-1;
        temp=arr[i];
        while(low<=high){
            mid=(low+high)/2;
            if(arr[mid]>temp)
                high=mid-1;
            else
                low=mid+1;
        }
        for(j=i;j>low;--j)
            arr[j]=arr[j-1];
        arr[low]=temp;
    }
}
void prt(int a){
	cout<<a<<' ';
}

int main(){
	int arr[]={1,3,5,7,9,11,13,15};
	//halfInsertSort(arr,8,12);
    binaryInsert(arr,sizeof(arr)/sizeof(arr[0]));
	for_each(arr,arr+sizeof(arr)/sizeof(arr[0]),prt);
}
