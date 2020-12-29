#include<iostream>
using namespace std;

void selectSort(int arr[],int n){
	for(int i=0;i<n;++i){
		int min=i;
		for(int j=i+1;j<n;++j){
			if(arr[j]<arr[min])
				min=j;
		}
		int temp=arr[i];
		arr[i]=arr[min];
		arr[min]=temp;
	}
}

int main(){
	int arr[]={6,5,4,3,2,1};
	selectSort(arr,sizeof(arr)/sizeof(arr[0]));
	for(auto i=begin(arr);i!=end(arr);++i)
		printf("%d ",*i);
}
