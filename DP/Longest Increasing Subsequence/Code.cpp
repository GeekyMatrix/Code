class Solution {
public:
//RECURSION METHOD

int helper(int n,vector<int>& nums,int curr,int prev){
//BASE CASE
if(curr==n) return 0;
//INCLUDE
int take=0;
if(prev==-1||nums[curr]>nums[prev]) take=1+helper(n,nums,curr+1,curr);
//EXCLUDE
int notTake=0+helper(n,nums,curr+1,prev);

return max(take,notTake);
}
//MAIN FUNCTION
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        return helper(n,nums,0,-1);
    }

//MEMOIZATION METHOD

int helper(int n,vector<int>& nums,int curr,int prev,vector<vector<int>>&t){
//BASE CASE
if(curr==n) return 0;
if(t[curr][prev+1]!=-1) return t[curr][prev+1];
//INCLUDE
int take=0;
if(prev==-1||nums[curr]>nums[prev]) take=1+helper(n,nums,curr+1,curr,t);
//EXCLUDE
int notTake=0+helper(n,nums,curr+1,prev,t);

return t[curr][prev+1]= max(take,notTake);
}
//MAIN FUNCTION
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
       vector<vector<int>>t(n,vector<int>(n+1,-1));
        return helper(n,nums,0,-1,t);
    }

//DP METHOD

TC=O(n^2),S.C=O(n^2)
int helper(int n,vector<int>& nums){
   vector<vector<int>>dp(n+1,vector<int>(n+1,0));

for(int curr=n-1;curr>=0;curr--){
    for(int prev=curr-1;prev>=-1;prev--){
        //INCLUDE
        int take=0;
        if(prev==-1||nums[curr]>nums[prev]) take=1+dp[curr+1][curr+1];
        //EXCLUDE
        int NotTake=0+dp[curr+1][prev+1];

    dp[curr][prev+1]=max(take,NotTake);
    }
}
   return dp[0][0];
}

 //MAIN FUNCTION
int lengthOfLIS(vector<int>& nums) {
   int n=nums.size();
   return helper(n,nums);

}

//DP WITH SPACE OPTIMIZATION 

TC=O(n^2),S.C=O(n)
int helper(int n,vector<int>& nums){

    vector<int>currRow(n+1,0);
    vector<int>nextRow(n+1,0);

for(int curr=n-1;curr>=0;curr--){
    for(int prev=curr-1;prev>=-1;prev--){
        //INCLUDE
        int take=0;
        if(prev==-1||nums[curr]>nums[prev]) take=1+nextRow[curr+1];
        //EXCLUDE
        int NotTake=0+nextRow[prev+1];

    currRow[prev+1]=max(take,NotTake);
    }
    nextRow=currRow;
}
   return nextRow[0];
}

  //MAIN FUNCTION
int lengthOfLIS(vector<int>& nums) {
   int n=nums.size();
   return helper(n,nums);
}

//DP METHOD

 int lengthOfLIS(vector<int>& nums) {
     int maxlength=1;
     int n=nums.size();
  vector<int>dp(n,1);

   for(int i=1;i<n;i++){
       for(int j=0;j<i;j++){
           if(nums[j]<nums[i]) {
            dp[i]=max(dp[i],dp[j]+1);
            maxlength=max(maxlength,dp[i]);
           }
       }
   }
   return maxlength;
 }

//DP WITH BINARY SEARCH METHOD

int helper(int n,vector<int>& nums){
if(n==0) return 0;
vector<int>ans;
ans.push_back(nums[0]);

for(int i=1;i<n;i++){
    //AGAR AAGE BDA MIL RHA HAI TOH AAD KRTE JAO
    if(nums[i]>ans.back()) ans.push_back(nums[i]);
    else{
    //AGAR CHOTA MIL RHA HAI TOH ans ko change krro
    
    //Find index of just bdda element in ans
    int index=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
    ans[index]=nums[i];
    }
}
  return ans.size();
}
 int lengthOfLIS(vector<int>& nums) {
   int n=nums.size();
   return helper(n,nums);
}

};
