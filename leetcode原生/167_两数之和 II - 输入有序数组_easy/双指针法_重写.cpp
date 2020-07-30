class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0,j=nums.size()-1;i<=j;){
            int sum=nums[i]+nums[j];
            if(sum>target) j--;
            else if(sum<target) i++;
            else if(sum==target) return vector<int>{i+1,j+1};
        }
        return vector<int>(NULL);
    }
};