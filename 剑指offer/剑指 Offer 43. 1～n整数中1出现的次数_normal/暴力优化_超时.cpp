class Solution {
public:
    vector<int> dp={0};
    int countDigitOne(int n) {
        if(n<dp.size()) return dp[n];
        for(int i=dp.size();i<=n;i++){
            int tmp=i;
            int last=dp[i-1];
            while(tmp){
                if(tmp%10==1){
                    last++;
                }
                tmp/=10;
            }
            dp.push_back(last);
        }
        //for(int x:dp) cout<<x<<endl;
        return dp[n];
    }
};