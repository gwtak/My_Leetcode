class Solution {
public:
    vector<vector<int>> res;
    void tracer(vector<int>& nums,int target,int cnt,vector<int> path,int sum){
        if(sum==target){
            res.push_back(path);
            return;
        }
        else if(sum>target) return;
        if(cnt>=nums.size()) return;
        for(int i=cnt;i<nums.size();i++){
            path.push_back(nums[i]);
            tracer(nums,target,i+1,path,sum+nums[i]);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<int> path;
        sort(nums.begin(),nums.end());
        tracer(nums,target,0,path,0);
        set<vector<int>> st(res.begin(),res.end());
        res.assign(st.begin(),st.end());
        return res;
    }
};