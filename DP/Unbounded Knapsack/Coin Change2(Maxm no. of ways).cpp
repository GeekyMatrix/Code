lass Solution {
public:
//RECURSIVE 
 int ans=0;
  int solve(int amount, vector<int>& coins,int n) {
  if(n==0) return 0;
  if(amount==0) return 1;

  if(coins[n-1]<=amount) ans=solve(amount-coins[n-1],coins,n)+solve(amount,coins,n-1);

 else if(coins[n-1]>amount)  ans=solve(amount,coins,n-1);

  return ans;
  }

int change(int amount, vector<int>& coins) {
  int n=coins.size();
  return solve(amount,coins,n);
  
}

//MEMOIZATION METHOD
  int solve(int amount, vector<int>& coins,int n, vector<vector<int>>&t) {
  if(n==0) return 0;
  if(amount==0) return 1;
  
  if(t[n][amount]!=-1) return t[n][amount];

if(coins[n-1]<=amount) 
  t[n][amount]=solve(amount-coins[n-1],coins,n,t)+solve(amount,coins,n-1,t);

 else if(coins[n-1]>amount)  t[n][amount]=solve(amount,coins,n-1,t);

  return t[n][amount];
  }

int change(int amount, vector<int>& coins) {
  int n=coins.size();
   vector<vector<int>>t(n+1,vector<int>(amount+1,-1));
  return solve(amount,coins,n,t);
} 
//DP METHOD
    int change(int amount, vector<int>& coins) {
         int n=coins.size();
        int m=amount;
     int dp[n+1][m+1];
     //FILL THE IST ROW& IST COL OF THE MATRIX
     for(int i=0;i<=n;i++){
         for(int j=0;j<=m;j++){
             if(i==0) dp[i][j]=0;
             if(j==0) dp[i][j]=1;
         }
     }
     //FILL THE REST OF THE MATRIX
     for(int i=1;i<=n;i++){
         for(int j=1;j<=m;j++){
             if(coins[i-1]<=j){
                 dp[i][j]=(dp[i][j-coins[i-1]]+dp[i-1][j]);
             }
             else{
                 dp[i][j]=dp[i-1][j];
             }
         }
     }
       return dp[n][m]; 
    }
};
