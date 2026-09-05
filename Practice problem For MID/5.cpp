# include <iostream>
# include <vector>
using namespace std ;
int partition(vector<int>&arr,int low,int high){

    int pivot= arr[high];
    int i = low-1;

    for (int j= low;j<high;j++){
        if (arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

void Quicksort(vector<int>&arr,int low,int high){
    if (low < high ) {
        int pi =partition(arr,low,high);
        Quicksort(arr,low,pi-1);
        Quicksort(arr,pi+1,high);
    }
}

int main (){
 vector<int> arr1 = {10, 7, 8, 9, 1, 5};
 Quicksort(arr1,0,arr1.size());
 cout << "Sorted : ";
 for (int i=0;i<arr1.size();i++){
    cout << arr1[i]<<" ";
 }
}
