#include<iostream>
using namespace std;
void directInsertSort(int arr[],int len){
    int i,j,temp;
    for(i=1;i<len;++i){
        temp=arr[i];
        for(j=i;temp<arr[j-1]&&j>0;--j)
            arr[j]=arr[j-1];
        arr[j]=temp;
    }
}
void print(int arr[],int len){
    for(int i=0;i<len;++i)
        cout<<arr[i]<<' ';
}
int main(){
    int arr[]={9,8,6,7,7,0,5,4,3,2,1};
    directInsertSort(arr,sizeof(arr)/sizeof(arr[0]));
    print(arr,sizeof(arr)/sizeof(arr[0]));
}
