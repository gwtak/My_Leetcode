class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        for(int i=1;i<=target/2;i++){
            int sum=0;
            for(int j=i;j<=(target/2+1);j++){
                sum+=j;
                if(sum==target){
                    vector<int> tmp;
                    for(int k=i;k<=j;k++){
                        tmp.push_back(k);
                    }
                    res.push_back(tmp);
                }
            }
        }
        return res;
    }
};