class Solution {
public:
//Recursive without for loop
int n;
int solve(int idx,vector<int>& nums,int target){
    //BASE CASE
    if(idx>=n || target<0) return 0;
    if(target==0) return 1;
   
   int take_idx=solve(0,nums,target-nums[idx]);

   int reject_idx=solve(idx+1,nums,target);
  
  return take_idx + reject_idx;
}
  int combinationSum4(vector<int>& nums, int target) {
      n = nums.size();
  return solve(0,nums,target);
  }

//Recursive Method
int solve(vector<int>& nums,int target){
    //BASE CASE
    if(target<0) return 0;
    if(target==0) return 1;
   
   int ans=0;
    for(int i=0;i<nums.size();i++){
     ans+=solve(nums,target-nums[i]);
    }
    return ans;
}
    int combinationSum4(vector<int>& nums, int target) {
        return solve(nums,target);
    }

// Memoization Method
int solve(vector<int>& nums,int target,  vector<int>&t){
    //BASE CASE
    if(target<0) return 0;
    if(target==0) return 1;
   
   if(t[target]!=-1) return t[target];
   int ans=0;
    for(int i=0;i<nums.size();i++){
     ans+=solve(nums,target-nums[i],t);
    }
    t[target]=ans;
    return  t[target];
}
 int combinationSum4(vector<int>& nums, int target) {
     vector<int>t(target+1,-1);
        return solve(nums,target,t);
//     }

//DP method
int combinationSum4(vector<int>& nums, int target) {
vector< unsigned int> dp (target+1, 0); //STORE THE NO OF WAYS IN WHICH WE GET ith INDEX SUM;
        dp[0] = 1;
        for(int i = 1; i <= target; i++)
        {
            for(int j = 0; j < nums.size(); j++)
            {
         if(i - nums[j] >= 0) //IF INDEX IS PRESENT i.e. INDEX SHOULD BE GREATER THAN OR EQUAL TO 0.
                    dp[i] += dp[i - nums[j]];
            }
        }
        return dp[target];
   }
};
