class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                for(int k=j+1;k<nums.size();k++){
                    if(nums[i]+nums[j]+nums[k]==0) res.push_back({nums[i],nums[j],nums[k]});
                }
            }
        }
        set<vector<int>> st(res.begin(),res.end());
        res.assign(st.begin(),st.end());
        return res;
    }
};