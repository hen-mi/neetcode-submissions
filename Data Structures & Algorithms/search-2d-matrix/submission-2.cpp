class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int cols = matrix[0].size() - 1;

        for (int j = 0; j < matrix.size(); ++j) {

            // Check if target could be in this row
            if (matrix[j][0] <= target &&
                matrix[j][cols] >= target) {

                int left = 0;
                int right = cols;

                while (left <= right) {

                    int mid = left + (right - left) / 2;

                    if (matrix[j][mid] == target)
                        return true;

                    else if (target > matrix[j][mid])
                        left = mid + 1;

                    else
                        right = mid - 1;
                }

                return false;
            }
        }

        return false;
    
    }
};
