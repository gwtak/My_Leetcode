class Solution {
public:
    int numWays(int n) {
        int dp[101];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=n;i++){
            if(i==0||i==1) dp[i]=1;
            else dp[i]=(dp[i-1]+dp[i-2])%1000000007;
        }
        return dp[n];
    }
};