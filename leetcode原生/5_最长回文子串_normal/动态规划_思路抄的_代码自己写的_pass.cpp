class Solution {
public:
    string longestPalindrome(string s) {
        string rev;
        string res;
        if(s.empty()) return res;
        int max_i=0;
        int max_j=0;
        int max=0;
        for(int i=s.size()-1;i>=0;i--){
            rev.push_back(s[i]);
        }
        int dp[s.size()][s.size()];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<rev.size();i++){
            for(int j=0;j<s.size();j++){
                if(i>0&&j>0){
                    if(rev[i]==s[j]) dp[i][j]=dp[i-1][j-1]+1;
                    else dp[i][j]=0;//及时将已经不再相同的字串置0
                }
                else{
                    if(rev[i]==s[j]) dp[i][j]=1;
                }
                if(i+j-dp[i][j]+2!=s.size()) continue;//排除类似"aacdfcaa"的输入，避免输出aac
                if(dp[i][j]>max){
                    max=dp[i][j];
                    //cout<<"max="<<max<<endl;
                    max_i=i;
                    max_j=j;
                    //cout<<"max_i="<<max_i<<"  "<<"max_j="<<max_j<<endl;
                }
            }
        }
        //显示dp表
        /*for(int i=0;i<rev.size();i++){
            for(int j=0;j<s.size();j++){
                cout<<dp[i][j]<<',';
            }
            cout<<endl;
        }*/
        while(max_i>=0&&max_j>=0&&dp[max_i][max_j]){
            res.push_back(rev[max_i]);
            max_i--;
            max_j--;
        }
        return res;
    }
};