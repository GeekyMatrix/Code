class Solution {
public:
   //MEMOIZATION METHOD
int helper(int i,int amount,vector<vector<int>>&t,vector<int>& coins){
    if(i==0){
        if(amount%coins[0]==0) return amount/coins[0];
        else return INT_MAX-1;
    }
    if(t[i][amount]!=-1) return t[i][amount];
   int notTake=helper(i-1,amount,t,coins)+0;
   int Take=INT_MAX-1;
   if(coins[i]<=amount) Take=helper(i,amount-coins[i],t,coins)+1;
   return t[i][amount]=min(notTake,Take);
}
int coinChange(vector<int>& coins, int amount) {
    int n=coins.size();
vector<vector<int>>t(n,vector<int>(amount+1,-1));
int ans=helper(n-1,amount,t,coins);
if(ans==INT_MAX-1) return -1;
return ans;
}

//DP METHOD
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        if(amount==0) return 0;

        //FILL THE WHOLE MATRIX WITH 0
        vector<vector<int>>dp(n+1,vector<int>(amount+1,0));

        //FILL THE IST ROW WITH INT_MAX-1
        for(int i=0;i<=amount;i++) dp[0][i]=INT_MAX-1;

        //FILL THE 2nd ROW WITH 1 or INT_MAX-1
        for(int i=1;i<=amount;i++){
            if(i%coins[0]==0) dp[1][i]=i/coins[0];
            else dp[1][i]=INT_MAX-1;
        }
    
        //FILL THE REST PART OF MATRIX
        for(int i=2;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1]<=j) dp[i][j]=min(dp[i-1][j],dp[i][j-coins[i-1]]+1);
                else dp[i][j]=dp[i-1][j];
            }
        }
        if(dp[n][amount]==INT_MAX-1) return -1;
        return dp[n][amount];
    }
};
