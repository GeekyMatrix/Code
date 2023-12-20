class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int temp = money;
        sort(prices.begin(),prices.end());

        money -= prices[0];
        money -= prices[1];

        if(money >= 0) return money; 
         return temp;
    }
};
