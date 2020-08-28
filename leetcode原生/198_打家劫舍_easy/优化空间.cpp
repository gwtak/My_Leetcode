class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size()==1) return nums[0];
        int pre_pre=nums[0];
        int pre=max(nums[0],nums[1]);
        int res=pre;
        for(int i=2;i<nums.size();i++){
            res=max(pre_pre+nums[i],pre);
            pre_pre=pre;
            pre=res;
        }
        return res;
    }
};