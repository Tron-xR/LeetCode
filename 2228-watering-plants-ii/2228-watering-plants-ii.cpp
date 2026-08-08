class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int left=0;
        int right=plants.size()-1;
        int waterA=capacityA;
        int waterB=capacityB;

        int refill=0;
        while (left<right)
        {
            if (plants[left]>waterA)
            {
                refill++;
                waterA=capacityA;
            }
            waterA-=plants[left];
            left++;
            if (plants[right]>waterB)
            {
                refill++;
                waterB=capacityB;
            }
            waterB-=plants[right];
            right--;
        }
        if (left==right)
        {
            if (max(waterA, waterB) < plants[left])
            {
                refill++;
            }
        }
        
        return refill;
    }
};