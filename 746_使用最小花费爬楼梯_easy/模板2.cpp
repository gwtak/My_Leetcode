class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        vector<int> dp(size+1,0);
        for (int i = 2; i <= size; ++i) {
            dp[i] = min(dp[i-2]+cost[i-2],dp[i-1]+cost[i-1]);
        }
        return dp[size];
    }
};