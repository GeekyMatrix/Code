class Solution {
public:
//RECURSIVE METHOD
 int lcs(string s1, string s2,int x,int y)
    {
      // BASE CONDITION
      if(x==0||y==0) return 0;
      //CHOICE DIG.
      if(s1[x-1]==s2[y-1])
      return 1+lcs(s1,s2,x-1,y-1);
      else{
        return max(lcs(s1,s2,x-1,y),lcs(s1,s2,x,y-1));
      }
    }

 int longestPalindromeSubseq(string s) {
        string r=s;
        reverse(r.begin(),r.end());
        int n=s.size(),m=r.size();
        return lcs(s,r,n,m);
    }

//MEMOIZATION METHOD
int lcs(string s1, string s2,int x,int y,vector<vector<int>>&t)
    {
      // BASE CONDITION
      if(x==0||y==0) return 0;

      if(t[x][y]!=-1) return t[x][y];

      //CHOICE DIG.
      if(s1[x-1]==s2[y-1])
      return t[x][y]=1+lcs(s1,s2,x-1,y-1,t);
      else{
       return t[x][y]= max(lcs(s1,s2,x-1,y,t),lcs(s1,s2,x,y-1,t));
      }
    }
int longestPalindromeSubseq(string s) {
        string r=s;
        reverse(r.begin(),r.end());
        int n=s.size(),m=r.size();
         vector<vector<int>>t(n+1,vector<int>(m+1,-1));
        return lcs(s,r,n,m,t);
    }

//DP METHOD
    int lcs(string s1, string s2,int x,int y)
    {
        //INSERT 0 IN THE WHOLE MATRIX
         vector<vector<int> > t(x+ 1, vector<int>(y + 1, 0));
      for(int i=1;i<=x;i++){
          for(int j=1;j<=y;j++){
              if(s1[i-1]==s2[j-1]) t[i][j]=1+t[i-1][j-1];
              else
              t[i][j]=max(t[i-1][j],t[i][j-1]);
          }
      }
     
        return t[x][y];    
    }

    int longestPalindromeSubseq(string s) {
        string r=s;
        reverse(r.begin(),r.end());
        int n=s.size(),m=r.size();
        return lcs(s,r,n,m);
    }
};
