#include<iostream>
#include<algorithm>
using namespace std;
void bubbleSort(int arr[],int n)
{
	int i,j,flag;
	for(i=n-1;i>=1;--i)
	{
		flag=0;
		for(j=1;j<=i;++j)
			if(arr[j-1]>arr[j]){
                swap(arr[j],arr[j-1]);
				flag=1;
			}
		if(flag==0) return;
	}
}

void print(int* arr,int n){
    for(int i=0;i<n;++i)
        printf("%d ",arr[i]);
}

int main(){
	int arr[]={1,3,2,5,4,2};
	bubbleSort(arr,sizeof(arr)/sizeof(arr[0]));
    print(arr,sizeof(arr)/sizeof(arr[0]));
}
