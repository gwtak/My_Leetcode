class Solution {
public:
    static bool compare(int a,int b){//注意为static,类外创建
        return a>b;
    }
    int maxProfit(vector<int>& prices) {
        int res=0;
        vector<int> tmp(2,0);
        int i=0;
        int j=0;
        while(j<prices.size()){
            if(j+1<prices.size()&&prices[j]<prices[j+1]) j++;
            else{
                tmp.push_back(prices[j]-prices[i]);
                j++;
                i=j;
            }
        }
        sort(tmp.begin(),tmp.end(),compare);
        return tmp[0]+tmp[1];
    }
};