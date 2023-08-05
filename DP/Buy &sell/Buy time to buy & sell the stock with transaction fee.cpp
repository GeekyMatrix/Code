class Solution {
public:
//RECURSIVE APPROACH(TLE DEGA)
  int solve(int index,int buy,vector<int>& prices,int fee){ 
  if(index==prices.size()) return 0;
  int profit=0;

  if(buy){
      int buykaro=-prices[index]+solve(index+1,0,prices,fee);
      int skipkaro=0+solve(index+1,1,prices,fee);
      profit=max(buykaro,skipkaro);
  }
  else {
    int sellkaro=prices[index]+solve(index+1,1,prices,fee)-fee;
    int skipkaro=0+solve(index+1,0,prices,fee);
     profit=max(sellkaro,skipkaro);
  }
 return profit;
  }

 int maxProfit(vector<int>& prices, int fee) {
 return solve(0,1,prices,fee);
 }

//MEMOIZATION
int solve(int index,int buy,vector<int>& prices,vector<vector<int>>&t,int fee){
  if(index==prices.size()) return 0;

  if(t[index][buy]!=-1) return t[index][buy];
  int profit=0;

  if(buy){
      int buykaro=-prices[index]+solve(index+1,0,prices,t,fee);
      int skipkaro=0+solve(index+1,1,prices,t,fee);
      profit=max(buykaro,skipkaro);
  }
  else {
    int sellkaro=prices[index]+solve(index+1,1,prices,t,fee)-fee;
    int skipkaro=0+solve(index+1,0,prices,t,fee);
     profit=max(sellkaro,skipkaro);
  }
 return t[index][buy]=profit;
  }

 int maxProfit(vector<int>& prices, int fee) {
   int n=prices.size();
vector<vector<int>>t(n,vector<int>(2,-1));
 return solve(0,1,prices,t,fee);
 }

//DP 
int solve(vector<int>& prices,int fee){
int n=prices.size();
vector<vector<int>>dp(n+1,vector<int>(2,0));
//buy==1,sell=0
for(int index=n-1;index>=0;index--){
  for(int buy=0;buy<=1;buy++){

    int profit=0;

    if(buy){
      int buykaro=-prices[index]+dp[index+1][0];
      int skipkaro=0+dp[index+1][1];
      profit=max(buykaro,skipkaro);
  }
  else {
    int sellkaro=prices[index]+dp[index+1][1]-fee;
    int skipkaro=0+dp[index+1][0];
     profit=max(sellkaro,skipkaro);
  }
   dp[index][buy]=profit;
  }
  }
  return dp[0][1];
}
    int maxProfit(vector<int>& prices, int fee) {
   return solve(prices,fee);
    }

//DP with transcation fee
int solve(vector<int>& prices,int fee){
int n=prices.size();
vector<int>curr(2,0);
vector<int>next(2,0);

for(int index=n-1;index>=0;index--){
  for(int buy=0;buy<=1;buy++){

    int profit=0;

    if(buy){
      int buykaro=-prices[index]+next[0];
      int skipkaro=0+next[1];
      profit=max(buykaro,skipkaro);
  }
  else {
    int sellkaro=prices[index]+next[1]-fee;
    int skipkaro=0+next[0];
     profit=max(sellkaro,skipkaro);
  }
   curr[buy]=profit;
  }
  next=curr;
  }
  return next[1];
}

int maxProfit(vector<int>& prices, int fee) {
   return solve(prices,fee);
    }
};

