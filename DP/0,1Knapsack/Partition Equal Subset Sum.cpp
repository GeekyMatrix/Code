class Solution {
public:
//MEMOIZATION METHOD

bool f(vector<int>arr,int n,int target, vector<vector<int>>t ){
      if(target==0) return true;
      if(n==0) return target==0?true:false;
      
      if (t[n][ target]!= -1) return t[n][target];
  
      if(arr[n-1]<=target)  return t[n][target]= f(arr,n-1,target-arr[n-1],t)|| f(arr,n-1,target,t);
      
      else if(arr[n-1]>target)  return t[n][target]= f(arr,n-1,target,t);
      
      return false;
  }
  //CODE HERE
    bool canPartition(vector<int>& nums) {
        int sum1 = 0;
        int n=nums.size();
        for(int i = 0; i < nums.size(); i++) sum1 += nums[i];
        if(sum1%2 != 0) return false;
       int target=sum1/2;
        vector<vector<int>>t (n+1,vector<int>(target+1,-1));
       return f(nums,n,target,t);
    }

//DP METHOD

    bool solve(vector<int>& nums, int n,  int sum,  vector<vector<int>>&dp) {
     
            for(int i=0;i<n+1;i++){
                for(int j=0;j<sum+1;j++){
                    if(i==0) dp[i][j]=false;
                    if(j==0) dp[i][j]=true;
                }
            }

        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(nums[i-1]<=j)   dp[i][j]=(dp[i-1][j-nums[i-1]]||dp[i-1][j]);

                 else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
      bool canPartition(vector<int>& nums) {
        int sum1 = 0;
        int n=nums.size();
        for(int i = 0; i < nums.size(); i++) sum1 += nums[i];
        if(sum1%2 != 0) return false;
       int sum=sum1/2;
        vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
       return solve(nums,n,sum,dp);
    }
};
