bool searchMatrix(vector<vector<int>> &mat, int target)
{
    int m = mat.size();
    int n = mat[0].size();
    int l = 0, r = m * n - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        int ele = mat[mid / n][mid % n];

        if (ele == target)
            return true;
        else if (ele < target)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return false;
}