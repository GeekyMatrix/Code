class Solution {
public:
//Recursive method
int n;
int solve(int idx,vector<int>& arr, int k){
    BASE CASE
    if(idx==arr.size()) return 0;
    int len=0;
    int maxi=INT_MIN;
    int maxAns=INT_MIN;

    for(int j=idx; j<min(idx+k,n); j++){
        len++;
        maxi=max(arr[j],maxi);
        int sum=(len*maxi)+solve(j+1,arr,k);
        maxAns=max(maxAns,sum);
    }
    return maxAns;
}
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n=arr.size();
        return solve(0,arr,k);
    }

//Memoization
int n;
int solve(int idx,vector<int>& arr, int k,vector<int>&t){
    //BASE CASE
    if(idx==arr.size()) return 0;

    if(t[idx]!=-1) return t[idx];
    int len=0;
    int maxi=INT_MIN;
    int maxAns=INT_MIN;
    
    for(int j=idx; j<min(idx+k,n); j++){
        len++;
        maxi=max(arr[j],maxi);
        int sum=(len*maxi)+solve(j+1,arr,k,t);
        maxAns=max(maxAns,sum);
    }
    return t[idx]=maxAns;
}
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n=arr.size();
        vector<int>t(n,-1);
        return solve(0,arr,k,t);
    }
};
