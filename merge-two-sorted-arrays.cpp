#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int> &arr1, vector<int> &arr2, int m, int n)
{
    int len = n + m;
    int gap = (len / 2) + (len % 2);

    while (gap)
    {
        int i = 0, j = gap;
        while (j < len)
        {
            if (i < m && j < m)
            {
                if (arr1[i] > arr1[j])
                {
                    swap(arr1[i], arr1[j]);
                }
            }
            else if (i < m && j >= m)
            {
                if (arr1[i] > arr2[j - m])
                {
                    swap(arr1[i], arr2[j - m]);
                }
            }
            else if (i >= m && j >= m)
            {
                if (arr2[i - m] > arr2[j - m])
                {
                    swap(arr2[i - m], arr2[j - m]);
                }
            }
            i++, j++;
        }
        if (gap == 1)
            break;
        gap = (gap / 2) + (gap % 2);
    }

    for (int i = 0; i < n; i++)
    {
        arr1[i + m] = arr2[i];
    }
    return arr1;
}