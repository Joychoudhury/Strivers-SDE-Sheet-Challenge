#include <bits/stdc++.h>

pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
    // Write your code here
    int xr = 0;
    for (int i = 1; i <= n; i++)
    {
        xr ^= (i ^ arr[i - 1]);
    }
    int num = (xr & ~(xr - 1));

    int missing = 0, repeating = 0;
    for (int i = 0; i < n; i++)
    {
        if ((arr[i] & num) != 0)
            missing ^= arr[i];
        else
            repeating ^= arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if ((i & num) != 0)
            missing ^= i;
        else
            repeating ^= i;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == repeating)
            cnt++;
    }

    if (cnt == 2)
        return {missing, repeating};
    return {repeating, missing};
}
