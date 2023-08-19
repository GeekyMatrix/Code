class Solution {
public:
//Greedy 
    bool canJump(vector<int>& nums) {
        int reach=0;
        for(int i=0;i<=reach;i++){
            reach=max(i+nums[i],reach);
            if(reach>=nums.size()-1) return true;
        }
        return false;
   }

// //Recursive
  bool solve(int i,vector<int>& nums){
      //Base case
      if(i>=nums.size()-1) return true;
        int reachable=i+nums[i];
        
        for(int k=i+1;k<=reachable;k++){
                  if(solve(k,nums))    return true;         
        }
        return false;
  }

    bool canJump(vector<int>& nums) {
    return solve(0,nums);
    }

//Memoization
  bool solve(int i,vector<int>& nums, vector<int>&t){
      //Base case
      if(i>=nums.size()-1) return true;

      if(t[i]!=-1) return t[i];

        int reachable=i+nums[i];
        
        for(int k=i+1;k<=reachable;k++){
                  if(solve(k,nums,t))    return t[i]=true;         
        }
        return t[i]=false;
  }

    bool canJump(vector<int>& nums) {
      vector<int>t(nums.size(),-1);
    return solve(0,nums,t);
    }
  
  //DP 
  bool canJump(vector<int>& nums) {
    int n=nums.size();

      vector<int>dp(n,0);
     dp[0]=true;
        
        for(int i=1;i<n;i++){
             for(int j=i-1;j>=0;j--){
                 if(dp[j] && j+nums[j]>=i){
                     dp[i]=true;
                     break;
                 }       
             }           
        }
        return dp[n-1];
    }
};
