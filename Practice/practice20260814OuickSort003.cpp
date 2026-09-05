# include <bits/stdc++.h>
using namespace std ;

void quicksort(vector<int>&v,int s,int e){
if (s>=e) return ;
int pivot =v[e];
int i=s;
for (int j=s;j<e;j++){
  if (v[j]<pivot){
    swap(v[j],v[i]);
    i++;
    }
  }
swap(v[e],v[i]);
quicksort(v,s-1);
quicksort(v,l+1,e);
}


int main (){
  vector<int>v={346,346,547732,77477,-546};
  quicksort(v,0,v.size()-1);
  for (int i=0;i<v.size();i++){
    cout << v[i]<< " ";
  }
  return 0;
}
