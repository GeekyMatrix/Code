class Solution {
public:
//Recusion method
  int lcs(vector<int> &X,vector<int> &Y,int n,int m){
       //BASE CONDITION
      if(n==0||m==0) return 0;
      //CHOICE DIG.
      if(X[n-1]==Y[m-1])
      return 1+lcs(X,Y,n-1,m-1);
      else{
        return max(lcs(X,Y,n-1,m),lcs(X,Y,n,m-1));
      }
  }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        return lcs(nums1, nums2,n,m);
    }

//MEMOIZATION METHOD
 int lcs(vector<int> &X,vector<int> &Y,int n,int m,vector<vector<int>>t){
       //BASE CONDITION
      if(n==0||m==0) return 0;
       if(t[n][m]!=-1) return t[n][m];
      //CHOICE DIG.
      if(X[n-1]==Y[m-1])
      return t[n][m]=1+lcs(X,Y,n-1,m-1,t);
      else{
        return  t[n][m]=max(lcs(X,Y,n-1,m,t),lcs(X,Y,n,m-1,t));
      }
  }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
         vector<vector<int>>t(n+1,vector<int>(m+1,-1));
        return lcs(nums1, nums2,n,m,t);
    }

//DP METHOD
 int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
 int n=nums1.size();
 int m=nums2.size();

vector<vector<int>>t(n+1,vector<int>(m+1,0));
          for(int i=1;i<n+1;i++){ 
           for(int j=1;j<m+1;j++){
        if(nums1[i-1]== nums2[j-1]) t[i][j]=1+t[i-1][j-1];
        else
        t[i][j]=max(t[i-1][j],t[i][j-1]);
           }
          }
         return t[n][m];
 }
};
