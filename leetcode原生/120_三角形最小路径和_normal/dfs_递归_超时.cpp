class Solution {
public:
    int res=INT_MAX;
    void dfs(vector<vector<int>>& triangle,int i,int j,int sum){
        if(i>=triangle.size()||j>=triangle[i].size()){
            res=min(res,sum);
            return;
        }
        dfs(triangle,i+1,j,sum+triangle[i][j]);
        dfs(triangle,i+1,j+1,sum+triangle[i][j]);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        dfs(triangle,0,0,0);
        return res;
    }
};