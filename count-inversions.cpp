#include <bits/stdc++.h>

long long merge(long long *arr, int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;

    long long left[n1], right[n2];
    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[low + i];
    }
    for (int i = 0; i < n2; i++)
    {
        right[i] = arr[mid + i + 1];
    }

    long long inversions = 0;
    int i = 0, j = 0, k = low;

    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
            inversions += n1 - i;
        }
    }
    while (i < n1)
    {
        arr[k++] = left[i++];
    }
    while (j < n2)
    {
        arr[k++] = right[j++];
    }
    return inversions;
}

long long merge_sort(long long *arr, int low, int high)
{
    long long inversions = 0;

    if (low < high)
    {
        int mid = (low + high) / 2;
        inversions += merge_sort(arr, low, mid);
        inversions += merge_sort(arr, mid + 1, high);
        inversions += merge(arr, low, mid, high);
    }
    return inversions;
}
long long getInversions(long long *arr, int n)
{
    // Write your code here.
    return merge_sort(arr, 0, n - 1);
}