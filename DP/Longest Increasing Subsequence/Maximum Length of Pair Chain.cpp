class Solution {
public:
//DP METHOD (LIS APPROACH)

//TC=O(n^2) SC=O(n)
    int findLongestChain(vector<vector<int>>& pairs) {
        int maxi=0;
        int n=pairs.size();
        if(n==1) return 1;
        vector<int>dp(n,1);

        vector<pair<int,int>>p;
        for(int i=0;i<n;i++) p.push_back({pairs[i][0],pairs[i][1]});
        sort(p.begin(),p.end());

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(p[j].second<p[i].first) dp[i]=max(dp[i],dp[j]+1);
                 maxi=max(maxi,dp[i]);
            }
        }
         return maxi;
    }

// Greedy approach
  //TC=O(n) SC=O(n)
 static bool comp(pair<int,int>a,pair<int,int>b){
   return a.second<b.second;
  }

   int findLongestChain(vector<vector<int>>& pairs) {
       int n=pairs.size();
        vector<pair<int,int>>p;
        for(int i=0;i<n;i++) p.push_back({pairs[i][0],pairs[i][1]});
        sort(p.begin(),p.end(),comp);  //sort krlia second ke respect mai

  int size=p.size();
 int i=0,j=1,count=1;
  while(j<size){
      if(p[i].second<p[j].first) {
          count++;
          i=j;
          j++;
      }
      else j++;
  }
      return count;
   }
};
