/*给定一个可包含重复数字的序列，返回所有不重复的全排列。

示例:

输入: [1,1,2]
输出:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutations-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    vector<vector<int>> res;
    void tracer(vector<int> trace,vector<int> nums){
        if(nums.empty()) res.push_back(trace);
        for(int i=0;i<nums.size();i++){
            vector<int> tmp_trace=trace;
            vector<int> tmp_nums=nums;
            trace.push_back(nums[i]);
            nums.erase(nums.begin()+i);
            tracer(trace,nums);
            nums=tmp_nums;
            trace=tmp_trace;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> trace;
        tracer(trace,nums);
        set<vector<int>> st(res.begin(),res.end());
        res.assign(st.begin(),st.end());
        return res;
    }
};