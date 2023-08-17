class Solution {
public:
//Recusive method
 int solve(int i,int j,vector<vector<int>>& matrix){
     //BASE CASE
     if(j<0 || j>=matrix[0].size()) return 1e9; //out of matrix
     if(i==0) return matrix[0][j];

     int u=matrix[i][j]+solve(i-1,j,matrix);
     int ld=matrix[i][j]+solve(i-1,j-1,matrix);
     int rd=matrix[i][j]+solve(i-1,j+1,matrix);

     return min(u,min(ld,rd));

 }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int mini=1e9;

        for(int j=0;j<m;j++)  mini=min(mini,solve(n-1,j,matrix));

        return mini;
    }

//Memoization 
 int solve(int i,int j,vector<vector<int>>& matrix, vector<vector<int>>&t){
     //BASE CASE
     if(j<0 || j>=matrix[0].size()) return 1e9; //out of matrix
     if(i==0) return matrix[0][j];
    
    if(t[i][j]!=-1) return t[i][j];

     int u=matrix[i][j]+solve(i-1,j,matrix,t);
     int ld=matrix[i][j]+solve(i-1,j-1,matrix,t);
     int rd=matrix[i][j]+solve(i-1,j+1,matrix,t);

     return t[i][j]=min(u,min(ld,rd));

 }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int mini=1e9;
       vector<vector<int>>t(n,vector<int>(m,-1));
        for(int j=0;j<m;j++)  mini=min(mini,solve(n-1,j,matrix,t));

        return mini;
    }

//DP
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int mini=1e9;
       vector<vector<int>>dp(n,vector<int>(m,0));
       
       for(int j=0;j<m;j++) dp[0][j]=matrix[0][j];   //Base Case

       for(int i=1;i<n;i++){
           for(int j=0;j<m;j++){

     int u=matrix[i][j]+dp[i-1][j];

     int ld=matrix[i][j];
     if(j-1>=0)  ld+=dp[i-1][j-1];
     else  ld+=1e9;
  
     int rd=matrix[i][j];
      if(j+1<m) rd+=dp[i-1][j+1];
      else rd+=1e9;

       dp[i][j]=min(u,min(ld,rd));
           }
       }

        for(int j=0;j<m;j++)  mini=min(mini,dp[n-1][j]);

        return mini;
    }

//Dp with space optimisation
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int mini=1e9;
      vector<int>prev(n,0);
      vector<int>curr(n,0);
       
       for(int j=0;j<m;j++) prev[j]=matrix[0][j];   //Base Case

       for(int i=1;i<n;i++){
           for(int j=0;j<m;j++){

     int u=matrix[i][j]+prev[j];

     int ld=matrix[i][j];
     if(j-1>=0)  ld+=prev[j-1];
     else  ld+=1e9;
  
     int rd=matrix[i][j];
      if(j+1<m) rd+=prev[j+1];
      else rd+=1e9;

       curr[j]=min(u,min(ld,rd));
           }
           prev=curr;
       }

        for(int j=0;j<m;j++)  mini=min(mini,prev[j]);

        return mini;
    }
};
