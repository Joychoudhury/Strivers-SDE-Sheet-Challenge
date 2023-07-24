#include <bits/stdc++.h>

string fourSum(vector<int> arr, int target, int n) {
    // Write your code here.
    sort(arr.begin(),arr.end());
    for(int i = 0;i<n;i++){
        for(int j = i+1 ;j<n;j++){
            int target_3 = target - arr[i] - arr[j];

            int front = j+1,back = n-1;
            while(front<back){
                int two_sum = arr[front] + arr[back];

                if(two_sum < target_3) front++;
                else if(two_sum > target_3) back--;
                else if(two_sum == target_3) return "Yes";
            }
        }
    }
    return "No";
}
