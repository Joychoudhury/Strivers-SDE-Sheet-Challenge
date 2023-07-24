#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s)
{
    // Write your code here.
    map<int, int> mp;
    vector<vector<int>> ans;

    for (int i = 0; i < arr.size(); i++)
    {
        int moreNeeded = s - arr[i];
        int x = mp[moreNeeded];
        if (mp.find(moreNeeded) != mp.end())
        {
            while (x--)
            {

                if (moreNeeded > arr[i])
                    ans.push_back({arr[i], moreNeeded});
                else
                    ans.push_back({moreNeeded, arr[i]});
            }
        }
        mp[arr[i]]++;
    }

    sort(ans.begin(), ans.end());
    return ans;
}