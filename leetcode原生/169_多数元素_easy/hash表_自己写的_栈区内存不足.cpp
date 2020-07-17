class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int length=nums.size();
        int hash[10000];
        vector<int> tmp;
        int res=0;
        memset(hash,0,sizeof(hash));
        for(int i=0;i<length;i++){
            if(nums[i]>=0){
                hash[nums[i]]++;
                if(hash[nums[i]]>length/2) return nums[i];
            } 
        }
        memset(hash,0,sizeof(hash));
        for(int i=0;i<length;i++){
            if(nums[i]<0){
                hash[-nums[i]]++;
                if(hash[nums[i]]>length/2) return -nums[i];
            }
        }
        return res;
    }
};