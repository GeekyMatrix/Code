class Solution {
public:
int lengthOfLIS(vector<vector<int>>& nums) {
     int n=nums.size();
  vector<int>dp(n);
  for(int i=0;i<n;i++) dp[i]=nums[i][2];

   for(int i=1;i<n;i++){
       for(int j=0;j<i;j++){
if(nums[i][0] >= nums[j][0] && nums[i][1] >= nums[j][1] && nums[i][2] >= nums[j][2]) {
            dp[i]=max(dp[i],*max_element(nums[i].begin(),nums[i].end())+dp[j]);
           }
       }
   }
   return *max_element(dp.begin(),dp.end());
 }

    int maxHeight(vector<vector<int>>& cuboids) {
        //Step1:sort all dimensions for every cuboid
        for(auto &a:cuboids) sort(a.begin(),a.end());

        //Step 2:Sort all cuboids on the basis of W or L
        sort(cuboids.begin(),cuboids.end());

        //step 3:Use LIS logic
         return lengthOfLIS(cuboids);
    }
};
