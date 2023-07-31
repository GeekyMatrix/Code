class Solution {
public:
int t[101];
 int solve(vector<int>& nums,int i,int n){
  if(i>n) return 0;

       if(t[i] != -1) return t[i];
        
int take = nums[i] + solve(nums, i+2, n); //steals ith house and moves to i+2 (because we can't steal adjacent)
int skip = solve(nums, i+1, n); //skips this house, now we can move to adjacent next house
        
        return t[i]=max(take, skip);
    }

    int rob(vector<int>& nums) {
        int n=nums.size();

        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);

        memset(t,-1,sizeof(t));

        // case->1 -Take first house 0th index wala house
        int take_0th_index_house=solve(nums,0,n-2);

         memset(t,-1,sizeof(t));

        // case->2 -Take second house 1th index wala house
        int take_1th_index_house=solve(nums,1,n-1);

        return max(take_0th_index_house,take_1th_index_house);
    }

//DP METHOD
   int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return nums[0];
        
        vector<int> dp(n+1, 0);
        //dp[i] = Max money gained from i houses
        
        //Case-1 (Take from 1st House - Hence skip the last house)
        dp[0] = 0;
        for(int i = 1; i<=n-1; i++) {
            int take=nums[i-1]+ ((i-2 >= 0) ? dp[i-2] : 0);
            int skip=dp[i-1];
            dp[i] = max(take ,skip);
        }
       int result1 = dp[n-1];
        
        dp.clear();
        //Case-2 (Take from 2nd House - Hence take the last house)
        dp[0] = 0;
        dp[1] = 0; //skip ist house
        for(int i = 2; i<=n; i++) {
            int take=nums[i-1]+((i-2 >= 0) ? dp[i-2] : 0);
            int skip=dp[i-1];
            dp[i] = max(take ,skip);
        }
       int result2 = dp[n];
        
        return max(result1, result2);
        
    }

//Constant space

int solve(vector<int>& nums,int l,int r){
 int prev=0;
 int prev_prev=0;

 for(int i=l;i<=r;i++){
 int take=nums[i]+prev_prev;
 int skip=prev;

 int temp=max(take,skip);

 prev_prev=prev;
 prev=temp;
 }
 return prev;
}

    int rob(vector<int>& nums) {
        int n=nums.size();

        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);

        // case->1 -Take first house 0th index wala house
        int take_0th_index_house=solve(nums,0,n-2);


        // case->2 -Take second house 1th index wala house
        int take_1th_index_house=solve(nums,1,n-1);

        return max(take_0th_index_house,take_1th_index_house);
    }
};
