//Previous approach jo space n*k le rha hai
int solve(vector<int>& prices,int k){
int n=prices.size();
vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));

for(int index=n-1;index>=0;index--){
  for(int buy=0;buy<=1;buy++){
  for(int limit=1;limit<=k;limit++){
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
  return dp[0][1][k];
}

    int maxProfit(int k, vector<int>& prices) {
        return solve(prices,k);
    }

//RECURSIVE
 int solve(int index,int operationNo,int k,vector<int>& prices){
 if(index==prices.size()) return 0;
 if(operationNo==2*k) return 0;

 int profit=0;
 if(operationNo%2==0) {
  int buykaro=-prices[index]+solve(index+1,operationNo+1,k,prices);
      int skipkaro=0+solve(index+1,operationNo,k,prices);
      profit=max(buykaro,skipkaro);
 }
 else{
int sellkaro=prices[index]+solve(index+1,operationNo+1,k,prices);
    int skipkaro=0+solve(index+1,operationNo,k,prices);
     profit=max(sellkaro,skipkaro);
 }
 return profit;
 }

    int maxProfit(int k, vector<int>& prices) {
        return solve(0,0,k,prices);
    }

//MEMOIZATION
int solve(int index,int operationNo,int k,vector<int>& prices,vector<vector<int>>&t){
 if(index==prices.size()) return 0;
 if(operationNo==2*k) return 0;
 
 if(t[index][operationNo]!=-1) t[index][operationNo];

 int profit=0;
 if(operationNo%2==0) {
  int buykaro=-prices[index]+solve(index+1,operationNo+1,k,prices,t);
      int skipkaro=0+solve(index+1,operationNo,k,prices,t);
      profit=max(buykaro,skipkaro);
 }
 else{
int sellkaro=prices[index]+solve(index+1,operationNo+1,k,prices,t);
    int skipkaro=0+solve(index+1,operationNo,k,prices,t);
     profit=max(sellkaro,skipkaro);
 }
 return t[index][operationNo]= profit;
 }

    int maxProfit(int k, vector<int>& prices) {
      int n=prices.size();
      vector<vector<int>>t(n,vector<int>(2*k,-1));
        return solve(0,0,k,prices,t);
    }

//DP
int solve(vector<int>& prices,int k){
int n=prices.size();
  vector<vector<int>>dp(n+1,vector<int>(2*k+1,-0));

for(int index=n-1;index>=0;index--){
  for(int operationNo=0;operationNo<2*k;operationNo++){
 
    int profit=0;

   if(operationNo%2==0) {
  int buykaro=-prices[index]+dp[index+1][operationNo+1];
      int skipkaro=0+dp[index+1][operationNo];
      profit=max(buykaro,skipkaro);
 }
 else{
int sellkaro=prices[index]+dp[index+1][operationNo+1];
    int skipkaro=0+dp[index+1][operationNo];
     profit=max(sellkaro,skipkaro);
 }
   dp[index][operationNo]= profit;
 }
}
  return dp[0][0];
}

    int maxProfit(int k, vector<int>& prices) {
        return solve(prices,k);
    }

//DP with space optimisation
int solve(vector<int>& prices,int k){
int n=prices.size();
  vector<int>curr(2*k+1,0);
  vector<int>next(2*k+1,0);

for(int index=n-1;index>=0;index--){
  for(int operationNo=0;operationNo<2*k;operationNo++){
 
    int profit=0;

   if(operationNo%2==0) {
  int buykaro=-prices[index]+next[operationNo+1];
      int skipkaro=0+next[operationNo];
      profit=max(buykaro,skipkaro);
 }
 else{
int sellkaro=prices[index]+next[operationNo+1];
    int skipkaro=0+next[operationNo];
     profit=max(sellkaro,skipkaro);
 }
   curr[operationNo]= profit;
 }
 next=curr;
}
  return next[0];
}

    int maxProfit(int k, vector<int>& prices) {
        return solve(prices,k);
    }
