class Solution {
public:
//RECURSIVE METHOD
int solve(vector<int> nums,int i){
    //BASE CASE
    if(i<0) return 0;
    if(i==0) return nums[0];

    int incl=solve(nums,i-2)+nums[i];
    int excl=solve(nums,i-1)+0;
    return max(incl,excl);
}

    int rob(vector<int>& nums) {
        int n=nums.size();
        int ans=solve(nums,n-1);
        return ans;
    }

//MEMOIZATION METHOD
int solvemem(vector<int> &nums,int i,vector<int>&t){
   //BASE CASE
   if(i<0) return 0;
   if(i==0) return nums[0];
   if(t[i]!=-1) return t[i];
    
    int incl=solvemem(nums,i-2,t)+nums[i];
    int excl=solvemem(nums,i-1,t)+0;
    t[i]=max(incl,excl);
    return t[i];
}
 int rob(vector<int>& nums) {
int n=nums.size();
vector<int>t(n,-1);
return solvemem(nums,n-1,t);
 }

//DP
 int rob(vector<int>& nums) {
    int n=nums.size();
      if(n==1)     return nums[0];
        
 vector<int>dp(n,0);
 dp[0]=nums[0];
dp[1]=max(nums[0],nums[1]);
 for(int i=2;i<n;i++){
     int incl=dp[i-2]+nums[i];
     int excl=dp[i-1]+0;
     dp[i]=max(incl,excl);
 }
return dp[n-1];
 }

//Constant space
int rob(vector<int>& nums) {
    int n=nums.size();
      if(n==1)     return nums[0];

 int prev_prev=nums[0];
 int prev=max(nums[0],nums[1]);
 for(int i=2;i<n;i++){
     int incl=prev_prev+nums[i];
     int excl=prev+0;
    int temp=max(incl,excl);

   prev_prev=prev;
   prev=temp;
 }
return prev;
 }
};
