//RECURSIVE APPROACH(TLE DEGA)
  int solve(int index,int buy,vector<int>& prices,int limit){
  if(index==prices.size()) return 0;
  if(limit==0) return 0;
  int profit=0;
    
  if(buy){
      int buykaro=-prices[index]+solve(index+1,0,prices,limit);
      int skipkaro=0+solve(index+1,1,prices,limit);
      profit=max(buykaro,skipkaro);
  }
  else {
    int sellkaro=prices[index]+solve(index+1,1,prices,limit-1);
    int skipkaro=0+solve(index+1,0,prices,limit);
     profit=max(sellkaro,skipkaro);
  }
 return profit;
  }

int maxProfit(vector<int>& prices) {
        return solve(0,1,prices,2);
    }

// MEMOIZATION METHOD
 int solve(int index,int buy,vector<int>& prices,vector<vector<vector<int>>>&t,int limit){
  if(index==prices.size()) return 0;
    if(limit==0) return 0;
  if(t[index][buy][limit]!=-1) return t[index][buy][limit];
  int profit=0;

  if(buy){
      int buykaro=-prices[index]+solve(index+1,0,prices,t,limit);
      int skipkaro=0+solve(index+1,1,prices,t,limit);
      profit=max(buykaro,skipkaro);
  }
  else {
    int sellkaro=prices[index]+solve(index+1,1,prices,t,limit-1);
    int skipkaro=0+solve(index+1,0,prices,t,limit);
     profit=max(sellkaro,skipkaro);
  }
 return t[index][buy][limit]=profit;
  }

 int maxProfit(vector<int>& prices) {
   int n=prices.size();
  vector<vector<vector<int>>>t(n,vector<vector<int>>(2,vector<int>(3,-1)));
    return solve(0,1,prices,t,2);
 }

 //DP 
int solve(vector<int>& prices){
int n=prices.size();
vector<vector<int>curr(2,

for(int index=n-1;index>=0;index--){
  for(int buy=0;buy<=1;buy++){
  for(int limit=1;limit<=2;limit++){
    int profit=0;

    if(buy){
      int buykaro=-prices[index]+dp[index+1][0][limit];
      int skipkaro=0+dp[index+1][1][limit];
      profit=max(buykaro,skipkaro);
  }
  else {
    int sellkaro=prices[index]+dp[index+1][1][limit-1];
    int skipkaro=0+dp[index+1][0][limit];
     profit=max(sellkaro,skipkaro);
  }
   dp[index][buy][limit]=profit;
  }
  }
}
  return dp[0][1][2];
}

int maxProfit(vector<int>& prices) {
 return solve(prices);
 }

 //DP  with space optimization
int solve(vector<int>& prices){
int n=prices.size();

vector<vector<int>>curr(2,vector<int>(3,0));
vector<vector<int>>next(2,vector<int>(3,0));

for(int index=n-1;index>=0;index--){
  for(int buy=0;buy<=1;buy++){
  for(int limit=1;limit<=2;limit++){
    int profit=0;

    if(buy){
      int buykaro=-prices[index]+next[0][limit];
      int skipkaro=0+next[1][limit];
      profit=max(buykaro,skipkaro);
  }
  else {
    int sellkaro=prices[index]+next[1][limit-1];
    int skipkaro=0+next[0][limit];
     profit=max(sellkaro,skipkaro);
  }
   curr[buy][limit]=profit;
  }
  }
  next=curr;
}
  return next[1][2];
}

int maxProfit(vector<int>& prices) {
 return solve(prices);
 }
