class Solution {
public:
//RECURSIVE METHOD
int helper(int i,int j){
    //BASE CASE
    if(i==0&&j==0) return 1;
    if(i<0||j<0) return 0;
    //FUNCTION CALL
   int up=helper(i-1,j);
   int left=helper(i,j-1);
   return up+left;
}
int uniquePaths(int m, int n) {
   return helper(m-1,n-1);
}

//MEMOIZATION METHOD
int helper(int i,int j,vector <vector<int>> &t){
    //BASE CASE
    if(i==0&&j==0) return 1;
    if(i<0||j<0) return 0;
    if(t[i][j]!=-1) return t[i][j];
    //FUNCTION CALL
   int up=helper(i-1,j,t);
  int left=helper(i,j-1,t);
   return  t[i][j]=left+up;
}
int uniquePaths(int m, int n) {
        vector <vector<int>> t(m,vector<int>(n,-1));
        return helper(m-1,n-1,t);
    }

//DP METHOD
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,1));
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
     return dp[m-1][n-1];
    }
};
