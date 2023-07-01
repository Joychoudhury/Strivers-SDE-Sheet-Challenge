#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    // Write your code here
    int top = 0, left = 0, right = m - 1, bottom = n - 1;

    while (top < bottom && left < right)
    {
        int prev = mat[top + 1][left];
        for (int i = left; i <= right; i++)
        {
            int cur = mat[top][i];
            mat[top][i] = prev;
            prev = cur;
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            int cur = mat[i][right];
            mat[i][right] = prev;
            prev = cur;
        }
        right--;
        for (int i = right; i >= left; i--)
        {
            int cur = mat[bottom][i];
            mat[bottom][i] = prev;
            prev = cur;
        }
        bottom--;
        for (int i = bottom; i >= top; i--)
        {
            int cur = mat[i][left];
            mat[i][left] = prev;
            prev = cur;
        }
        left++;
    }
}