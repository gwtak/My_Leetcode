class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0;
        int min_price=INT_MAX;
        for(int i=0;i<prices.size();i++){
            res=max(res,prices[i]-min_price);
            min_price=min(prices[i],min_price);
        }
        return res;
    }
};