class Solution {
public:
//RECURSION 
  int solve(string a,string b,int i,int j){
  //BASE CASE
  if(i==a.length()) return b.length()-j;
  if(j==b.length()) return a.length()-i;

 int ans=0;
 if(a[i]==b[j]) return solve(a,b,i+1,j+1);

 else{
    int insertAns= 1+solve(a,b,i,j+1);//INSERT
   
    int deleteAns= 1+solve(a,b,i+1,j);//DELETE

    int ReplaceAns= 1+solve(a,b,i+1,j+1);//REPLACE

    ans=min(insertAns,min(deleteAns,ReplaceAns));
 }
   return ans;
  }
    int minDistance(string word1, string word2) {
       return solve(word1,word2,0,0);
    }

//MEMOIZATION
 int solve(string a,string b,int i,int j, vector<vector<int>>&t){
  //BASE CASE
  if(i==a.length()) return b.length()-j;
  if(j==b.length()) return a.length()-i;
 
 if(t[i][j]!=-1) return t[i][j];
  int ans=0;
 if(a[i]==b[j]) return solve(a,b,i+1,j+1,t);

 else{
    int insertAns= 1+solve(a,b,i,j+1,t);//INSERT
   
    int deleteAns= 1+solve(a,b,i+1,j,t);//DELETE

    int ReplaceAns= 1+solve(a,b,i+1,j+1,t);//REPLACE

    ans=min(insertAns,min(deleteAns,ReplaceAns));
 }
   return t[i][j]=ans;
  }
    int minDistance(string word1, string word2) {
      vector<vector<int>>t(word1.length(),vector<int>(word2.length(),-1));
       return solve(word1,word2,0,0,t);
    }

//DP
    int solve(string a,string b){
    vector<vector<int>>dp(a.length()+1,vector<int>(b.length()+1,0));
   
   for(int j=0;j<b.length();j++)   dp[a.length()][j]=b.length()-j;
   
   for(int i=0;i<a.length();i++)   dp[i][b.length()]=a.length()-i;

   for(int i=a.length()-1;i>=0;i--){
     for(int j=b.length()-1;j>=0;j--){
        int ans=0;
        if(a[i]==b[j]) ans= dp[i+1][j+1];

 else{
    int insertAns= 1+ dp[i][j+1];//INSERT
   
    int deleteAns= 1+ dp[i+1][j];//DELETE

    int ReplaceAns= 1+ dp[i+1][j+1];//REPLACE

    ans=min(insertAns,min(deleteAns,ReplaceAns));
 }
    dp[i][j]=ans;
     }
   }
  return dp[0][0];
    }
      int minDistance(string word1, string word2) {
       return solve(word1,word2);
    }
};
