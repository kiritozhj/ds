#include <iostream>
using namespace std;

void merge(int* arr,int first,int mid,int last,int* temp){
    int i=first,j=mid+1;
    int m=mid,n=last;
    int k=0;

    while(i<=m && j<=n){
        if(arr[i]<=arr[j])
            temp[k++]=arr[i++];
        else
            temp[k++]=arr[j++];
    }
    while(i<=m)
        temp[k++]=arr[i++];
    while(j<=n)
        temp[k++]=arr[j++];
    for(i=0;i<k;++i)
        arr[first+i]=temp[i];

}

void mergeSort(int* arr,int first,int last,int* temp){
    if(first<last){
        int mid=(first+last)/2;
        mergeSort(arr,first,mid,temp);
        mergeSort(arr,mid+1,last,temp);
        merge(arr,first,mid,last,temp);
    }
}

bool mergeSort(int* arr,int len){
    int* p=new int[len];
    if(p==nullptr) return false;
    mergeSort(arr,0,len-1,p);
    delete[] p;
    return false;
}

void print(int* arr,int len){
    for(int i=0;i<len;++i){
        printf("%d ",arr[i]);
    }
}

int main(){
    int arr[]={10,9,8,7,6,5,4,3,2,1};
    mergeSort(arr,sizeof(arr)/sizeof(arr[0]));
    print(arr,sizeof(arr)/sizeof(arr[0]));
}
