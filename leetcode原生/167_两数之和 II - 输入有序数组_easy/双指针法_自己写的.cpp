class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0;
        int j=nums.size()-1;
        vector<int> res;
        while(i<j){
            if(nums[i]+nums[j]==target){
                res.push_back(i+1);
                res.push_back(j+1);
                return res;
            }
            else if(nums[i]+nums[j]<target) i++;
            else if(nums[i]+nums[j]>target) j--;
        }
        return res;
    }
};