#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    unordered_map<int,int> mp;
    int ans = 0, xr=0;
    mp[xr] ++;

    for(int i =0 ;i<arr.size();i++){
        xr = xr^arr[i];
        int xorNeeeded = xr^x;
        ans += mp[xorNeeeded];

        mp[xr]++;
    }
    return ans;
}