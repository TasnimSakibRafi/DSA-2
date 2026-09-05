#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeSort(vector<int> arr1)
{
    if (arr1.size() <= 1)
        return arr1;
    int mid = (arr1.size()) / 2;
    vector<int> left(arr1.begin(), arr1.begin()+mid);
    vector<int> right(arr1.begin() + mid, arr1.end());

    left = mergeSort(left);
    right = mergeSort(right);

    vector<int> ans;
    int i = 0, j = 0;

    while (i < left.size() && j < right.size())
    {
        if (left[i] > right[j])
        {
            ans.push_back(left[i]);
            i++;
        }
        else
        {
            ans.push_back(right[j]);
            j++;
        }
    }

    while (i < left.size())
    {
        ans.push_back(left[i]);
        i++;
    }

    while (j < right.size())
    {
        ans.push_back(right[j]);
        j++;
    }
    return ans;
}

int main()
{
    vector<int> arr1 = {8, 3, 5, 1, 9, 6};
    vector<int> sorted = mergeSort(arr1);
    cout << "Sorted Array : ";
    for (int i=0;i<sorted.size();i++){
            cout<<sorted[i]<<" ";
    }
}
