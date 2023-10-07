class Solution {
public:
//Recursive
int n;
long long solve(int idx , vector<vector<int>>& questions){
    //BASE CASE
if(idx >= n) return 0;
long long take = questions[idx][0] + solve(idx + questions[idx][1] + 1 , questions);
long long notTake = 0 + solve(idx + 1, questions);

return max(take , notTake);
}
    long long mostPoints(vector<vector<int>>& questions) {
        n = questions.size();
         return solve(0,questions);
    }

//Memoization
int n;
int t[100001];
long long solve(int idx , vector<vector<int>>& questions){
    //BASE CASE
if(idx >= n) return 0;
if(t[idx]!=-1) return t[idx];

long long take = questions[idx][0] + solve(idx + questions[idx][1] + 1 , questions);
long long notTake = 0 + solve(idx + 1, questions);

return t[idx] = max(take , notTake);
}
    long long mostPoints(vector<vector<int>>& questions) {
        n = questions.size();
        memset(t,-1,sizeof(t));
         return solve(0,questions);
    }

//DP
long long mostPoints(vector<vector<int>>& questions) {
int n = questions.size();
if(n == 1) return  questions[0][0];
vector<long long>dp(200001,0);

for(int i = n-1; i>=0; i--){
    long long take = questions[i][0] + dp[i + questions[i][1] + 1];
    long long notTake = dp[i + 1];
    dp[i] = max(take , notTake);
}
 return dp[0];
}
};
