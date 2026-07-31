// This code only do mergesort in Acccending Order 


# include <bits/stdc++.h>
using namespace std;
vector <int> mergesort(vector<int>v){
     if (v.size()<=1)return v;
     int mid = v.size()/2;

     vector <int>left(v.begin(),v.begin()+mid);
     vector <int> right (v.begin()+mid,v.end());

     left=mergesort(left);
     right=mergesort(right);

     vector<int>ans;
     int i=0,j=0;

     while (i<left.size() && j<right.size()){
          if (left[i] < right [j]){      // Accending 
               ans.push_back(left[i]);
               i++;
          }else {
               ans.push_back(right[j]);
               j++;
          }
     }



     while (i<left.size()){
           ans.push_back(left[i]);
               i++;
     }
     while (j<right.size()){
          ans.push_back(right[j]);
               j++;
     }


     return ans;
}



int main (){
     vector <int> v={945,5,-76767,46,3435345,-7,4};
     vector<int>sorted=mergesort(v);

     cout << "sorted : "<< endl;
      for (int i=0;i<sorted.size();i++){
          cout << sorted[i]<<" ";
      }

      return 0;
}
