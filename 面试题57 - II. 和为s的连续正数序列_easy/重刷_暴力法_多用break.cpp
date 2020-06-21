class Solution {
public:
    vector<vector<int>> findContinuousSequence(int t) {
        vector<vector<int>> res;
        for(int i=1;i<=t/2+1;i++){
            int sum=0;
            for(int j=i;j<=t/2+1;j++){
                sum+=j;
                if(sum==t){
                    vector<int> tmp;
                    for(int k=i;k<=j;k++){
                        tmp.push_back(k);
                    }
                    res.push_back(tmp);
                    break;
                }
                else if(sum>t) break;
            }
        }
        return res;
    }
};