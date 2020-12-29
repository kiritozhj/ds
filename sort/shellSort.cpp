#include <iostream>
using namespace std;

void shellSort(int* arr,int len){
    for(int gap=len/2;gap>0;gap/=2){
        for(int i=0;i<gap;++i){
            for(int j=i+gap;j<len;j+=gap){
                if(arr[j]<arr[j-gap]){
                    int temp=arr[j],k=j-gap;
                    while(k>=0&&arr[k]>temp){
                        arr[k+gap]=arr[k];
                        k-=gap;
                    }
                    arr[k+gap]=temp;
                }
            }
        }
    }
}

void print(int* arr,int len){
    for(int i=0;i<len;++i){
        printf("%d ",arr[i]);
    }
}

int main(){
    int arr[]={10,9,8,7,6,5,4,3,2,1};
    shellSort(arr,sizeof(arr)/sizeof(arr[0]));
    print(arr,sizeof(arr)/sizeof(arr[0]));
}
