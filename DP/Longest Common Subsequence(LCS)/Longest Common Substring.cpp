//Ye changes honge LCS wale se

//DP METHOD
    int longestCommonSubstring(string X, string Y) {
      int count=0;
        int n=X.length();
        int m=Y.length();
        vector<vector<int>>t(n+1,vector<int>(m+1,0));
          for(int i=1;i<n+1;i++){ 
           for(int j=1;j<m+1;j++){
        if(X[i-1]==Y[j-1]) t[i][j]=1+t[i-1][j-1];
          count=max(count,t[i][j]);
        else
        t[i][j]=0;
           }
          }
         return count;

    }
};
