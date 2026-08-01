// Solution of Number 1 Question
# include<bits/stdc++.h>
using namespace std;
int countDivisibleBy7(vector <int> &v, int left, int right);


int main ()
{
vector<int>v={14,3,21,8,7,10};
  cout<<countDivisibleBy7(v, 0, v.size()-1) << endl; 
  return 0;
}

int countDivisibleBy7(vector <int> &v, int left, int right){
    if(left == right) return (v[left]%7 != 0);
    int mid = (left+right)/2;
    return countDivisibleBy7(v, left, mid) + countDivisibleBy7(v, mid+1, right);
}



