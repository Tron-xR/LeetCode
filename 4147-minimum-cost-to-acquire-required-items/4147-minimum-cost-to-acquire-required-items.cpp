class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long a=1LL*cost1*need1+1LL*cost2*need2;
        long long b=1LL*costBoth*max(need1,need2);
        long long c=1LL*costBoth*min(need1,need2)+(need1-min(need1,need2))*1LL*cost1+(need2-min(need1,need2))*1LL*cost2;
        return min(a,min(b,c));
    }
};