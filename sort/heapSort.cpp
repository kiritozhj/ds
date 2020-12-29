#include <iostream>
using namespace std;

void sift(int* arr,int low,int high){
    int i=low,j=2*i,temp=arr[i];        //i是父节点，j指向i的左孩子，temp是i的值
    while(j<=high){                     //如果左孩子存在
        if(j<high&&arr[j]<arr[j+1])     //左右孩子比较，如果右孩子较大
            ++j;                        //j指向i的右孩子
        if(temp<arr[j]){                //如果i小于j
            arr[i]=arr[j];              //交换i节点和j节点的值
            i=j;                        
            j=2*i;
        }else
            break;
    }
    arr[i]=temp;
}

void heapSort(int* arr,int len){
    for(int i=len/2;i>=1;--i){
        sift(arr,i,len);
    }
    int temp;
    for(int i=len;i>=2;--i){
        temp=arr[1];
        arr[1]=arr[i];
        arr[i]=temp;
        sift(arr,1,i-1);
    }
}

void print(int* arr,int len){
    for(int i=0;i<len;++i){
        printf("%d ",arr[i]);
    }
}

int main(){
    int arr[]={0,9,8,7,6,5,4,3,2,1};
    heapSort(arr,sizeof(arr)/sizeof(arr[0]));
    print(arr,sizeof(arr)/sizeof(arr[0]));
}
