/*给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

示例:

输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combinations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    vector<vector<int>> res;
    void tracer(int n,int m,int start,vector<int> tmp){
        if(!m){
            res.push_back(tmp);
            return;
        }
        for(int i=start;i<=n;i++){
            tmp.push_back(i);
            tracer(n,m-1,i+1,tmp);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> tmp;
        tracer(n,k,1,tmp);
        return res;
    }
};