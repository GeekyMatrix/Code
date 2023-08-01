class Solution {
public:
//RECURSIVE METHOD +Memoization method
int solve(vector<int> &values,int i, vector<int>&t){
    //BASE CASE
    if(i<0) return 0;
     if(t[i]!=-1) return t[i];

    int incl=solve(values,i-2,t)+values[i];
    int excl=solve(values,i-1,t)+0;
    return t[i]=max(incl,excl);
}
          
    int deleteAndEarn(vector<int>& nums) {
        int n=10001;
        vector<int>values(n,0);
        vector<int>t(n,-1);
        for(int num:nums) values[num]+=num;  //store  all the values of the particular num

        int ans=solve(values,n-1,t);
        return ans;
    }

//DP method
int deleteAndEarn(vector<int>& nums) {
         int n=10001;
        vector<int>values(n,0);
        vector<int>dp(n,0);
        for(int num:nums) values[num]+=num;  //store  all the values of the particular num
         
     dp[0]=values[0];
dp[1]=max(values[0],values[1]);
 for(int i=2;i<n;i++){
     int incl=dp[i-2]+values[i];
     int excl=dp[i-1]+0;
     dp[i]=max(incl,excl);
 }
return dp[n-1];
 }

//DP(Constant Space)
int deleteAndEarn(vector<int>& nums) {
         int n=10001;
        vector<int>values(n,0);
        for(int num:nums) values[num]+=num;  //store  all the values of the particular num
        if(nums.size()==1) return nums[0];

        int prev_prev=values[0];
        int prev=max(values[0],values[1]);

        for(int i=2;i<n;i++){
         int incl=prev_prev+values[i];
         int excl=prev+0;
         int temp=max(incl,excl);
         
         prev_prev=prev;
         prev=temp;
        }
         return prev;
     }
};
