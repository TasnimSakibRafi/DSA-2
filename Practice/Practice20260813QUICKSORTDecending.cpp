//This is only for Decending Order 

#include <bits/stdc++.h>
using namespace std;

void quickSort(vector<int>& v, int s, int e) {
    if (s >= e) return;

    // Inline partitioning
    int pivot = v[e];   // choose last element as pivot
    int i = s;          // index for smaller elements
    for (int j = s; j < e; j++) {
        if (v[j] > pivot) {
            swap(v[i], v[j]);
            i++;
        }
    }
    swap(v[i], v[e]);   // place pivot in correct position

    // Recursive calls
    quickSort(v, s, i - 1);
    quickSort(v, i + 1, e);
}

int main() {
    vector<int> v = {3, 2, -60, 20, 3, 10, -2};
    quickSort(v, 0, v.size() - 1);

    for(int i=0;i<v.size();i++){
        cout<<v[i]<< " ";
    }
    cout << endl;

    return 0;
