class Solution {
public:
// RECURSION METHOD (BUT IT GIVES TLE)
  int helper(int i,string s,set<string>wordDict){
      if(i==s.size()) return 1;
      string temp;
      for(int j=i;j<s.size();j++){
          temp+=s[j];
          if(wordDict.find(temp)!=wordDict.end()){
              if(helper(j+1,s,wordDict)) return 1;
          }
      }
      return 0;
  }

    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>st;
        for(auto x:wordDict) st.insert(x);
        return helper(0,s,st);
    }

//MEMOIZATION METHOD
int t[301];
int helper(int i,string s,set<string>wordDict){
      if(i==s.size()) return 1;
      string temp;
      if(t[i]!=-1) return t[i];
      for(int j=i;j<s.size();j++){
          temp+=s[j];
          if(wordDict.find(temp)!=wordDict.end()){
              if(helper(j+1,s,wordDict)) return t[i]=1;
          }
      }
      return t[i]=0;
  }

    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>st;
        memset(t,-1,sizeof t);
        for(auto x:wordDict) st.insert(x);
        return helper(0,s,st);
    }

//DP METHOD
bool wordBreak(string s, vector<string>& wordDict) {
    int n=s.size();
      vector<int>dp(n+1,0);
     dp[n] =1;
    set<string>st;
     for(auto x:wordDict) st.insert(x);
     
  for(int i=n-1;i>=0;i--){
   string temp;
    for(int j=i;j<n;j++){
   temp+=s[j];
     if(st.find(temp)!=st.end() && dp[j+1]==1)  dp[i]= 1; 
    }
    }
  return dp[0];
 }
};
