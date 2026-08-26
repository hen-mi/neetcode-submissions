class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int profit = 0;

        for(auto& p : prices) {

            int temp = p - min;

            if(p < min) min = p;

            if(temp > profit) profit = temp;

        }

        return profit;
    }
};
