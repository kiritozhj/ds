#include<iostream>
using namespace std;

int search(int arr[],int len,int k){
    for(int i=0;i<len-1;++i){
        if(arr[i]==k) return i;
    }
    return -1;
}

int main(){
    
}