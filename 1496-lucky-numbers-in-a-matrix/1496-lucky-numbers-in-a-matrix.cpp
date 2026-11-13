class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> ans;

        for (int i = 0; i < m; i++) 
        {
            int minCol = 0;
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] < matrix[i][minCol]) {
                    minCol = j;
                }
            }
            bool isLucky = true;

            for (int k = 0; k < m; k++) {
                if (matrix[k][minCol] > matrix[i][minCol]) {
                    isLucky = false;
                    break;
                }
            }

            if (isLucky) ans.push_back(matrix[i][minCol]);
        }

        return ans;
    }
};