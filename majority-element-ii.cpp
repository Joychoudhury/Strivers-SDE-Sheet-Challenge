#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{

    int n = arr.size();

    int c1 = 0, c2 = 0;
    int ele1 = INT_MIN, ele2 = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (c1 == 0 && arr[i] != ele2)
        {
            ele1 = arr[i];
            c1 = 1;
        }
        else if (c2 == 0 && arr[i] != ele1)
        {
            ele2 = arr[i];
            c2 = 1;
        }
        else if (ele1 == arr[i])
            c1++;
        else if (ele2 == arr[i])
            c2++;
        else
        {
            c1--;
            c2--;
        }
    }

    c1 = 0, c2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (ele1 == arr[i])
            c1++;
        if (ele2 == arr[i])
            c2++;
    }
    vector<int> ans;
    if (c1 > n / 3)
        ans.push_back(ele1);
    if (c2 > n / 3)
        ans.push_back(ele2);
    return ans;
}