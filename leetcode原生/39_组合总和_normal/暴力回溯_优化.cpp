class Solution {
public:
    vector<vector<int>> res;
    void tracer(vector<int>& nums,int target,int cnt,vector<int> path,int sum){
        if(sum==target){
            res.push_back(path);
            return;
        }
        else if(sum>target||cnt>=nums.size()) return;
        for(int i=cnt;i<nums.size();i++){
            path.push_back(nums[i]);
            tracer(nums,target,i,path,sum+nums[i]);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> path;
        tracer(nums,target,0,path,0);
        return res;
    }
};