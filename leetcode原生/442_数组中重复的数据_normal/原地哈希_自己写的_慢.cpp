class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for(int i=0;i<nums.size();){
            if(nums[i]!=i+1){
                if(nums[nums[i]-1]==nums[i]){
                    res.push_back(nums[i]);
                    i++;
                }
                else{
                    int tmp=nums[i];
                    nums[i]=nums[nums[i]-1];
                    nums[tmp-1]=tmp;
                }
            }
            else i++;
        }
        set<int> st(res.begin(),res.end());
        res.assign(st.begin(),st.end());
        return res;
    }
};