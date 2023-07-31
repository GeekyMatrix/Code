class Solution {
public:
//RECURSIVE METHOD
int solve(vector<int>& cost,int n){
    if(n==0) return cost[0];
    if(n==1) return cost[1];
    return cost[n]+min(solve(cost,n-1),solve(cost,n-2));
}
    int minCostClimbingStairs(vector<int>& cost) {
       int n=cost.size();
         return min(solve(cost,n-1),solve(cost,n-2));
    }

//MEMOIZATION METHOD
int solve(vector<int>& cost,int n, vector<int>t){
    if(n==0) return cost[0];
    if(n==1) return cost[1];
    if(t[n]!=-1) return t[n];
    return t[n]=cost[n]+min(solve(cost,n-1,t),solve(cost,n-2,t));
}
    int minCostClimbingStairs(vector<int>& cost) {
       int n=cost.size();
       vector<int>t(n+1,-1);
        return min(solve(cost,n-1,t),solve(cost,n-2,t));
    }

//DP METHOD
 int minCostClimbingStairs(vector<int>& cost) {
     int n=cost.size();
     vector<int>dp(n+1,0);
     dp[0]=cost[0];
     dp[1]=cost[1];
     for(int i=2;i<n;i++){
       dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
     }
     return min(dp[n-1],dp[n-2]);
 }
};
