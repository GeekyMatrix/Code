class Solution {
public:
//GREEDY APPROACH
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int profit=0;
        for(int i=1;i<n;i++){
            if(prices[i]>prices[i-1])
            profit+=prices[i]-prices[i-1];
        }
        return profit;
    }

//RECURSIVE APPROACH(TLE DEGA)
  int solve(int index,int buy,vector<int>& prices){
  if(index==prices.size()) return 0;
  int profit=0;

  if(buy){
      int buykaro=-prices[index]+solve(index+1,0,prices); 
      int skipkaro=0+solve(index+1,1,prices);
      profit=max(buykaro,skipkaro);
  }
  else {
    int sellkaro=prices[index]+solve(index+1,1,prices);
    int skipkaro=0+solve(index+1,0,prices);
     profit=max(sellkaro,skipkaro);
  }
 return profit;
  }

 //MEMOIZATION
int solve(int index,int buy,vector<int>& prices,vector<vector<int>>&t){
  if(index==prices.size()) return 0;

  if(t[index][buy]!=-1) return t[index][buy];
  int profit=0;

  if(buy){
      int buykaro=-prices[index]+solve(index+1,0,prices,t);
      int skipkaro=0+solve(index+1,1,prices,t);
      profit=max(buykaro,skipkaro);
  }
  else {
    int sellkaro=prices[index]+solve(index+1,1,prices,t);
    int skipkaro=0+solve(index+1,0,prices,t);
     profit=max(sellkaro,skipkaro);
  }
 return t[index][buy]=profit;
  }

 int maxProfit(vector<int>& prices) {
   int n=prices.size();
vector<vector<int>>t(n,vector<int>(2,-1));
 return solve(0,1,prices,t);
 }

//DP 
int solve(vector<int>& prices){
int n=prices.size();
vector<vector<int>>dp(n+1,vector<int>(2,0));

for(int index=n-1;index>=0;index--){
  for(int buy=0;buy<=1;buy++){

    int profit=0;

    if(buy){
      int buykaro=-prices[index]+dp[index+1][0];
      int skipkaro=0+dp[index+1][1];
      profit=max(buykaro,skipkaro);
  }
  else {
    int sellkaro=prices[index]+dp[index+1][1];
    int skipkaro=0+dp[index+1][0];
     profit=max(sellkaro,skipkaro);
  }
   dp[index][buy]=profit;
  }
  }
  return dp[0][1];
}

int maxProfit(vector<int>& prices) {
 return solve(prices);
 }
};

//DP with space optimization
int solve(vector<int>& prices){
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
    int sellkaro=prices[index]+next[1];
    int skipkaro=0+next[0];
     profit=max(sellkaro,skipkaro);
  }
   curr[buy]=profit;
  }
  next=curr;
  }
  return next[1];
}

int maxProfit(vector<int>& prices) {
 return solve(prices);
 }
};
