class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int minDis = INT_MAX;
        int ans = -1;

        for(int i = 0; i < drones.size(); i++) {
            int dis = abs(drones[i][0] - target[0]) + abs(drones[i][1] - target[1]);

            if(dis <= drones[i][2] && dis < minDis) {
                minDis = dis;
                ans = i;
            }
        }

        return ans;
    }
};