class Solution {
public:
//Recursion
  int solve(vector<vector<char>>&matrix,int i,int j,int &maxi){
  if(i>=matrix.size() || j>=matrix[0].size()) return 0;

  int right=solve(matrix,i,j+1,maxi);
  int diagonal=solve(matrix,i+1,j+1,maxi);
  int down=solve(matrix,i+1,j,maxi);

  if(matrix[i][j]=='1') {
      int ans=1+min(right,min(diagonal,down));
      maxi=max(maxi,ans);
      return ans;
  }
  else return 0;
  }
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi=0;
        solve(matrix,0,0,maxi);
        return maxi*maxi;
 }

//Memoization
  int solve(vector<vector<char>>&matrix,int i,int j,int &maxi,vector<vector<int>>&t){
  if(i>=matrix.size() || j>=matrix[0].size()) return 0;
  
  if(t[i][j]!=-1) return t[i][j];

  int right=solve(matrix,i,j+1,maxi,t);
  int diagonal=solve(matrix,i+1,j+1,maxi,t);
  int down=solve(matrix,i+1,j,maxi,t);

  if(matrix[i][j]=='1') {
      t[i][j]=1+min(right,min(diagonal,down));
      maxi=max(maxi,t[i][j]);
      return t[i][j];
  }
  else return t[i][j]=0;
  }
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxi=0;
        vector<vector<int>>t(n,vector<int>(m,-1));
        solve(matrix,0,0,maxi,t);
        return maxi*maxi;
    }

//DP
int solve(vector<vector<char>>&matrix,int &maxi){
     int n=matrix.size();
     int m=matrix[0].size();
 vector<vector<int>>dp(n+1,vector<int>(m+1,0));
   
   for(int i=n-1;i>=0;i--){
       for(int j=m-1;j>=0;j--){

  int right=dp[i][j+1];
  int diagonal=dp[i+1][j+1];
  int down=dp[i+1][j];

  if(matrix[i][j]=='1') {
      dp[i][j]=1+min(right,min(diagonal,down));
      maxi=max(maxi,dp[i][j]);
  }
   else  dp[i][j]=0;
       }
   }
   return dp[0][0];
}
 int maximalSquare(vector<vector<char>>& matrix) {
        int maxi=0;
        solve(matrix,maxi);
        return maxi*maxi;
    }

//DP With space optimisation
int solve(vector<vector<char>>&matrix,int &maxi){
     int n=matrix.size();
     int m=matrix[0].size();
 vector<int>curr(m+1,0);
  vector<int>next(m+1,0);

   for(int i=n-1;i>=0;i--){
       for(int j=m-1;j>=0;j--){

  int right=curr[j+1];
  int diagonal=next[j+1];
  int down=next[j];

  if(matrix[i][j]=='1') {
      curr[j]=1+min(right,min(diagonal,down));
      maxi=max(maxi,curr[j]);
  }
   else  curr[j]=0;
       }
       next=curr;
   }
   return next[0];
}
 int maximalSquare(vector<vector<char>>& matrix) {
        int maxi=0;
        solve(matrix,maxi);
        return maxi*maxi;
    }
};
