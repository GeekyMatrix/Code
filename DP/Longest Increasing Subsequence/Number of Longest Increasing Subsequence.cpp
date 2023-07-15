class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int ans=0;
         int maxlength=1;
     int n=nums.size();
  vector<int>dp(n,1),count(n,1);

   for(int i=1;i<n;i++){
       for(int j=0;j<i;j++){
           if(nums[j]<nums[i]  && dp[j]+1>dp[i]) {
            dp[i]=max(dp[i],dp[j]+1);
            maxlength=max(maxlength,dp[i]);
            count[i]=count[j];
           }

           else if(nums[j]<nums[i] && 1+dp[j]==dp[i]) count[i]+=count[j];  //increase the count
       }
   }

   for(int i=0;i<n;i++){
       if(dp[i]==maxlength) ans+=count[i];
   }
     return ans;
    }
};
