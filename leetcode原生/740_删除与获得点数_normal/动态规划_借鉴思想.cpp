/*简化成打家劫舍问题*/
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.empty()) return 0;
        int len=0;
        for(int x:nums) len=max(len,x);
        int cnt[len+1];
        int dp[len+1];
        memset(cnt,0,sizeof(cnt));
        memset(dp,0,sizeof(dp));
        for(int x:nums) cnt[x]++;
        dp[1]=cnt[1];
        for(int i=2;i<=len;i++){
            dp[i]=max(cnt[i]*i+dp[i-2],dp[i-1]);
        }
        int res=0;
        for(int i=0;i<=len;i++) res=max(res,dp[i]);
        return res;
    }
};