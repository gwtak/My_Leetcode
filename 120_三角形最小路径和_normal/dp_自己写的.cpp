/*给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。

例如，给定三角形：

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。

说明：

如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int res;
        int length=triangle.size();
        vector<vector<int>> dp;
        dp.push_back({triangle[0][0]});
        for(int i=1;i<length;i++){
            vector<int> tmp;
            for(int j=0;j<=i;j++){
                if(j==0) tmp.push_back(dp[i-1][0]+triangle[i][j]);
                else if(j==i) tmp.push_back(dp[i-1][j-1]+triangle[i][j]);
                else tmp.push_back(min(dp[i-1][j-1]+triangle[i][j],dp[i-1][j]+triangle[i][j]));
            }
            dp.push_back(tmp);
        }
        res=dp[dp.size()-1][0];
        for(int i=0;i<dp[dp.size()-1].size();i++){
            res=min(res,dp[dp.size()-1][i]);
        }
        return res;
    }
};