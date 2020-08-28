class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int decrease=0;
        for(int i=1,count=1;i<nums.size();i++){
            if(nums[i]==nums[i-1-decrease]) count++;
            else count=1;
            if(count>2) decrease++;
            else nums[i-decrease]=nums[i];
        }
        return nums.size()-decrease;
    }
};