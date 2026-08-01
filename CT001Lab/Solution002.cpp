// Answer Of Question 2 
//I Did Is Stupidtly Big But I Still Think This Is The Easy One To Do(^^)


#include <bits/stdc++.h>
using namespace std;


// Step 1: Normal merge sort in descending order
vector<int> mergeSort(vector<int> v)
{
    if (v.size() <= 1)
        return v;

    int mid = v.size() / 2;
    vector<int> left(v.begin(), v.begin() + mid);
    vector<int> right(v.begin() + mid, v.end());

    left = mergeSort(left);
    right = mergeSort(right);

    vector<int> ans;
    int i = 0, j = 0;

    while (i < left.size() && j < right.size())
    {
        if (left[i] > right[j])
        { // descending order
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
        ans.push_back(left[i++]);
    while (j < right.size())
        ans.push_back(right[j++]);

    return ans;
}


// Step 2: Split into odd and even arrays
void splitOddEven(vector<int> v, vector<int> &A1, vector<int> &A2)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] % 2 == 0)
            A2.push_back(v[i]); // even
        else
            A1.push_back(v[i]); // odd
    }
}


// Step 3: Merge odd and even arrays (odds first)
vector<int> mergeOddEven(vector<int> A1, vector<int> A2)
{
    vector<int> merged;
    for (int i = 0; i < A1.size(); i++)
        merged.push_back(A1[i]);
    for (int i = 0; i < A2.size(); i++)
        merged.push_back(A2[i]);
    return merged;
}


int main()
{
    vector<int> arr = {8, 3, 2, 9, 6, 1, 4, 7};

    // Step 1: Sort entire array in descending order
    vector<int> sorted = mergeSort(arr);

    // Step 2: Split into odd and even arrays
    vector<int> A1, A2;
    splitOddEven(sorted, A1, A2);

    // Step 3: Merge odds first, then evens
    vector<int> finalArr = mergeOddEven(A1, A2);

    cout << "Sorted (Odd-Even Descending): ";
    for (int i = 0; i < finalArr.size(); i++)
        cout << finalArr[i] << " ";
    cout << endl;

    return 0;
}
