class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int res = INT_MAX;
        sort(coins.begin(),coins.end());//将硬币从小到大排序
        helper(coins,amount,coins.size()-1,0,res);
        return res==INT_MAX?-1:res;
    }
    void helper(vector<int>& coins, int amount, int start,int cur, int& res){
        if(start<0) return;
        if(amount%coins[start]==0){
            res = min(res, cur+amount/coins[start]);
            return;
        }
        for(int i = amount/coins[start]; i >=0; i--){
            if(cur+i>=res-1)break;
            helper(coins,amount-i*coins[start],start-1,cur+i,res);
        }
    }
};