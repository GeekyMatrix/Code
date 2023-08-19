class Solution {
public:
//Greedy
    int jump(vector<int>& nums) {
        int farthest=0,jumps=0,curr=0;

        for(int i=0;i<nums.size()-1;i++){
            farthest=max(farthest,nums[i]+i);

            if(i==curr) {
                curr=farthest;
                jumps++;
            }
        }
        return jumps;
    }

//Recursion
  int solve(int i,vector<int>& nums){

      int farthest=i+nums[i];
      //Base case
      if(farthest>=nums.size()-1)  return 0;
      
      int mini_steps=1e7;

      for(int j=i+1;j<=farthest;j++){
      int jumps=1+solve(j,nums);
      mini_steps=min(mini_steps,jumps);
      }
   return mini_steps;
  }
    int jump(vector<int>& nums) {
    if(nums.size()==1) return 0;
    return solve(0,nums)+1;
    }

//Memoization
  int solve(int i,vector<int>& nums, vector<int>&t){

      int farthest=i+nums[i];
      //Base case
      if(farthest>=nums.size()-1)  return 0;
      
      if(t[i]!=-1) return t[i];
      int mini_steps=1e7;

      for(int j=i+1;j<=farthest;j++){
      int jumps=1+solve(j,nums,t);
      mini_steps=min(mini_steps,jumps);
      }
   return t[i]=mini_steps;
  }
    int jump(vector<int>& nums) {
    if(nums.size()==1) return 0;
    vector<int>t(nums.size()+1,-1);
    return solve(0,nums,t)+1;
    }
  
//DP
int jump(vector<int>& nums) {
    int n=nums.size();
    vector<int>dp(n,1e7);
     dp[0]=0;

    for(int i=0;i<n-1;i++){
      if(i+nums[i]>=n-1){
        dp[n-1]=min(dp[n-1],dp[i]+1);
        break;
      }
    for(int j=i+1;j<=i+nums[i];j++){
      dp[j]=min(dp[j],dp[i]+1);
    }
    }
    return dp[n-1];
    }
};
