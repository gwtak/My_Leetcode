class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int dp[col];
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i-1>=0&&j-1>=0) dp[j]=min(dp[j-1],dp[j])+grid[i][j];
                else if(i-1>=0) dp[j]=dp[j]+grid[i][j];
                else if(j-1>=0) dp[j]=dp[j-1]+grid[i][j];
                else dp[j]=grid[i][j];
            }
        }
        return dp[col-1];
    }
};