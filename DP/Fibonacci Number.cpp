class Solution {
public:
//RECURSIVE METHOD
    int fib(int n) {
        if(n<=1) return n;
        return fib(n-1)+fib(n-2);
    }

//MEMOIZATION METHOD
int solve(int n,vector<int>&t){
  if(n<=1) return n;
  if(t[n]!=-1) t[n];
  return t[n]=solve(n-1,t)+solve(n-2,t);
}
 int fib(int n) {
        vector<int>t(n+1,-1);
        return solve(n,t);
    }

//DP METHOD
int fib(int n) {
        vector<int> dp(n+1, 0);
        for(int i=0;i<=n;i++){
            if(i==0 || i==1)dp[i] = i; 
            else dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
