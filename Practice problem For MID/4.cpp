#include <iostream>
#include <vector>
using namespace std;


int mergeAndCount(vector <int>& arr,int left,int mid,int right){
    vector<int>leftArr(arr.begin()+left,arr.begin()+mid+1);
    vector<int>rightArr(arr.begin()+mid+1,arr.begin()+right+1);
    int i=0,j=0,k=left;
    int inv =0;

    while (i < leftArr.size() && j<rightArr.size()){
        if (leftArr[i]<=rightArr[j]){
            arr[k++]=leftArr[i++];
        }else {
            arr[k++]=rightArr[j++];
            inv+= (leftArr.size()-i);
        }
    }
    while(i<leftArr.size()) arr[k++] = leftArr[i++];
    while(j<rightArr.size()) arr[k++]=rightArr[j++];
    return inv;
}



int mergeSortandCount (vector<int>& arr,int left,int right){
    int inv = 0 ;
    if (left<right){
        int mid = left + (right-left)/2;
        inv += mergeSortandCount(arr,left,mid);
        inv += mergeSortandCount (arr,mid+1,right);
        inv += mergeAndCount(arr,left,mid,right);
    }
    return inv;
}

int main() {
    vector<int> arr1 = {8, 4, 2, 1};

    cout << "Number of Inversions: " ;
    cout<< mergeSortandCount(arr1, 0, arr1.size() - 1);

    return 0;
}


