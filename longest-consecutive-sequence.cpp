#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    unordered_set<int> hashset;
    for(int i: arr) hashset.insert(i);

    int longestStreak = 0;

    for(int num: arr){
        if( !hashset.count(num-1)){
            int curr = num;
            int currStreak = 1;
            while(hashset.count(curr+1)){
                curr++;
                currStreak++;
            }
            longestStreak= max(longestStreak,currStreak);
        }
    }
    return longestStreak;
}