class Solution {
public:
//RECURSIVE METHOD
    int tribonacci(int n) {
        if(n<=1) return n;
        if(n==2) return 1;
        return tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
    }

//MEMOIZATION METHOD
int solve(int n,vector<int>&t){
  if(n<=1) return n;
    if(n==2) return 1;
  if(t[n]!=-1) t[n];
  return t[n]=solve(n-1,t)+solve(n-2,t)+solve(n-3,t);
}
 int tribonacci(int n) {
        vector<int>t(n+1,-1);
        return solve(n,t);
    }

//DP METHOD
int tribonacci(int n) {
        vector<int>dp(n+1,0);
       for(int i=0;i<=n;i++){
            if(i==0 || i == 1) dp[i] = i;
            else if(i==2) dp[i] = 1;
            else  dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
            
        }
        return dp[n];
    }
};
