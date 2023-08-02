class Solution {
public:
//BRUTE FORCE
    bool isSubsequence(string s, string t) {
        int i=0;
        for(auto&x:t){
            if(x==s[i]) i++;
        }
        return (i==s.size()?true:false);
    }

//DP METHOD (LCS CODE )
 bool isSubsequence(string  X, string Y) {
 int n=X.length();
        int m=Y.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
          for(int i=1;i<n+1;i++){ 
           for(int j=1;j<m+1;j++){
        if(X[i-1]==Y[j-1]) dp[i][j]=1+dp[i-1][j-1];
        else
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
           }
          }
          int res=dp[n][m];
          if(res==n) return true;
         return false ;

 }
};
