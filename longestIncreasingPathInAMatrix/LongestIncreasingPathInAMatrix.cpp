


class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int result = 0;
        int row = matrix.size();
        int col = row ? matrix[0].size() : 0;
        vector<vector<int>> path = vector<vector<int>>(row, vector<int>(col, 0));
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                result = max(result, helper(matrix, path, row, col, r, c));
            }
        }
        return result;
    }
    
    int helper(vector<vector<int>>& matrix, vector<vector<int>>& path, const int row, const int col, int r, int c) {

        if (path[r][c]>0) return path[r][c];
        
        int maxPath = 0;
        
        int tmp = matrix[r][c]; 
        matrix[r][c]=INT_MIN;  
        if (r < row-1 && tmp < matrix[r+1][c]) {
            maxPath = max(maxPath, helper(matrix, path, row, col, r+1, c));
        }
        if (c < col-1 && tmp < matrix[r][c+1]) {
            maxPath = max(maxPath, helper(matrix, path, row, col, r, c+1));
        }
        if (r > 0 && tmp < matrix[r-1][c]) {
            maxPath = max(maxPath, helper(matrix, path, row, col, r-1, c));
        }
        if (c > 0 && tmp < matrix[r][c-1]) {
            maxPath = max(maxPath, helper(matrix, path, row, col, r, c-1));
        }
        matrix[r][c] = tmp;
        path[r][c] = maxPath + 1;
        return path[r][c];
    }
};
