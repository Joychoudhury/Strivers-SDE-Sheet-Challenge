#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n)
{
    // Write your code here.
    int majorityele = INT_MIN, count = 0;

    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            majorityele = arr[i];
            count = 1;
        }
        else
        {
            if (majorityele == arr[i])
                count++;
            else
                count--;
        }
    }
    int ele = 0;
    for (int i = 0; i < n; i++)
    {
        if (majorityele == arr[i])
            ele++;
    }
    if (ele > n / 2)
        return majorityele;
    else
        return -1;
}