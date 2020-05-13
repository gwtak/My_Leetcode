class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        //思想还是用双指针
        int min_sum=nums[0]+nums[1]+nums[2];
        int cmp=abs(min_sum-target);
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            if(i>0&&nums[i]==nums[i-1])continue;
            int ptr1=i+1,ptr2=nums.size()-1;
            while(ptr1<ptr2){
                int tmp_sum=nums[i]+nums[ptr1]+nums[ptr2];
                if(tmp_sum<target){
                    ptr1++;
                }else if(tmp_sum>target){
                    ptr2--;
                }else return target;
                if(abs(target-tmp_sum)<cmp){
                    min_sum=tmp_sum;
                    cmp=abs(target-tmp_sum);
                }
            }
        }
        return min_sum;
    }
};