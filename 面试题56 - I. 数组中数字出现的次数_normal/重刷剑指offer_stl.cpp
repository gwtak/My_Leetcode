class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        vector<int> res;
        unordered_map<int,int> tmp;
        for(int x:nums){
            tmp[x]++;
        }
        for(pair<int,int> x:tmp){
            if(x.second==1) res.push_back(x.first);
        }
        return res;
    }
};