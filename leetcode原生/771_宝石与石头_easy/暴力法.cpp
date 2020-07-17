class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int ans=0;
        for(int i=0;i<=S.size()-1;i++){
            for(int j=0;j<=J.size()-1;j++){
                if(S[i]==J[j]) ans++;
            }
        }
        return ans;
    }
};