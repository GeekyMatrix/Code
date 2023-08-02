class Solution {
public:
//Recusive method
 int solve(int n){
     //BASE CASE
     if(n==0) return 0;
     int ans=n;

     for(int i=1;i*i<=n;i++){
         int temp=i*i;
         ans=min(ans,1+solve(n-temp));
     }
     return ans;
 }
    int numSquares(int n) {
        return solve(n);
    }

//Memoization method
 int solve(int n, vector<int>&t){
     //BASE CASE
     if(n==0) return 0;
     int ans=n;
     if(t[n]!=-1) return t[n];
     for(int i=1;i*i<=n;i++){
         int temp=i*i;
         ans=min(ans,1+solve(n-temp,t));
     }
     t[n]=ans;
     return t[n];
 }
int numSquares(int n) {
    vector<int>t(n+1,-1);
        return solve(n,t);
    }

//DP method
int numSquares(int n) {
vector<int>dp(n+1,INT_MAX);
dp[0]=0;

for(int i=1;i<=n;i++){
    for(int j=1;j*j<=n;j++){
     int temp=j*j;
     if(i-temp>=0) dp[i]=min(dp[i],1+dp[i-temp]);
    }
}
return dp[n];
}
};
