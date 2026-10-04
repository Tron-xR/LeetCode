class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        vector<vector<int>> temp(n, vector<int>(n));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                temp[i][(j - rowShift[i] % n + n) % n] = grid[i][j];
            }
        }

        grid = temp;

 
        for(int j = 0; j < n; j++) {
            for(int i = 0; i < n; i++) {
                temp[(i - colShift[j] % n + n) % n][j] = grid[i][j];
            }
        }
        return temp;
    }
};