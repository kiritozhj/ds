#include<iostream>
#include<algorithm>
using namespace std;

/*
int half(int arr[],int low,int high){
	bool mark=true;
	while(low<high){
		if(arr[low]>arr[high]){
			swap(arr[low],arr[high]);
			mark=!mark;
		}
		if(mark)
			--high;
		else 
			++low;
	}
	return low;
}

void quickSort(int arr[],int low,int high){
	if(low<high){
		int temp=half(arr,low,high);
		quickSort(arr,low,temp-1);
		quickSort(arr,temp+1,high);
	}
}
*/
void quickSortPlus(int arr[],int low,int high){
    if(low<high){
        int i=low,j=high;
        bool mark=true;
        while(i<j){
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
                mark=!mark;
            }
            if(mark)
                --j;
            else
                ++i;
        }
        quickSortPlus(arr,low,i-1);
        quickSortPlus(arr,i+1,high);
    }
}

int main()
{
	int arr[]={6,10,10,3,7,1,8};
	quickSortPlus(arr,0,6);
	for_each(arr,arr+7,[](int a){cout<<a<<' ';});
}
