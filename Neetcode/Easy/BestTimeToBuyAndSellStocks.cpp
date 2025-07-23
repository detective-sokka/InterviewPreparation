// https://leetcode.com/problems/best-time-to-buy-and-sell-stock
#include <vector>
using namespace std;


// prices = [7,1,5,3,6,4]
// prices = [7,6,4,3,1]
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0;
        int sell = 1;
        int result = 0;
        int n = prices.size();

        while (sell < n) {
            if (prices[buy] > prices[sell])
                buy = sell;
            else 
            {
                int profit = prices[sell] - prices[buy];
                result = result > profit ? result : profit;
            }                
            
            sell++;
        }

        return result;
    }
};