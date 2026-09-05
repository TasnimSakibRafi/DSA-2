#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int crossingPro(vector<int>& arr,int left,int mid,int right){
    int left_pro =1;
    int max_left= INT_MIN;
    for (int i=mid;i>=left;i--){
        left_pro *= arr[i];
        max_left = max(max_left,left_pro);
        if (arr[i]==0) break;
    }
    int right_pro =1;
    int max_right= INT_MIN;
    for (int i=mid+1;i<=right;i++){
        right_pro *= arr[i];
        max_right = max(max_right,right_pro);
        if (arr[i]==0) break;
    }
    return max_left*max_right;
}

int Maxproduct(vector<int>&arr,int left,int right){
    if (left==right) return arr[left];
    int mid = (left+right)/2;
    int left_pro = Maxproduct(arr,left,mid);
    int right_pro = Maxproduct(arr,mid+1,right);
    int cross_pro = crossingPro (arr,left,mid,right);
    return max(max(left_pro,right_pro),cross_pro);
}

int main(){
    vector<int>arr1{2, 3, 0, 4, 5};
    vector<int>arr2= {0, 1, 2, 3, 0, 4};
    cout<<"MaxPriduct : "<<Maxproduct(arr1,0,arr1.size()-1)<<endl;
    cout<<"MaxPriduct : "<<Maxproduct(arr2,0,arr2.size()-1)<<endl;
}
