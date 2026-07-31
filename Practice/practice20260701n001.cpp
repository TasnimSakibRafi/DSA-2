
//This Code Only Finds Maximum


#include <bits/stdc++.h>
using namespace std;

int findMax (vector<int>&v,int s,int e);




int main (){
    vector<int>v= {45,466,7,33,686,25};
    int maximum = findMax(v,0,v.size()-1);
    cout << maximum <<endl;
    return 0;
    
}
int findMax (vector<int>&v,int s,int e){
    if (s==e) return v[s];
    int mid =(s+e)/2;
    return max(findMax(v,s,mid),findMax(v,mid+1,e));
    
}
