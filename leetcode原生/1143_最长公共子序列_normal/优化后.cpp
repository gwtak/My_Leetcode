class Solution {
public:
    int longestCommonSubsequence(string str1, string str2) {
        vector<vector<int>> dp(str1.size(),vector<int>(str2.size(),0));
        int res=0;
        for(int i=0;i<str1.size();i++){
            for(int j=0;j<str2.size();j++){
                if(i==0||j==0){
                    if(str1[i]==str2[j]) dp[i][j]=1;
                    else if(i-1>=0) dp[i][j]=dp[i-1][j];
                    else if(j-1>=0) dp[i][j]=dp[i][j-1];
                }
                else if(str1[i]==str2[j]) dp[i][j]=dp[i-1][j-1]+1;
				else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                res=max(res,dp[i][j]);
            }
        }
        return res;
    }
};