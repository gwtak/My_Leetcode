class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res=INT_MIN;
        int tmp=0;
        for(int i=0;i<nums.size();i++){
            tmp+=nums[i];
            tmp=max(nums[i],tmp);
            res=max(tmp,res);
        }
        return res;
    }
};