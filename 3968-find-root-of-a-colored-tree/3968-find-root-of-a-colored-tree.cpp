class Solution {
public:
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        int n = colors.length();
        vector<int> ins(n, 0), outs(n, 0);
        
        auto getColorId = [](char c) {
            if (c == 'W') return 0;
            if (c == 'R') return 1;
            return 2;
        };
        
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            int uc = getColorId(colors[u]);
            int vc = getColorId(colors[v]);
        
            if (uc == vc) return -1;
            
            if ((uc + 1) % 3 == vc) {
                outs[u]++;
                ins[v]++;
            }
            else if ((vc + 1) % 3 == uc) {
                outs[v]++;
                ins[u]++;
            } else {
                return -1;
            }
            if (ins[u] > 1 || ins[v] > 1 || outs[u] > 2 || outs[v] > 2) {
                return -1;
            }
        }
        for (int i = 0; i < n; i++) {
            if (ins[i] == 0 && outs[i] <= 2) {
                return i;
            }
        }
        
        return -1;
    }
};