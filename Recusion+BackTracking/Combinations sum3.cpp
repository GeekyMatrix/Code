class Solution {
public:
 void solve(int index,int n,int k,vector<vector<int>>&ans,vector<int>output){
     //BASE CASE
     if(k==0 && n==0){ 
         ans.push_back(output);
         return;
     }
       if(k==0) return;
             
      for(int i=index;i<=9;i++){
       if(i>n) break;

       output.push_back(i);
       solve(i+1,n-i,k-1,ans,output);
       //BACKTRACK
       output.pop_back();
      }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
         vector<vector<int>>ans;
        vector<int>output;
        solve(1,n,k,ans,output);
        return ans;
    }
};
