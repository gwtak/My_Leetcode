/*给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

说明：

所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
示例 2:

输入: candidates = [2,5,2,1,2], target = 5,
所求解集为:
[
  [1,2,2],
  [5]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    vector<vector<int>> res;
    void tracer(vector<int> nums, int target,vector<int> arr){
        if(target<0) return;
        if(!target){
            res.push_back(arr);
            return;
        }
        for(int i=0;i<nums.size();i++){
            vector<int> tmp_nums=nums;
            vector<int> tmp_arr=arr;
            int tmp=nums[i];
            nums.erase(nums.begin()+i);
            arr.push_back(tmp);
            tracer(nums,target-tmp,arr);
            arr=tmp_arr;
            nums=tmp_nums;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> arr;
        tracer(candidates,target,arr);
        for(vector<int>& x:res) sort(x.begin(),x.end());
        set<vector<int>> st(res.begin(),res.end());
        res.assign(st.begin(),st.end());
        return res;
    }
};