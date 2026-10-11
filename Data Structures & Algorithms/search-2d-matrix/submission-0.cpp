class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int lo = 0, hi = m - 1, row = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (matrix[mid][0] <= target) { row = mid; lo = mid + 1; }
            else hi = mid - 1;
        }
        if (row == -1) return false;

        lo = 0; hi = n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (matrix[row][mid] == target) return true;
            else if (matrix[row][mid] < target) lo = mid + 1;
            else hi = mid - 1;
        }
        return false;
    }
};