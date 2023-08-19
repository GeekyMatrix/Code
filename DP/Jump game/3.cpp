class Solution {
public:
//Recursion 
    bool solve(vector<int>& arr,int i,vector<bool>& vis){
       
        if(i>=arr.size() || i<0 || vis[i]==true)return false;
        if(arr[i]==0)return true;
        vis[i]=true;
        bool forward = solve(arr,i+arr[i],vis);
        bool backward = solve(arr,i-arr[i],vis);
        return forward || backward;
    }
    bool canReach(vector<int>& arr, int start) {
        vector<bool> vis(arr.size(),false);
        return solve(arr,start,vis);
    }

//Memoization
    bool solve(vector<int>& arr,int i,vector<bool>& vis,  vector<int>&t){
       
        if(i>=arr.size() || i<0 || vis[i]==true)return false;
        if(arr[i]==0)return true;
        vis[i]=true;
        if(t[i]!=-1) return t[i];

        bool forward = solve(arr,i+arr[i],vis,t);
        bool backward = solve(arr,i-arr[i],vis,t);
        return t[i]=forward || backward;
    }
    bool canReach(vector<int>& arr, int start) {
        vector<int>t(arr.size(),-1);
        vector<bool> vis(arr.size(),false);
        return solve(arr,start,vis,t);
    }
};
