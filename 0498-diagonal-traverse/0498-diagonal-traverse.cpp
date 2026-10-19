class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    if (mat.empty() || mat[0].empty()) return {};
    
    int R = mat.size();
    int C = mat[0].size();
    vector<int> result;
    result.reserve(R * C);

    for (int k = 0; k < R + C - 1; ++k) {
        int low =max(0, k - (C - 1));
        int high =min(R - 1, k);

        if (k % 2 == 0) {
            for (int r = high; r >= low; --r) {
                result.push_back(mat[r][k - r]);
            }
        } else {
            for (int r = low; r <= high; ++r) {
                result.push_back(mat[r][k - r]);
            }
        }
    }
    
    return result;
    }
};