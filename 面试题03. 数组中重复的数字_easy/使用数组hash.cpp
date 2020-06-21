class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        vector<int> tmp(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            if(tmp[nums[i]]) return nums[i];
            else tmp[nums[i]]=1;
        }
        return 0;
    }
};