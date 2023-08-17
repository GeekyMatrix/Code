class Solution {
public:
//Recursion method
int solve(int i,int j,vector<vector<int>>& triangle,int n, vector<vector<int>>&t){
 //BASE CASE
  if(i==n-1) return triangle[n-1][j];
  
  int d=triangle[i][j]+solve(i+1,j,triangle,n,t);
  int dg=triangle[i][j]+solve(i+1,j+1,triangle,n,t);
  
  return min(d,dg);
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        return solve(0,0,triangle,n,t);
    }

// //Memoization method
int solve(int i,int j,vector<vector<int>>& triangle,int n, vector<vector<int>>&t){
 //BASE CASE
  if(i==n-1) return triangle[n-1][j];
  
  if(t[i][j]!=-1) return t[i][j];

  int d=triangle[i][j]+solve(i+1,j,triangle,n,t);
  int dg=triangle[i][j]+solve(i+1,j+1,triangle,n,t);
  
  return t[i][j]=min(d,dg);
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>t(n,vector<int>(n,-1));
        return solve(0,0,triangle,n,t);
    }

//Dp method
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        
        for(int j=0;j<n;j++) dp[n-1][j]=triangle[n-1][j];  //BASE CASE 

        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
   int d=triangle[i][j]+dp[i+1][j];
  int dg=triangle[i][j]+dp[i+1][j+1];
  
  dp[i][j]=min(d,dg);
            }
        }
    return dp[0][0];
    }

//Dp method with space 
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
      vector<int>curr(n,0);
      vector<int>front(n,0);
        
        for(int j=0;j<n;j++) front[j]=triangle[n-1][j];  //BASE CASE 

        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
   int d=triangle[i][j]+front[j];
  int dg=triangle[i][j]+front[j+1];
  
  curr[j]=min(d,dg);
            }
    front=curr;
        }
    return front[0];
    }
};
