/*找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

说明：

所有数字都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: k = 3, n = 7
输出: [[1,2,4]]
示例 2:

输入: k = 3, n = 9
输出: [[1,2,6], [1,3,5], [2,3,4]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    vector<vector<int>> res;
    void tracer(int target,int cnt,vector<int>& path,int last){
        if(!target&&!cnt){
            res.push_back(path);
            return;
        }
        else if(target<=0||cnt<=0) return;
        for(int i=last+1;i<=9;i++){
            path.push_back(i);
            tracer(target-i,cnt-1,path,i);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        tracer(n,k,path,0);
        return res;
    }
};