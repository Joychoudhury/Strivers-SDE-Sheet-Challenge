#include <bits/stdc++.h>
int merge(int lo, int mid, int hi, vector<int> &arr)
{
    vector<int> temp;
    int l1 = lo, l2 = mid + 1;
    int j = mid + 1;
    int res = 0;

    for (int i = lo; i <= mid; i++)
    {
        while (j <= hi && arr[i] > 2 * arr[j])
        {
            j++;
        }
        res += (j - (mid + 1));
    }

    while (l1 <= mid && l2 <= hi)
    {
        if (arr[l1] <= arr[l2])
        {
            temp.push_back(arr[l1++]);
        }
        else
        {
            temp.push_back(arr[l2++]);
        }
    }
    while (l1 <= mid)
    {
        temp.push_back(arr[l1++]);
    }
    while (l2 <= hi)
    {
        temp.push_back(arr[l2++]);
    }

    for (int i = lo; i <= hi; i++)
    {
        arr[i] = temp[i - lo];
    }
    return res;
}

int mergeSort(int lo, int hi, vector<int> &arr)
{
    int res = 0;

    if (hi > lo)
    {
        int mid = (hi + lo) / 2;

        res += mergeSort(lo, mid, arr);
        res += mergeSort(mid + 1, hi, arr);

        res += merge(lo, mid, hi, arr);
    }
    return res;
}
int reversePairs(vector<int> &arr, int n)
{
    // Write your code here.
    return mergeSort(0, n - 1, arr);
}