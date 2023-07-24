#include <bits/stdc++.h>
int uniqueSubstrings(string input)
{
    // Write your code here
    vector<int> mp(256, -1);
    int l = 0, r = 0;
    int n = input.size();
    int ans = 0;
    while (r < n)
    {
        if (mp[input[r]] != -1)
        {
            l = max(mp[input[r]] + 1, l);
        }
        mp[input[r]] = r;
        ans = max(ans, r - l + 1);
        r++;
    }
    return ans;
}