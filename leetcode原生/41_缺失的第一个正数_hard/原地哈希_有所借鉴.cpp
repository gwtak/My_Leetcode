class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0;i<nums.size();){
            if(nums[i]>0&&nums[i]<=nums.size()&&nums[i]!=nums[nums[i]-1]){
                int tmp=nums[i];
                nums[i]=nums[tmp-1];
                nums[tmp-1]=tmp;
            }
            else i++;
        }
        //for(int x:nums) cout<<x<<endl;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i+1) return i+1;
        }
        return nums.size()+1;
    }
};