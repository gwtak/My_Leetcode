class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = nums[0];
        int sum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(sum<0){
                sum = nums[i];
            }
            else{
                sum = sum + nums[i];
            }
            if(sum>maxsum)
            maxsum = sum;
        }
        return maxsum;
    }
};