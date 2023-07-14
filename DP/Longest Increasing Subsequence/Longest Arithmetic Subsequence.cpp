class Solution {
public:
//RECURSIVE METHOD

int n;
  int solve(vector<int>& nums,int i,int d){
      if(i<0) return 0;

      int ans=0;
      for(int k=i-1;k>=0;k--){ //left side going
      if(nums[i]-nums[k]==d) ans=max(ans,1+solve(nums,k,d));

      }
      return ans;
  }
    int longestArithSeqLength(vector<int>& nums) {
        n=nums.size();
        if(n<=2) return n;

        int result=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int d=nums[j]-nums[i];
              result=max(result,2+solve(nums,i,d));
            }
        }
        return result;
    }

//MEMOIZATION METHOD

int n;
int t[1001][1003];
  int solve(vector<int>& nums,int i,int d){
      if(i<0) return 0;
      int ans=0;

      if(t[i][d+501]!=-1) return t[i][d+501];

      for(int k=i-1;k>=0;k--){ //left side going
      if(nums[i]-nums[k]==d) ans=max(ans,1+solve(nums,k,d));

      }
      return t[i][501]=ans;
  }
    int longestArithSeqLength(vector<int>& nums) {
        n=nums.size();
        if(n<=2) return n;
        
        memset(t,-1,sizeof(t));
        int result=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int d=nums[j]-nums[i];
              result=max(result,2+solve(nums,i,d));
            }
        }
        return result;
    }
  
// DP APPROACH WITH LIS METHOD

 int longestArithSeqLength(vector<int>& nums) {
   int n=nums.size();
 vector<vector<int>>dp(n,vector<int>(1001,0));
 //t[i][diff]=Longest Arithmetic Subsequence ending at ith index with c.d=diff

 int result=0;

 for(int i=1;i<n;i++){
   for(int j=0;j<i;j++){
     int diff=nums[i]-nums[j]+500;   //to avoid -ve diff

     dp[i][diff]=dp[j][diff]>0?1+dp[j][diff]:2;
     result=max(result,dp[i][diff]);
   }
 }
     return result;
 }
};
