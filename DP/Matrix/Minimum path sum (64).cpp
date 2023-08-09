class Solution {
public:
//Recusive Method
int solve(int i,int j,vector<vector<int>>& grid){
  if(i==0 && j==0) return grid[0][0];
  if(i<0 || j<0) return 1e9; //Maximum value lelo

   int up=grid[i][j]+solve(i-1,j,grid);
   int left=grid[i][j]+solve(i,j-1,grid);

   return min(up,left);

}
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        return solve(m-1,n-1,grid);
    }

//Memoization method
int t[201][201];
int solve(int i,int j,vector<vector<int>>& grid){
  if(i==0 && j==0) return grid[0][0];
  if(i<0 || j<0) return 1e9; //Maximum value lelo
  
  if(t[i][j]!=-1) return t[i][j];

   int up=grid[i][j]+solve(i-1,j,grid);
   int left=grid[i][j]+solve(i,j-1,grid);

   return t[i][j]=min(up,left);

}
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        memset(t,-1,sizeof(t));

        return solve(m-1,n-1,grid);
    }

//DP Method
 int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
       vector<vector<int>>dp(m+1,vector<int>(n+1,0));
      for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
              if(i==0 && j==0) dp[0][0]=grid[0][0];
            
             else {    
                  int up=grid[i][j];
                if(i>0) up+=dp[i-1][j];
                else up+=1e9;

                int left=grid[i][j];
                if(j>0) left+=dp[i][j-1];
                 else left+=1e9;

                        dp[i][j]=min(up,left);
             }
          }
      }
      return dp[m-1][n-1];
    }

//Dp with space optimisation
 int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
   
       vector<int>prev(n,0);
        vector<int>curr(n,0);
      for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
              if(i==0 && j==0) curr[j]=grid[i][j];
            
             else {    
                  int up=grid[i][j];
                if(i>0) up+=prev[j];
                else up+=1e9;

                int left=grid[i][j];
                if(j>0) left+=curr[j-1];
                 else left+=1e9;

                        curr[j]=min(up,left);
             }
          }
          prev=curr;
      }
      return prev[n-1];
    }
};
