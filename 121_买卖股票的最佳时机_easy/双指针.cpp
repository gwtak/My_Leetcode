class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int j = 0;
        int m_Profit = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i] - prices[j] > m_Profit)
                m_Profit = prices[i] - prices[j];
            if(prices[i] < prices[j])
                j = i;
        }
        return m_Profit;
    }
};