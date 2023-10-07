class Solution {
public:
//Recursion 
 int solve(int n){
    //BASE CASE 
    if(n == 1) return 1;
    int res = INT_MIN;

     for(int i = 1; i < n; i++){
         int product = i * max(n - i,solve(n - i));
         res = max(res , product);
     }
     return res;
 }
    int integerBreak(int n) {
        return solve(n);
    }

//Memoization
int t[59];
 int solve(int n){
    //BASE CASE 
    if(n == 1) return 1;
    if(t[n]!=-1) return t[n];
    int res = INT_MIN;

     for(int i = 1; i < n; i++){
         int product = i * max(n - i,solve(n - i));
         res = max(res , product);
     }
     return t[n] = res;
 }
    int integerBreak(int n) {
        memset(t,-1,sizeof(t));
        return solve(n);
    }

//DP
    int integerBreak(int n) {
        vector<int>dp(n + 1,0);
        dp[1] = 1;
        for(int i = 2; i <=n; i++){
          for(int j = 1; j < i; j++){
              int product = j * max((i - j) , dp[i - j]);
              dp[i] = max(dp[i] , product);
          }
        }
        return dp[n];
    }
};
