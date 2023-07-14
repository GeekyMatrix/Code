class Solution {
public:
//T.C=O(N^2) S.C=O(N) THIS GIVES US TLE

    int longestSubsequence(vector<int>& arr, int difference) {
        int n=arr.size();
        vector<int>dp(n,1);
          int maxL=1;

        for(int i=1;i<n;i++){
          int temp=arr[i]-difference;
          for(int j=0;j<i;j++){
            if(temp==arr[j]) {
                 dp[i]=max(dp[i],1+dp[j]);
                 maxL=max(maxL,dp[i]);
            }
          }
        }
        return maxL;
    }

//T.C=O(N) S.C =O(N)
int longestSubsequence(vector<int>& arr, int difference) {
  unordered_map<int,int>dp;
  int ans=0;
  
  for(int i=0;i<arr.size();i++){
  int temp=arr[i]-difference;
  int tempAns=0;
 //check answer exist for temp already or not
 if(dp.count(temp)) tempAns=dp[temp];

 //current answer update
 dp[arr[i]]=1+tempAns;
 
 //ans ko update kardo
 ans=max(ans,dp[arr[i]]);
  }
 return ans;
}
};
