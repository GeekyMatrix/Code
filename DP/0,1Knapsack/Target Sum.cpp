class Solution {
public:
//RECURSIVE METHOD

int f(vector<int>&arr,int sum,int n){
      if(sum<0) return 1;
      if(n<=0){
          return sum==0?1:0;
      }
      int nontake=0;
      int take=0;
      if(arr[n-1]<=sum){
        take= f(arr,sum-arr[n-1],n-1)+ f(arr,sum,n-1);
      }
      else if(arr[n-1]>sum){
        nontake=f(arr,sum,n-1);
      }
      return take+nontake;
  }
    int findTargetSumWays(vector<int>& nums, int target) {
         int sum=0;
         int n=nums.size();
         for(int i=0;i<n;i++) sum+=nums[i];
         if(target>sum||(sum-target)%2) return 0;
	     int reqSum=(target+sum)/2;
         if(reqSum<0) return 0;
	     return f(nums,reqSum,n);
    }

//MEMOIZATION METHOD
int f(vector<int>&arr,int sum,int n, vector<vector<int>>t){
      if(sum<0) return 1;
      if(n<=0){
          return sum==0?1:0;
      }
      if(t[n][sum] != -1) return t[n][sum];
      int nontake=0;
      int take=0;
      if(arr[n-1]<=sum){
        return t[n][sum]= f(arr,sum-arr[n-1],n-1,t)+ f(arr,sum,n-1,t);
      }
      else if(arr[n-1]>sum){
       return t[n][sum]=f(arr,sum,n-1,t);
      }
      return 0;
  }
    int findTargetSumWays(vector<int>& nums, int target) {
         int sum=0;
         int n=nums.size();
         for(int i=0;i<n;i++) sum+=nums[i];
         if(target>sum||(sum-target)%2) return 0;
	     int reqSum=(target+sum)/2;
         if(reqSum<0) return 0;
          vector<vector<int>>t(n+1, vector<int>(target + 1, -1));
	     return f(nums,reqSum,n,t);
    }

//DP METHOD
  int subsetSum(vector<int> &a, int n, int sum)
{
    // Initializing the matrix
    int dp[n + 1][sum + 1];
  // Initializing the first value of matrix
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
              if(i==0) dp[i][j]=0;
                  if(j==0) dp[i][j]=1;
            }
        }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
          // if the value is greater than the sum
            if (a[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i - 1]]; 
            else
                  dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][sum];
}

    int findTargetSumWays(vector<int>& nums, int target) {
          int sum=0;
          int n=nums.size();
    for(int i=0;i<n;i++) sum+=nums[i];
    if(target>sum||(sum-target)%2) return 0;
	 int reqSum=(target+sum)/2;
     if(reqSum<0) return 0;
	 return subsetSum(nums,n,reqSum);
    }
};


