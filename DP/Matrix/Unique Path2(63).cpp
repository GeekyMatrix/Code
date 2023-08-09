class Solution {
public:
//Recursive Method
  int helper(int i,int j,vector<vector<int>>& obstacleGrid){
      //BASE CASE
      if((i>=0 && j>=0) && (obstacleGrid[i][j]==1)) return 0;
      if(i==0 && j==0)  return 1;
      if(i<0 || j<0)     return 0;
      
      int up=helper(i-1,j,obstacleGrid);
      int left=helper(i,j-1,obstacleGrid);

      return up+left;
   }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();

        return helper(m-1,n-1,obstacleGrid);
    }

//Memoization method
  int helper(int i,int j,vector<vector<int>>& obstacleGrid,vector<vector<int>>&t){
      //BASE CASE
      if((i>=0 && j>=0) && (obstacleGrid[i][j]==1)) return 0;
      if(i==0 && j==0)  return 1;
      if(i<0 || j<0)    return 0;
      
      if(t[i][j]!=-1) return t[i][j];

      int up=helper(i-1,j,obstacleGrid,t);
      int left=helper(i,j-1,obstacleGrid,t);

      return t[i][j]=up+left;
   }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
          vector<vector<int>>t(m+1,vector<int>(n+1,-1));
        return helper(m-1,n-1,obstacleGrid,t);
    }

//DP method
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int up, left = 0;
                if(i >= 0 && j >= 0 && obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else if(i == 0 && j == 0) dp[i][j] = 1;
                else {
                    if(i > 0) up = dp[i-1][j];
                    if(j > 0) left = dp[i][j-1];
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};
