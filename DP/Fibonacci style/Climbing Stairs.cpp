class Solution {
public:
//RECURSIVE METHOD
    int climbStairs(int n) {
        if(n<=1) return 1;

       return climbStairs(n-1)+ climbStairs(n-2);
    }

//MEMOIZATION METHOD
int solve(int n,vector<int>t){
    if(n<=1) return 1;
    if(t[n]!=-1) return t[n];
    return t[n]=solve(n-1,t)+solve(n-2,t);
}
  int climbStairs(int n) {
    vector<int>t(n+1,-1);
    return solve(n,t);
  }

//DP METHOD
 int climbStairs(int n) {
  vector<int>dp(n+1,-1);
  dp[0]=1,dp[1]=1;
for(int i=2;i<=n;i++)   dp[i]=dp[i-1]+dp[i-2];
return dp[n];
 }
};
