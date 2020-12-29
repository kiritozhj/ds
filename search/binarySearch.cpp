#include<iostream>
#include<algorithm>
using namespace std;

int binarySearch(int* arr,int begin,int end,int k){
    int mid;
    while(begin<=end){
        mid=(begin+end)/2;
        if(arr[mid]==k)
            return mid;
        else if(arr[mid]>k)
            end=mid-1;
        else
            begin=mid+1;
    }
    return -1;
}

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,14};
    cout<<binarySearch(arr,0,9,14);
}
