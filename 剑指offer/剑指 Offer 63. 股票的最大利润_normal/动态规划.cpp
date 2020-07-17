class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int res=0;
        int cost=INT_MAX;
        for(int i=0;i<nums.size();i++){
            cost=min(nums[i],cost);
            res=max(res,nums[i]-cost);
        }
        return res;
    }
};