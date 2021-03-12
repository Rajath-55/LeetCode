#include<bits/stdc++.h>
using namespace std;

int findLargestIndex(int arr[], int lastIdx){
    int maxIdx = 0;
    for(int i=0;i < lastIdx; ++i){
        if(arr[i] > arr[maxIdx]) maxIdx=i;
    }
    return maxIdx;
}

void flip(int arr[], int i){
    int j = 0;
    while(j<i){
        swap(arr[i], arr[j]);
        j++;
        i--;
    }
}

void pancakeSort(int arr[], int n){
    for(int i=n-1;i>=1;--i){
        int maxIdx = findLargestIndex(arr, i);
        if(maxIdx != i){
            flip(arr, maxIdx);
            flip(arr, i);
        }
    }
}



int main(){
    int arr[] = {10,5,6,34,21,9,0,7};
    int size = 8;
    pancakeSort(arr, 8);
    for(int i=0 ;i< 8 ; ++i) cout<<arr[i]<<" ";

}