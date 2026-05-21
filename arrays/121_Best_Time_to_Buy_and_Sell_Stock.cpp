class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0],maxim=0;
        for (int i = 1; i < prices.size(); i++){
            if (prices[i] < min){
                min = prices[i];
            }
            maxim = max(maxim, prices[i]-min);
        }
        return maxim;
    }
};