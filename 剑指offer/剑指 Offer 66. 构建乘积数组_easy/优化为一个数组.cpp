class Solution {
public:
    vector<int> constructArr(vector<int>& nums) {
        vector<int> res(nums.size(),0);
        for(int i=0,tmp=1;i<nums.size();i++){
            tmp*=i-1>=0?nums[i-1]:1;
            res[i]=tmp;
        }
        for(int i=nums.size()-1,tmp=1;i>=0;i--){
            tmp*=i+1<nums.size()?nums[i+1]:1;
            res[i]*=tmp;
        }
        return res;
    }
};