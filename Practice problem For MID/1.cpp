#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxCrossingSum(vector<int> &arr, int left, int mid, int right)
{
    int sum = 0;
    int left_sum = INT_MIN;

    for (int i = mid; i >= left; i--)
    {
        sum += arr[i];
        left_sum = max(left_sum, sum);
    }
    sum = 0;
    int right_sum = 0;
    for (int i = mid + 1; i <= right; i++)
    {
        sum += arr[i];
        right_sum = max(right_sum, sum);
    }
    return left_sum + right_sum;
}

int MaxSubarraySum(vector<int> &arr, int left, int right)
{
    if (left == right)
        return arr[left];
    int mid = (left + right) / 2;

    int left_max = MaxSubarraySum(arr, left, mid);
    int right_max = MaxSubarraySum(arr, mid + 1, right);
    int cross_max = maxCrossingSum(arr, left, mid, right);

    return max(max(left_max, right_max), cross_max);
}









int main()
{
    vector<int> arr1 = {-2, 3, 5, -1, 4, -6};
    vector<int> arr2 = {1, -3, 4, -2, 5};

    cout << "Sum : " << MaxSubarraySum(arr1, 0, arr1.size() - 1) << endl;
//     cout << "Sum : " << MaxSubarraySum(arr2, 0, arr2.size() - 1) << endl;
 }