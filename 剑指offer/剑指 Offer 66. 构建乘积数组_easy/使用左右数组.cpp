class Solution {
public:
    vector<int> constructArr(vector<int>& nums) {
        vector<int> left(nums.size(),0);
        vector<int> right(nums.size(),0);
        vector<int> res(nums.size(),0);
        for(int i=0,tmp=1;i<nums.size();i++){
            tmp*=nums[i];
            left[i]=tmp;
        }
        for(int i=nums.size()-1,tmp=1;i>=0;i--){
            tmp*=nums[i];
            right[i]=tmp;
        }
        for(int i=0;i<nums.size();i++){
            res[i]=(i-1>=0?left[i-1]:1)*(i+1<nums.size()?right[i+1]:1);
        }
        return res;
    }
};