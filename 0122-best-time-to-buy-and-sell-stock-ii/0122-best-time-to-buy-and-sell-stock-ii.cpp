class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        for(int i=0;i<prices.size()-1;i++) // stop it at second last element i.e. why we are able to use i+1
        {
            if(prices[i]<prices[i+1])
                profit+=prices[i+1]-prices[i];
        }
     return profit;   
    }
   
};