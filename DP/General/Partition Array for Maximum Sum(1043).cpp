class Solution {
public:
//Recursive method
int n;
int solve(int i,vector<int>& arr, int k){
    BASE CASE
    if(i >= arr.size()) return 0;
    int curr_max = INT_MIN;
    int res = INT_MIN;

    for(int j = i; j < min(i + k,n); j++){
       curr_max = max(arr[j], curr_max);
        int res = max(res, ((j-i+1) * curr_max) + solve(j + 1, arr, k)); // Current subarray = arr[i to j] 
    }
    return res;
}
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        return solve(0,arr,k);
    }

//Memoization
    int n;
    int t[501];
    int solve(vector<int>& arr, int i, int k) {
        if(i >= n)  return 0;
        
        
        if(t[i] != -1)  return t[i];
        
        int res = INT_MIN;
        int curr_max = INT_MIN;

        for(int j = i; j < min(i + k, n); j++) {
            curr_max = max(curr_max, arr[j]);
            
            res = max(res, curr_max * (j - i + 1) + solve(arr, j + 1, k));
        }
        
        return t[i] = res;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        memset(t, -1, sizeof(t));
        return solve(arr, 0, k);
    }

//DP
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
       int n = arr.size(); 

        vector<int>dp(n + 1,0);
        
        for(int size = n - 1; size >= 0; size--){
            int curr_max = INT_MIN;

            for(int j = size; j < min(size + k, n); j++){
                curr_max = max(curr_max, arr[j]);
                dp[size] = max(dp[size], curr_max * (j - size + 1) + dp[j + 1]);
            }
        }
        return dp[0];
    }
};
