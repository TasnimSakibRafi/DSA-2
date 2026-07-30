
// Approach 1 
// We will include the array inside the code 
#include <iostream>
#include <vector>
using namespace std;

 //MergeSort For Decending Order Sorting 

vector<int> mergeSort(vector<int> v) {
    if (v.size() <= 1) return v;

    int mid = v.size() / 2;
    vector<int> left(v.begin(), v.begin() + mid);
    vector<int> right(v.begin() + mid, v.end());

    left = mergeSort(left);
    right = mergeSort(right);

    vector<int> ans;
    int i = 0, j = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] > right[j]) {
            ans.push_back(left[i]);
            i++;
        } else {
            ans.push_back(right[j]);
            j++;
        }
    }

    // Add remaining elements
    while (i < left.size()) {
        ans.push_back(left[i]);
        i++;
    }
    while (j < right.size()) {
        ans.push_back(right[j]);
        j++;
    }

    return ans;
}

int main() {
    vector<int> v = {3, 2, -60, 20, 3, 10, -2};
    vector<int> sorted = mergeSort(v);

    cout << "Sorted array: ";
    for (int x : sorted) cout << x << " ";
    cout << endl;

    return 0;
}







//Approach 2 
// We can take The input from user in this version 



#include <iostream>
#include <vector>
using namespace std;

// MergeSort For Descending Order Sorting
vector<int> mergeSort(vector<int> v) {
    if (v.size() <= 1) return v;

    int mid = v.size() / 2;
    vector<int> left(v.begin(), v.begin() + mid);
    vector<int> right(v.begin() + mid, v.end());

    left = mergeSort(left);
    right = mergeSort(right);

    vector<int> ans;
    int i = 0, j = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] > right[j]) {   // descending order
            ans.push_back(left[i]);
            i++;
        } else {
            ans.push_back(right[j]);
            j++;
        }
    }

    // Add remaining elements
    while (i < left.size()) {
        ans.push_back(left[i]);
        i++;
    }
    while (j < right.size()) {
        ans.push_back(right[j]);
        j++;
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> v(n);
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> v[i];   // take input from user
    }

    vector<int> sorted = mergeSort(v);

    cout << "Sorted array (descending): ";
    for (int x : sorted) cout << x << " ";
    cout << endl;

    return 0;
}
