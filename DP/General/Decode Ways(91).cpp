class Solution {
public:
//Recursion
int solve(string s , int idx){
    if(idx == s.size()) return 1;
    
    int res = 0;
    if(s[idx]!= '0') res +=solve(s, idx + 1); //for single character

if(idx + 1 < s.size() && (s[idx] == '1' || s[idx] == '2' && s[idx + 1] <= '6')) res +=solve(s,idx +2);
     
     return res;
}
    int numDecodings(string s) {
        return solve(s, 0);
    }

//Memoization 
int t[101];
int solve(string s , int idx){
    if(idx == s.size()) return t[idx] = 1;
    if(t[idx]!=-1) return t[idx];

    int res = 0;
    if(s[idx]!= '0') res +=solve(s, idx + 1); //for single character

 if(idx + 1 < s.size() && (s[idx] == '1' || s[idx] == '2' && s[idx + 1] <= '6')) res +=solve(s,idx +2);
     
     return t[idx] = res;
}
    int numDecodings(string s) {
         memset(t, -1 ,sizeof(t));
        return solve(s, 0);
    }

//DP
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        int n = s.length();
        vector<int>dp(n + 1,0);
        dp[0] = 1;
        dp[1] = s[0] != '0' ? 1 : 0; // Initialize dp[1] based on the first character
        
       for(int idx = 2; idx <= n; idx++){

    if(s[idx - 1]!= '0') dp[idx] += dp[idx - 1]; //for single character

    if(s[idx - 2] == '1' || s[idx - 2] == '2' && s[idx - 1] <= '6') dp[idx] += dp[idx - 2];
     
       }
        return dp[n];
    }
};
