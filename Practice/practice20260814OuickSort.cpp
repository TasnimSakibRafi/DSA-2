# include <bits/stdc++.h>
using namespace std;

void quickSort (vector<int>&v,int s,int e){
    if (s>=e) return ;
    int pivot=v[e];
    int i=s;
    for (int j=s;j<e;j++){
        if (v[j]<pivot ){
            swap(v[i],v[j]);
            i++;
        }
    }
    swap(v[i],v[e]);
    quickSort(v,s,i-1);
    quickSort(v,i+1,e);
}

int main(){
    vector<int>v={34,468,6,-7,3,-435,4353,2,-4353,46463};
    quickSort(v,0,v.size()-1);
    for (int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
        // i++;
    }

    return 0;
}
