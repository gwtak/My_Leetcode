class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int,int> tmp;
        for(int i=0;i<nums.size();i++){
            if(tmp[nums[i]]) return nums[i];
            tmp[nums[i]]=1;
        }
        return 0;
    }
};