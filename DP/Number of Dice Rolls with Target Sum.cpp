class Solution {
public:
  int MOD=1e9+7;
//Recursive method
int solve(int dice,int faces,int target){
  //Base case 
  if(target<0) return 0;
  if(dice==0 && target!=0) return 0;
  if(dice!=0 && target==0) return 0;
  if(dice==0 && target==0) return 1;
  
  int ans=0;
  for(int i=1;i<=faces;i++) ans+=(solve(dice-1,faces,target-i))%MOD;
  ans=ans%MOD;
  return ans;
}
    int numRollsToTarget(int n, int k, int target) {
        return solve(n,k,target);
    }

//Memoization method
int solve(int dice,int faces,int target, vector<vector<int>>&t){
  //Base case 
  if(target<0) return 0;
  if(dice==0 && target!=0) return 0;
  if(dice!=0 && target==0) return 0;
  if(dice==0 && target==0) return 1;
  
  if(t[dice][target]!=-1) return t[dice][target];
  long long ans=0;
  for(int i=1;i<=faces;i++) ans+=solve(dice-1,faces,target-i,t);
  ans = ans%MOD;
  return t[dice][target]=ans;
}
    int numRollsToTarget(int n, int k, int target) {
      vector<vector<int>>t(n+1,vector<int>(target+1,-1));
        return solve(n,k,target,t);
    }

//DP Method
 int numRollsToTarget(int n, int k, int target) {
      vector<vector<int>>dp(n+1,vector<int>(target+1,0));
        dp[0][0]=1;

        for(int dice=1;dice<=n;dice++){
          for(int tar=1;tar<=target;tar++){
              long long ans=0;

         for(int i=1;i<=k;i++) {
           if(tar-i>=0)   ans+=dp[dice-1][tar-i];
         }
          ans = ans%MOD;
            dp[dice][tar]=ans;
          }
        }
       return dp[n][target];
    }

//DP with Space optimisation
 int numRollsToTarget(int n, int k, int target) {
  vector<int>prev(target+1,0);
   vector<int>curr(target+1,0);

        prev[0]=1;

        for(int dice=1;dice<=n;dice++){
          for(int tar=1;tar<=target;tar++){
              long long ans=0;

         for(int i=1;i<=k;i++) {
           if(tar-i>=0)   ans+=prev[tar-i];
         }
          ans = ans%MOD;
            curr[tar]=ans;
          }
          prev=curr;
        }
       return prev[target];
    }
};
