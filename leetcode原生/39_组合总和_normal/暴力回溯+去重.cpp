/*给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的数字可以无限制重复被选取。

说明：

所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 
示例 1：

输入：candidates = [2,3,6,7], target = 7,
所求解集为：
[
  [7],
  [2,2,3]
]
示例 2：

输入：candidates = [2,3,5], target = 8,
所求解集为：
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
 

提示：

1 <= candidates.length <= 30
1 <= candidates[i] <= 200
candidate 中的每个元素都是独一无二的。
1 <= target <= 500

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    vector<vector<int>> res;
    bool in_nums(int num,vector<int>& nums){
        for(int x:nums){
            if(x==num) return 1;
        }
        return 0;
    }
    void tracer(vector<int>& nums, int target,vector<int> arr){
        if(target<0) return;
        if(!target){
            res.push_back(arr);
            return;
        }
        for(int i=1;i<=target;i++){
            if(in_nums(i,nums)){
                vector<int> tmp_arr=arr;
                arr.push_back(i);
                tracer(nums,target-i,arr);
                arr=tmp_arr;
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> arr;
        tracer(candidates,target,arr);
        for(vector<int>& x:res) sort(x.begin(),x.end());
        set<vector<int>> st(res.begin(),res.end());
        res.assign(st.begin(),st.end());
        return res;
    }
};