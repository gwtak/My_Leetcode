class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=INT_MIN;
        int nums_max=1;
        int nums_min=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0) nums_max^=nums_min^=nums_max^=nums_min;
            nums_max=max(nums_max*nums[i],nums[i]);
            nums_min=min(nums_min*nums[i],nums[i]);
            res=max(nums_max,res);
        }
        return res;
    }
};